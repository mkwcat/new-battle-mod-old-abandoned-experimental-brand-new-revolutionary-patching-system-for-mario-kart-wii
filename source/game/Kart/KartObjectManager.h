#pragma once

#include "KartObject.h"

namespace Kart
{

class KartObjectManager
{
public:
    static KartObjectManager* s_instance;

    EXTERN_TEXT(
      0x80590100, //
      KartObject* GetObject(u32 playerId)
    );
};

} // namespace Kart
