// ItemObjBomhei.cpp
// MKW: 0x807A41C4 - 0x807A6328

#include "ItemObjBomhei.h"

namespace Item
{

// 0x808A5468
const ItemTypeEntry ItemObjBomhei::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_BOMHEI,
  .m_objCount = 1,
  .m_0x0C = 1,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_HOLD,
  .m_useHandler = nullptr,
};

EXTERN_DATA(
  0x808A5484, //
  ItemObjConfig ItemObjBomhei::s_itemObjConfig
);

} // namespace Item
