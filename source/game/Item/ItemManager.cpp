// ItemManager.cpp
// MKW: 0x80798F9C - 0x8079A778

#include "ItemManager.h"
#include "ItemNetManager.h"
#include "ItemObjGessoDirector.h"
#include "ItemObjPowBlockDirector.h"
#include "ItemPoint.h"
#include "ItemSlotTable.h"
#include "ItemType.h"
#include <Boot/DebugConfig.h>
#include <Race/ModeInfo.h>

namespace Item
{

EXTERN_DATA(
  0x809C3618, //
  ItemManager* ItemManager::s_instance
);

// 0x80798F9C: ItemManager destructor copy?

REPLACE(
  0x80799138, //
  ItemManager* ItemManager::CreateInstance()
)
{
    if (ItemManager::s_instance == nullptr) {
        ItemManager::s_instance = new ItemManager();
    }

    return ItemManager::s_instance;
}

REPLACE(
  0x80799188, //
  void ItemManager::DestroyInstance()
)
{
    if (ItemManager::s_instance != nullptr) {
        ItemManager* instance = ItemManager::s_instance;
        ItemManager::s_instance = nullptr;

        delete instance;
    }
}

REPLACE(
  0x807992D8, //
  ItemManager::ItemManager()
)
{
    m_kartCount = Race::ModeInfo::s_modeInfo.m_playerCount;
    m_expGeoObjCount = ITEM_GEO_OBJ_EXP_COUNT;

    InitItemTypeTable();
    ItemObjConfig::InitGlobal();

    ItemSlotTable::CreateInstance();

    ItemPoint::CreateItemPointMap();

    ItemObj::UNDEF_8079F8B4();

    if (Race::ModeInfo::s_modeInfo.m_isOnline) {
        ItemNetManager::CreateInstance();
    }

    u32 totalObjCount = 0;

    for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
        if (!IsValid_EItemGeoObjType(EItemGeoObjType(i))) {
            continue;
        }

        ItemGeoObjManager* item = GetGeoObjManager(EItemGeoObjType(i));

        if (item != nullptr) {
            item->Create_ItemObj(EItemGeoObjType(i), &totalObjCount);
        }
    }

    m_karts = new ItemKartProxy[m_kartCount];

    for (u8 i = 0; i < m_kartCount; i++) {
        m_karts[i].Init(i);
    }

    for (u8 i = 0; i < 12; i++) {
        m_netLocalPlayerLink[i] = nullptr;
    }

    if (Race::ModeInfo::s_modeInfo.m_isOnline) {
        u8 lastIdx = Race::MAX_PLAYER_COUNT;

        for (u8 i = 0; i < m_kartCount; i++) {
            if (!m_karts[i].m_isRemote && lastIdx != Race::MAX_PLAYER_COUNT) {
                m_netLocalPlayerLink[i] = &m_karts[lastIdx];
                m_netLocalPlayerLink[lastIdx] = &m_karts[i];
            }

            if (!m_karts[i].m_isRemote) {
                lastIdx = i;
            }
        }
    }

    ItemObjGessoDirector::CreateInstance();
    ItemObjPowBlockDirector::CreateInstance();

    m_bossChaseDummy.UNDEF_807A3618();

    m_0x42C = 0;
}

REPLACE(
  0x80799670, //
  ItemManager::~ItemManager()
)
{
    ItemSlotTable::DestroyInstance();

    if (Race::ModeInfo::s_modeInfo.m_isOnline) {
        ItemNetManager::DestroyInstance();
    }

    ItemObjGessoDirector::DestroyInstance();
    ItemObjPowBlockDirector::DestroyInstance();

    ItemManager::DestroyInstance();
}

REPLACE(
  0x80799794, //
  void ItemManager::Init()
)
{
    for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
        if (!IsValid_EItemGeoObjType(EItemGeoObjType(i))) {
            continue;
        }

        ItemGeoObjManager* item = GetGeoObjManager(EItemGeoObjType(i));

        if (item != nullptr) {
            item->Init();
        }
    }

    if (Race::ModeInfo::s_modeInfo.m_isTimeAttack) {
        for (u32 i = 0; i < Race::ModeInfo::s_modeInfo.m_playerCount; i++) {
            GetKart(i)->m_itemStock.Set(ITEM_KINOKO_3, false);
        }
    } else {
#ifdef DEBUG_START_ITEM
        GetKart(0)->m_itemStock.Set(DEBUG_START_ITEM, false);
#endif
    }

    InitMapGeo();

    ItemObjGessoDirector::Init();
    ItemObjPowBlockDirector::Init();
}

REPLACE(
  0x80799850, //
  void ItemManager::Calc()
)
{
    ItemSlotTable::Instance()->Calc();

    Race::ModeInfo::UpdateFrame();

    ItemObjGessoDirector::Instance()->Calc();
    ItemObjPowBlockDirector::Instance()->Calc();

    if (Race::ModeInfo::s_modeInfo.m_isOnline) {
        ItemNetManager::Instance()->CalcBefore();
        ItemNetManager::Instance()->CalcAfter();
    }

    for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
        if (!IsValid_EItemGeoObjType(EItemGeoObjType(i))) {
            continue;
        }

        ItemGeoObjManager* item = GetGeoObjManager(EItemGeoObjType(i));

        if (item == nullptr) {
            continue;
        }

        if (item->m_0x14 != 0) {
            item->CalcBeforeKart();
        }
    }

    u32 totalObj = 0;

    for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
        if (!IsValid_EItemGeoObjType(EItemGeoObjType(i))) {
            continue;
        }

        ItemGeoObjManager* item = GetGeoObjManager(EItemGeoObjType(i));

        if (item == nullptr) {
            continue;
        }

        totalObj += item->GetNumInUse() * g_itemObjConfigTable[i].m_0x5C;
    }

    m_0x42C = totalObj - 30;

    for (u8 i = 0; i < m_kartCount; i++) {
        m_karts[i].Calc();
    }

    for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
        if (!IsValid_EItemGeoObjType(EItemGeoObjType(i))) {
            continue;
        }

        ItemGeoObjManager* item = GetGeoObjManager(EItemGeoObjType(i));

        if (item == nullptr) {
            continue;
        }

        if (item->m_objCount != 0) {
            item->CalcAfterKart();
        }
    }
}

EXTERN_TEXT(
  0x80799E50, //
  void ItemManager::InitMapGeo()
);

} // namespace Item
