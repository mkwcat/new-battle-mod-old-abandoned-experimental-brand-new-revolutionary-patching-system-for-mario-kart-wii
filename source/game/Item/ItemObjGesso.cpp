// ItemObjGesso.cpp
// MKW: 0x807A8138 - 0x807A8394

#include "ItemObjGesso.h"
#include "ItemKartProxy.h"

namespace Item
{

// 0x808A587C
const ItemTypeEntry ItemObjGesso::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_GESSO,
  .m_objCount = 1,
  .m_0x0C = 1,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjGesso::UseHandler,
};

EXTERN_DATA(
  0x808D1DD0, //
  ItemObjConfig ItemObjGesso::s_itemObjConfig
);

EXTERN_TEXT(
  0x807A81B4, //
  void ItemObjGesso::UseHandler(ItemKartProxy* kart)
);

} // namespace Item
