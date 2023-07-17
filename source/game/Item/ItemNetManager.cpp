// ItemNetManager.cpp
// MKW: 0x8079A778 - 0x8079D804

#include "ItemNetManager.h"

namespace Item
{

EXTERN_DATA(
  0x809C3620, //
  ItemNetManager* ItemNetManager::s_instance
);

EXTERN_TEXT(
  0x8079A8A4, //
  void ItemNetManager::CreateInstance()
);

EXTERN_TEXT(
  0x8079AB68, //
  void ItemNetManager::DestroyInstance()
);

EXTERN_TEXT(
  0x8079BD94, //
  void ItemNetManager::CalcBefore()
);

EXTERN_TEXT(
  0x8079BED0, //
  void ItemNetManager::CalcAfter()
);

} // namespace Item
