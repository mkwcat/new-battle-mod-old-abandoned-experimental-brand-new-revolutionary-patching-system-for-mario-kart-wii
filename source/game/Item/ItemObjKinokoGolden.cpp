// ItemObjKinokoGolden.cpp
// MKW: 0x807A9EE8 - 0x807A9FF0

#include "ItemObjKinokoGolden.h"
#include "ItemKartProxy.h"

namespace Item
{

// 0x808A59C4
const ItemTypeEntry ItemObjKinokoGolden::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KINOKO_GOLDEN,
  .m_objCount = 1,
  .m_0x0C = 2,
  .m_0x10 = 1,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjKinokoGolden::UseHandler,
};

EXTERN_DATA(
  0x808D2098, //
  ItemObjConfig ItemObjKinokoGolden::s_itemObjConfig
);

EXTERN_TEXT(
  0x807A9F64, //
  void ItemObjKinokoGolden::UseHandler(ItemKartProxy* kart)
);

} // namespace Item
