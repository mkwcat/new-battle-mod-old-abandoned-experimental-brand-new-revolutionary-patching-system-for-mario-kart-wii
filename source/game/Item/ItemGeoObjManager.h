#pragma once

#include "ItemType.h"

namespace Item
{

class ItemGeoObjManager
{
public:
    ItemGeoObjManager() = default;
    ~ItemGeoObjManager() = default;

    void Create_ItemObj(EItemGeoObjType type, u32* outCount);

    void Init();

    /* 0x80796470 */
    void CalcBeforeKart();

    /* 0x80796B30 */
    void CalcAfterKart();

    /* 0x807974AC */
    u32 GetNumInUse();

private:
    FILL(0x00, 0x10);

public:
    /* 0x10 */ u32 m_objCount;
    /* 0x14 */ u32 m_0x14;

private:
    FILL(0x18, 0x24);
};

static_assert(sizeof(ItemGeoObjManager) == 0x24);

} // namespace Item
