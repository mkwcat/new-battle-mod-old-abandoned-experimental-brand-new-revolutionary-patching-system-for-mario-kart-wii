#pragma once

#include <egg/core/eggHeap.h>

namespace Sound
{

class SoundManager
{
public:
    EXTERN_TEXT(0x80716E2C, static SoundManager* CreateInstance());

    EXTERN_TEXT(0x80717150, void Init(EGG::Heap* heap));

    FILL(0, 0x8C0);
};

static_assert(sizeof(SoundManager) == 0x8C0);

} // namespace Sound
