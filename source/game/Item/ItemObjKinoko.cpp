// ItemObjKinoko.cpp
// MKW: 0x807A9CC0 - 0x807A9DD4

#include "ItemObjKinoko.h"
#include "ItemKartProxy.h"

namespace Item
{

// 0x808A593C
const ItemTypeEntry ItemObjKinoko::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KINOKO,
  .m_objCount = 1,
  .m_0x0C = 0,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjKinoko::UseHandler,
};

// 0x808A5958
const ItemTypeEntry ItemObjKinoko::s_itemType3 = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KINOKO,
  .m_objCount = 3,
  .m_0x0C = 1,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_NONE,
  .m_useHandler = ItemObjKinoko::UseHandler,
};

EXTERN_DATA(
  0x808D1F38, //
  ItemObjConfig ItemObjKinoko::s_itemObjConfig
);

EXTERN_TEXT(
  0x807A9D3C, //
  void ItemObjKinoko::UseHandler(ItemKartProxy* kart)
);

} // namespace Item
