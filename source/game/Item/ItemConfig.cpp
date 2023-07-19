// ItemConfig.cpp
// MKW: 0x80790AD8 - 0x8079126C

#include "ItemConfig.h"
#include "ItemObjBanana.h"
#include "ItemObjBomhei.h"
#include "ItemObjDummyBox.h"
#include "ItemObjFeather.h"
#include "ItemObjGesso.h"
#include "ItemObjKiller.h"
#include "ItemObjKinoko.h"
#include "ItemObjKinokoBig.h"
#include "ItemObjKinokoGolden.h"
#include "ItemObjKoura.h"
#include "ItemObjKouraBlue.h"
#include "ItemObjKouraGreen.h"
#include "ItemObjKumo.h"
#include "ItemObjPowBlock.h"
#include "ItemObjStar.h"
#include "ItemObjThunder.h"
#include <Race/Field/DriverModelManager.h>
#include <Race/ModeInfo.h>
#include <string.h>

namespace Item
{

REPLACE_DATA(
  0x809C2F48, 0x6CC, //
  ItemObjConfig g_itemObjConfigTable[ITEM_GEO_OBJ_EXP_END]
);

u32 GetGeoObjCount();
void SetItemObjConfig(ItemObjConfig* dst, const ItemObjConfig* src);

EXTERN_TEXT(
  0x80790AD8, //
  void ItemObjConfig::InitGlobal()
);

REPLACE(
  0x80790AFC, //
  void InitGeoObjConfig()
)
{
    memset(g_itemObjConfigTable, 0, sizeof(g_itemObjConfigTable));

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_KOURA_GREEN], //
      &ItemObjKouraGreen::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_KOURA_RED], //
      &ItemObjKoura::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_BANANA], //
      &ItemObjBanana::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_KINOKO], //
      &ItemObjKinoko::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_STAR], //
      &ItemObjStar::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_KOURA_BLUE], //
      &ItemObjKouraBlue::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_THUNDER], //
      &ItemObjThunder::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_DUMMY_BOX], //
      &ItemObjDummyBox::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_KINOKO_BIG], //
      &ItemObjKinokoBig::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_BOMHEI], //
      &ItemObjBomhei::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_GESSO], //
      &ItemObjGesso::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_POW_BLOCK], //
      &ItemObjPowBlock::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_KINOKO_GOLDEN], //
      &ItemObjKinokoGolden::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_KILLER], //
      &ItemObjKiller::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_KUMO], //
      &ItemObjKumo::s_itemObjConfig
    );

    SetItemObjConfig(
      &g_itemObjConfigTable[ITEM_GEO_OBJ_FEATHER], //
      &ItemObjFeather::s_itemObjConfig
    );

    for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
        if (!IsValid_eItemGeoObjType(eItemGeoObjType(i))) {
            continue;
        }

        if (g_itemObjConfigTable[i].m_0x24 != nullptr) {
            g_itemObjConfigTable[i].m_0x28 =
              g_itemObjConfigTable[i].m_0x24(0, 0, 1);
        } else {
            g_itemObjConfigTable[i].m_0x28 = 0;
        }
    }

    if (Race::ModeInfo::s_modeInfo.m_isTimeAttack) {
        for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
            if (IsValid_eItemGeoObjType(eItemGeoObjType(i))) {
                g_itemObjConfigTable[i].m_canLand = 0;
            }
        }
    }

    if (Race::DriverModelManager::s_instance->m_isAwards) {
        for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
            if (IsValid_eItemGeoObjType(eItemGeoObjType(i))) {
                g_itemObjConfigTable[i].m_count = 1;
            }
        }
    }

    // Normal behavior searches for geo obj sanbo_big here and increases the
    // size of the green shell if it exists.
    // https://tcrf.net/Mario_Kart_Wii/Unused_Code_%26_Parameters#Double-Sized_Green_Shells

    if (Race::ModeInfo::UseCompetitionItemLimits()) {
        for (u32 i = 0; i < ITEM_GEO_OBJ_EXP_END; i++) {
            if (IsValid_eItemGeoObjType(eItemGeoObjType(i))) {
                g_itemObjConfigTable[i].m_count =
                  g_itemObjConfigTable[i].m_competitionCount;
            }
        }
    }
}

EXTERN_TEXT(
  0x80790E3C, //
  u32 GetGeoObjCount()
);

EXTERN_TEXT(
  0x80790E7C, //
  void SetItemObjConfig(ItemObjConfig* dst, const ItemObjConfig* src)
);

} // namespace Item
