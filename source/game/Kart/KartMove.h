#pragma once

#include "KartObjectProxy.h"

namespace Kart
{

class KartMove : public KartObjectProxy
{
public:
    /* 0x805799AC */
    void StartRespawn();

    /* 0x80581778 */
    void BattleSideline();

    /* --- */
    void StartFeatherJump();

    /* 0x80581824 */
    void BattleFlagsUpdate();

private:
    FILL(0xC, 0x1A8);
    s16 m_battleBlinkTimer;
    FILL(0x1AA, 0x1AC);
    s16 m_battleVanishTimer;
    FILL(0x1AE, 0x250);

    enum eSpecialFloor {
        SPECIAL_FLOOR_BOOST_PANEL = 0x1,
        SPECIAL_FLOOR_BOOST_RAMP = 0x2,
        SPECIAL_FLOOR_JUMP_PAD = 0x4,
    };

    u32 m_specialFloor;

    FILL(0x254, 0x294);
};

static_assert(sizeof(KartMove) == 0x294);

}; // namespace Kart
