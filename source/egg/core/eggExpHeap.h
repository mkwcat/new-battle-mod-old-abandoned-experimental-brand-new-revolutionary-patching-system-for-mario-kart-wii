#pragma once

#include "eggHeap.h"

namespace EGG
{

class ExpHeap : public Heap
{
public:
    EXTERN_TEXT(
      0x80226AC8, static ExpHeap* create(u32 size, Heap* heap, u16 attr));
};

} // namespace EGG
