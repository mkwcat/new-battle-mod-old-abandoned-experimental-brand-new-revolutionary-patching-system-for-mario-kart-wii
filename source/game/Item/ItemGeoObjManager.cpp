// ItemGeoObjManager.cpp
// MKW: 0x80795CC8 - 0x8079754C

#include "ItemGeoObjManager.h"

namespace Item
{

// 0x80795CC8: ItemGeoObjManager constructor (deleted)

EXTERN_TEXT(
  0x80795CCC, //
  void ItemGeoObjManager::CreateItemObj(eItemGeoObjType type, u32* outCount)
);

EXTERN_TEXT(
  0x80795D94, //
  void ItemGeoObjManager::Init()
);

EXTERN_TEXT(
  0x80796470, //
  void ItemGeoObjManager::CalcBeforeKart()
);

EXTERN_TEXT(
  0x80796B30, //
  void ItemGeoObjManager::CalcAfterKart()
);

EXTERN_TEXT(
  0x807974AC, //
  u32 ItemGeoObjManager::GetNumInUse()
);

} // namespace Item
