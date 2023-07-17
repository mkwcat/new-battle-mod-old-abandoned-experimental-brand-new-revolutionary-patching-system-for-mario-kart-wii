// ItemObjKinokoBig.cpp
// MKW: 0x807A9DD4 - 0x807A9EE8

#include "ItemObjKinokoBig.h"
#include "ItemKartProxy.h"

namespace Item
{

// 0x808A598C
const ItemTypeEntry ItemObjKinokoBig::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KINOKO_BIG,
  .m_objCount = 1,
  .m_0x0C = 2,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjKinokoBig::UseHandler,
};

EXTERN_DATA(
  0x808D1FE8, //
  ItemObjConfig ItemObjKinokoBig::s_itemObjConfig
);

EXTERN_TEXT(
  0x807A9E50, //
  void ItemObjKinokoBig::UseHandler(ItemKartProxy* kart)
);

} // namespace Item
