// ItemObjThunder.cpp
// MKW: 0x807B7B00 - 0x807B7D9C

#include "ItemObjThunder.h"

namespace Item
{

// 0x808A6254
const ItemTypeEntry ItemObjThunder::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_THUNDER,
  .m_objCount = 1,
  .m_0x0C = 2,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjThunder::UseHandler,
};

EXTERN_DATA(
  0x808D26F8, //
  ItemObjConfig ItemObjThunder::s_itemObjConfig
);

EXTERN_TEXT(
  0x807B7B7C, //
  void ItemObjThunder::UseHandler(ItemKartProxy* kart)
);

} // namespace Item
