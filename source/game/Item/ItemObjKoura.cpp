// ItemObjKoura.cpp
// MKW: 0x807A9FF0 - 0x807AB9E0

#include "ItemObjKoura.h"

namespace Item
{

// 0x808A5A00
const ItemTypeEntry ItemObjKoura::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KOURA_RED,
  .m_objCount = 1,
  .m_0x0C = 1,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_HOLD,
  .m_useHandler = nullptr,
};

// 0x808A5A1C
const ItemTypeEntry ItemObjKoura::s_itemType3 = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KOURA_RED,
  .m_objCount = 3,
  .m_0x0C = 2,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_CIRCLE,
  .m_useHandler = nullptr,
};

EXTERN_DATA(
  0x808A5A38, //
  ItemObjConfig ItemObjKoura::s_itemObjConfig
);

} // namespace Item
