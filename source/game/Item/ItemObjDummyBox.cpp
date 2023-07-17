// ItemObjDummyBox.cpp
// MKW: 0x807A78A8 - 0x807A8138

#include "ItemObjDummyBox.h"

namespace Item
{

// 0x808A56C8
const ItemTypeEntry ItemObjDummyBox::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_DUMMY_BOX,
  .m_objCount = 1,
  .m_0x0C = 1,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_HOLD,
  .m_useHandler = nullptr,
};

EXTERN_DATA(
  0x808A56E4, //
  ItemObjConfig ItemObjDummyBox::s_itemObjConfig
);

} // namespace Item
