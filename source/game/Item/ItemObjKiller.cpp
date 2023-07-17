// ItemObjKiller.cpp
// MKW: 0x807A9A80 - 0x807A9CC0

#include "ItemObjKiller.h"
#include "ItemKartProxy.h"

namespace Item
{

// 0x808A58F4
const ItemTypeEntry ItemObjKiller::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KILLER,
  .m_objCount = 1,
  .m_0x0C = 2,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjKiller::UseHandler,
};

EXTERN_DATA(
  0x808D1E88, //
  ItemObjConfig ItemObjKiller::s_itemObjConfig
);

EXTERN_TEXT(
  0x807A9AFC, //
  void ItemObjKiller::UseHandler(ItemKartProxy* kart)
);

} // namespace Item
