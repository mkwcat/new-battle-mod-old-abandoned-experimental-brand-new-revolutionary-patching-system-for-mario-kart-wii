#include "eggDvdRipper.h"

namespace EGG
{

EXTERN_TEXT(
  0x802226D8, //
  u8* DvdRipper::loadToMainRAM(
    const char* path, u8* dst, Heap* heap, EAllocDirection allocDirection,
    u32 offset, u32* amountRead, u32* fileSize
  )
);

}
