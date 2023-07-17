// ItemObjKouraGreen.cpp
// MKW: 0x807AEAEC - 0x807AF140

#include "ItemObjKouraGreen.h"

namespace Item
{

// 0x808A5D08
const ItemTypeEntry ItemObjKouraGreen::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KOURA_GREEN,
  .m_objCount = 1,
  .m_0x0C = 0,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_HOLD,
  .m_useHandler = nullptr,
};

// 0x808A5D24
const ItemTypeEntry ItemObjKouraGreen::s_itemType3 = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KOURA_GREEN,
  .m_objCount = 3,
  .m_0x0C = 1,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_CIRCLE,
  .m_useHandler = nullptr,
};

EXTERN_DATA(
  0x808A5D40, //
  ItemObjConfig ItemObjKouraGreen::s_itemObjConfig
);

} // namespace Item
