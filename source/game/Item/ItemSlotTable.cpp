// ItemSlotTable.cpp
// MKW: 0x807BA650 - 0x807BC0F8

#include "ItemSlotTable.h"

namespace Item
{

EXTERN_DATA(
  0x809C3670, //
  ItemSlotTable* ItemSlotTable::s_instance
);

EXTERN_TEXT(
  0x807BA77C, //
  void ItemSlotTable::CreateInstance()
);

EXTERN_TEXT(
  0x807BA814, //
  void ItemSlotTable::DestroyInstance()
);

EXTERN_TEXT(
  0x807BB9EC, //
  void ItemSlotTable::Calc()
);

} // namespace Item
