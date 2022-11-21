#pragma once

#include "Mii.h"

namespace sys
{

class MiiManager
{
public:
    static MiiManager* s_instance;

    EXTERN_TEXT(0x80527B0C, Mii* ConstructMii(MiiId* id, EGG::Heap* heap));
    EXTERN_TEXT(0x805276E0, static s32 GetError());
};

} // namespace sys
