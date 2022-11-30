#pragma once

#include "KartObjectProxy.h"

namespace kart
{

class KartObject : public KartObjectProxy
{
    FILL(0xC, 0x80);
};

static_assert(sizeof(KartObject) == 0x80);

} // namespace kart
