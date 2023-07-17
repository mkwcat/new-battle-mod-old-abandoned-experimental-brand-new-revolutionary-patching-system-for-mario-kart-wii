// ItemObjBanana.cpp
// MKW: 0x807A3A24 - 0x807A41C4

#include "ItemObjBanana.h"

namespace Item
{

// 0x808A5350
const ItemTypeEntry ItemObjBanana::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_BANANA,
  .m_objCount = 1,
  .m_0x0C = 0,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_HOLD,
  .m_useHandler = nullptr,
};

// 0x808A536C
const ItemTypeEntry ItemObjBanana::s_itemType3 = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_BANANA,
  .m_objCount = 3,
  .m_0x0C = 2,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_CIRCLE,
  .m_useHandler = nullptr,
};

EXTERN_DATA(
  0x808A5388, //
  ItemObjConfig ItemObjBanana::s_itemObjConfig
);

} // namespace Item
