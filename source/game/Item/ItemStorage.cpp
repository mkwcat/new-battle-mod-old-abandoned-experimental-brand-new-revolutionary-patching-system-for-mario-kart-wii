// ItemStock.cpp
// MKW: 0x807BC0F8 - 0x807BCAE0

#include "ItemStock.h"
#include "ItemKartProxy.h"

namespace Item
{

EXTERN_TEXT(
  0x807BC940, //
  void ItemStock::Set(EItemType item, bool isMultiItem)
);

EXTERN_TEXT(
  0x807BC97C, //
  void ItemStock::Remove(u32 count)
);

EXTERN_TEXT(
  0x807BC9C0, //
  void ItemStock::Clear()
);

} // namespace Item
