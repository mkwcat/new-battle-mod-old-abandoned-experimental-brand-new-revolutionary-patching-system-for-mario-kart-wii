// ItemObjPowBlock.cpp
// MKW: 0x807B1AB0 - 0x807B1BC0

#include "ItemObjPowBlock.h"

namespace Item
{

// 0x808A5F88
const ItemTypeEntry ItemObjPowBlock::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_POW_BLOCK,
  .m_objCount = 1,
  .m_0x0C = 1,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjPowBlock::UseHandler,
};

EXTERN_DATA(
  0x808D24B8, //
  ItemObjConfig ItemObjPowBlock::s_itemObjConfig
);

EXTERN_TEXT(
  0x807B1B2C, //
  void ItemObjPowBlock::UseHandler(ItemKartProxy* kart)
);

} // namespace Item
