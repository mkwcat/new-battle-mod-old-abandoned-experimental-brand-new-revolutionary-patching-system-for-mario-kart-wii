// ItemObjGessoDirector.cpp
// MKW: 0x807A8394 - 0x807A9A80

#include "ItemObjGessoDirector.h"

namespace Item
{

EXTERN_DATA(
  0x809C3648, //
  ItemObjGessoDirector* ItemObjGessoDirector::s_instance
);

EXTERN_TEXT(
  0x807A8F04, //
  void ItemObjGessoDirector::CreateInstance()
);

EXTERN_TEXT(
  0x807A8FA0, //
  void ItemObjGessoDirector::DestroyInstance()
);

EXTERN_TEXT(
  0x807A8FD8, //
  void ItemObjGessoDirector::Init()
);

EXTERN_TEXT(
  0x807A92B0, //
  void ItemObjGessoDirector::Calc()
);

} // namespace Item
