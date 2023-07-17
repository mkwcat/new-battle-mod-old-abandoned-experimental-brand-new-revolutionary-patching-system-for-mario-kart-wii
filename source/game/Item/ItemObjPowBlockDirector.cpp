// ItemObjPowBlockDirector.cpp
// MKW: 0x807B1BC0 - 0x807B2EF8

#include "ItemObjPowBlockDirector.h"

namespace Item
{

EXTERN_DATA(
  0x809C3660, //
  ItemObjPowBlockDirector* ItemObjPowBlockDirector::s_instance
);

EXTERN_TEXT(
  0x807B1BC0, //
  void ItemObjPowBlockDirector::CreateInstance()
);

EXTERN_TEXT(
  0x807B1C70, //
  void ItemObjPowBlockDirector::DestroyInstance()
);

EXTERN_TEXT(
  0x807B1CA8, //
  void ItemObjPowBlockDirector::Init()
);

EXTERN_TEXT(
  0x807B22F8, //
  void ItemObjPowBlockDirector::Calc()
);

} // namespace Item
