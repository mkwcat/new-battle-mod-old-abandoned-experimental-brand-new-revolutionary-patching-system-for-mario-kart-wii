#pragma once

#include "SoundID.h"

namespace Sound
{

class KartSound
{
public:
    /* 0x80709980 */
    void PlaySound(ESoundID sound);

    /* 0x80708BAC */
    void PlayDashSound();
};

} // namespace Sound
