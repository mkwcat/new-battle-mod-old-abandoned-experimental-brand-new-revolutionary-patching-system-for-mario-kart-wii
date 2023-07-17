// ItemObjKumo.cpp
// MKW: 0x807AF140 - 0x807B1AB0

#include "ItemObjKumo.h"

namespace Item
{

// 0x808A5DF8
const ItemTypeEntry ItemObjKumo::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KUMO,
  .m_objCount = 1,
  .m_0x0C = 1,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjKumo::UseHandler,
};

EXTERN_DATA(
  0x808A5E14, //
  ItemObjConfig ItemObjKumo::s_itemObjConfig
);

EXTERN_TEXT(
  0x807AF1BC, //
  void ItemObjKumo::UseHandler(ItemKartProxy* kart)
);

} // namespace Item
