// ItemObjKouraBlue.cpp
// MKW: 0x807AB9E0 - 0x807AEAEC

#include "ItemObjKouraBlue.h"

namespace Item
{

// 0x808A5B18
const ItemTypeEntry ItemObjKouraBlue::s_itemType = {
  .m_0x00 = true,
  .m_0x01 = true,
  .m_objType = ITEM_GEO_OBJ_KOURA_BLUE,
  .m_objCount = 1,
  .m_0x0C = 2,
  .m_0x10 = 0,
  .m_trailType = ITEM_TRAIL_HOLD,
  // Removing use handler allows dragging blue shells
  .m_useHandler = nullptr,
};

EXTERN_DATA(
  0x808A5B34, //
  ItemObjConfig ItemObjKouraBlue::s_itemObjConfig
);

} // namespace Item
