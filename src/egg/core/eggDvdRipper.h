#pragma once

#include "eggHeap.h"

namespace EGG::DvdRipper
{

enum EAllocDirection {
    ALLOC_DIR_TOP = 1,
    ALLOC_DIR_BOTTOM = 2,
};

u8* loadToMainRAM(
  const char* path, u8* dst, Heap* heap, EAllocDirection allocDirection,
  u32 offset, u32* amountRead, u32* fileSize
);

} // namespace EGG::DvdRipper
