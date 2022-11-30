#pragma once

#include "KartObjectProxy.h"

namespace kart
{

class KartMove : public KartObjectProxy
{
public:
    EXTERN_TEXT(0x80581778, void BattleSideline());
    void BattleFlagsUpdate(); // Replaced 80581824

private:
    FILL(0xC, 0x1A8);
    s16 m_battleBlinkTimer;
    FILL(0x1AA, 0x1AC);
    s16 m_battleVanishTimer;
    FILL(0x1AE, 0x294);
};

static_assert(sizeof(KartMove) == 0x294);

}; // namespace kart
