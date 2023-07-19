#pragma once

#include "KartState.h"
#include <Sound/KartSound.h>

namespace Kart
{

class KartMove;
class KartBlink;

struct KartAccessor {
    FILL(0x0, 0x4);
    KartState* m_state;
    FILL(0x8, 0x28);
    KartMove* m_move;
    FILL(0x2C, 0x58);
    KartBlink* m_blink;
    FILL(0x5C, 0x64);
};

class KartObjectProxy
{
public:
    /* 0x8059020C */
    f32* GetPlayerPosition();

    /* 0x80590A5C */
    u32 GetPlayerID();

    KartState* GetKartState()
    {
        return m_accessor->m_state;
    }

    /* 0x8059077C */
    KartMove* GetKartMove();

    /* 0x80590794 */
    Sound::KartSound* GetKartSound();

    /* 0x805907B0 */
    void PlayVoiceSe(u32 type);

    /* 0x8059108C */
    KartBlink* GetKartBlink();

protected:
    KartAccessor* m_accessor;
    FILL(0x4, 0xC);
};

static_assert(sizeof(KartObjectProxy) == 0xC);

} // namespace Kart
