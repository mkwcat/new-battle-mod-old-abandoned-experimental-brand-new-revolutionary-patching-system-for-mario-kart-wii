#include "KartObjectManager.h"

namespace Kart
{

EXTERN_DATA(
  0x809C18F8, //
  KartObjectManager* KartObjectManager::s_instance
);

EXTERN_TEXT(
  0x80590100, //
  KartObject* KartObjectManager::GetObject(u32 playerId)
);

} // namespace Kart
