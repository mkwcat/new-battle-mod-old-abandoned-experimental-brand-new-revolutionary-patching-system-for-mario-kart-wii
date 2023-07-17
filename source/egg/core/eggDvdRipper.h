#pragma once

#include "eggHeap.h"
#include "eggStreamDecomp.h"

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

u8* loadToMainRAMDecomp(
  const char* path, StreamDecomp* streamDecomp, u8* dst, Heap* heap,
  EAllocDirection allocDirection, u32 offset, u32 size, u32 maxChunkSize
);

} // namespace EGG::DvdRipper
