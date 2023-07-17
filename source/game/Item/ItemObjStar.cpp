// ItemObjStar.cpp
// MKW: 0x807B6FF0 - 0x807B7104

#include "ItemObjStar.h"

namespace Item
{

// 0x808A61A4
const ItemTypeEntry ItemObjStar::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_STAR,
  .m_objCount = 1,
  .m_0x0C = 2,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjStar::UseHandler,
};

EXTERN_TEXT(
  0x807B706C, //
  void ItemObjStar::UseHandler(ItemKartProxy* kart)
);

EXTERN_DATA(
  0x808D2620, //
  ItemObjConfig ItemObjStar::s_itemObjConfig
);

} // namespace Item
