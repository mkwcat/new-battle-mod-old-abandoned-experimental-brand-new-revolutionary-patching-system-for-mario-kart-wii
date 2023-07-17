// ItemType.cpp
// MKW: 0x807BCAE0 - 0x807BD1D0

#include "ItemType.h"
#include "ItemObjBanana.h"
#include "ItemObjBomhei.h"
#include "ItemObjDummyBox.h"
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
#include <Race/ModeInfo.h>
#include <string.h>

namespace Item
{

REPLACE_DATA(
  0x809C36A0, 0x214, //
  ItemTypeEntry g_itemTypeTable[ITEM_EXP_END]
);

REPLACE(
  0x807BCAE0, //
  void InitItemTypeTable()
)
{
    memset(g_itemTypeTable, 0, sizeof(g_itemTypeTable));

    g_itemTypeTable[ITEM_KOURA_GREEN] = ItemObjKouraGreen::s_itemType;
    g_itemTypeTable[ITEM_KOURA_RED] = ItemObjKoura::s_itemType;
    g_itemTypeTable[ITEM_BANANA] = ItemObjBanana::s_itemType;
    g_itemTypeTable[ITEM_DUMMY_BOX] = ItemObjDummyBox::s_itemType;
    g_itemTypeTable[ITEM_KINOKO] = ItemObjKinoko::s_itemType;
    g_itemTypeTable[ITEM_KINOKO_3] = ItemObjKinoko::s_itemType3;
    g_itemTypeTable[ITEM_BOMHEI] = ItemObjBomhei::s_itemType;
    g_itemTypeTable[ITEM_KOURA_BLUE] = ItemObjKouraBlue::s_itemType;
    g_itemTypeTable[ITEM_THUNDER] = ItemObjThunder::s_itemType;
    g_itemTypeTable[ITEM_STAR] = ItemObjStar::s_itemType;
    g_itemTypeTable[ITEM_KINOKO_GOLDEN] = ItemObjKinokoGolden::s_itemType;
    g_itemTypeTable[ITEM_KINOKO_BIG] = ItemObjKinokoBig::s_itemType;
    g_itemTypeTable[ITEM_GESSO] = ItemObjGesso::s_itemType;
    g_itemTypeTable[ITEM_POW_BLOCK] = ItemObjPowBlock::s_itemType;
    g_itemTypeTable[ITEM_KUMO] = ItemObjKumo::s_itemType;
    g_itemTypeTable[ITEM_KILLER] = ItemObjKiller::s_itemType;
    g_itemTypeTable[ITEM_KOURA_GREEN_3] = ItemObjKouraGreen::s_itemType3;
    g_itemTypeTable[ITEM_KOURA_RED_3] = ItemObjKoura::s_itemType3;
    g_itemTypeTable[ITEM_BANANA_3] = ItemObjBanana::s_itemType3;
    g_itemTypeTable[ITEM_FEATHER] = ItemObjFeather::s_itemType;

    if (Race::ModeInfo::s_modeInfo.m_isOnline) {
        for (u32 i = 0; i < ITEM_EXP_END; i++) {
            if (i == ITEM_BASE_COUNT || i == ITEM_EMPTY) {
                continue;
            }

            if (g_itemTypeTable[i].m_0x00 && !g_itemTypeTable[i].m_0x01) {
                g_itemTypeTable[i].m_0x00 = false;
            }
        }
    }
}

} // namespace Item
