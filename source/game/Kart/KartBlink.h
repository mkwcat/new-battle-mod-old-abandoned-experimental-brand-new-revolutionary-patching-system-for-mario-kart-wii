#pragma once

#include "KartObjectProxy.h"

namespace Kart
{

class KartBlink : public KartObjectProxy
{
public:
    EXTERN_TEXT(
      0x8056A300, //
      void Calc(bool lastFrame)
    );

    FILL(0xC, 0x14);
};

static_assert(sizeof(KartBlink) == 0x14);

} // namespace Kart
