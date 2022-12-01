#pragma once

#include <egg/core/eggHeap.h>

namespace sys
{

class HomeButtonMenu
{
public:
    EXTERN_TEXT(
      0x8051D4D4, static HomeButtonMenu* CreateInstance(EGG::Heap* heap));

    FILL(0x0, 0x2B4);
};

static_assert(sizeof(HomeButtonMenu) == 0x2B4);

} // namespace sys
