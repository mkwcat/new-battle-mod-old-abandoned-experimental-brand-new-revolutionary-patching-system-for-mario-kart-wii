#pragma once

#include "ItemGeoObjManager.h"
#include "ItemKartProxy.h"
#include "ItemType.h"
#include <egg/core/eggDisposer.h>

namespace Item
{

class ItemObjCommon;

class ItemManager : public EGG::Disposer
{
private:
    /* 0x809C3618 */
    static ItemManager* s_instance;

public:
    static ItemManager* Instance()
    {
        return s_instance;
    }

    /* 0x80799138 */
    ItemManager* CreateInstance();

    /* 0x80799188 */
    void DestroyInstance();

    /* 0x807992D8 */
    ItemManager();

    /* 0x80799670 */
    ~ItemManager();

    /* 0x80799794 */
    void Init();

    /* 0x80799850 */
    void Calc();

    /* 0x80799E50 */
    void InitMapGeo();

    ItemKartProxy* GetKart(u8 index)
    {
        if (index >= m_kartCount) {
            return nullptr;
        }

        return m_karts + index;
    }

    ItemGeoObjManager* GetGeoObjManager(EItemGeoObjType item)
    {
        if (item < ITEM_GEO_OBJ_BASE_COUNT) {
            return &m_itemGeoObj[item];
        }

        if (item >= ITEM_GEO_OBJ_EXP_START && //
            item < ITEM_GEO_OBJ_EXP_END) {
            return &m_itemGeoObjExp[item - ITEM_GEO_OBJ_EXP_START];
        }

        return nullptr;
    }

private:
    /* 0x010 */ u8 m_kartCount;
    /* 0x014 */ ItemKartProxy* m_karts;
    /* 0x018 */ ItemKartProxy* m_netLocalPlayerLink[12];

    /* 0x048 */ ItemGeoObjManager m_itemGeoObj[15];

    /* 0x264 */ ItemObjCommon* m_0x264[16];
    /* 0x2A4 */ ItemObj m_bossChaseDummy;
    /* 0x42C */ u32 m_0x42C;
    // Normal class end

    FILL(0x430, 0x434);

public:
    /* 0x434 */ u32 m_expGeoObjCount;

    // Egregious hack: custom items start at ItemGeoObjType base 0x1C.
    // (0x048 + 0x1C * 0x24 = 0x438)
    /* 0x438 */ ItemGeoObjManager m_itemGeoObjExp[ITEM_GEO_OBJ_EXP_COUNT];
};

static_assert(offsetof(ItemManager, m_itemGeoObjExp) == 0x438);

} // namespace Item
