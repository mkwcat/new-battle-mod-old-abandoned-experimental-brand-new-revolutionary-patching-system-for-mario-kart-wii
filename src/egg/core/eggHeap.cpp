#include "eggHeap.h"
#include <string.h>

EXTERN_TEXT(0x80229DCC, void* operator new(u32 size));

EXTERN_TEXT(0x80229DD8, void* operator new[](u32 size, u32 align));

EXTERN_TEXT(
  0x80229DE0, void* operator new(u32 size, EGG::Heap* heap, int align)
);

EXTERN_TEXT(0x80229DF0, void* operator new[](u32 size));

EXTERN_TEXT(0x80229DFC, void* operator new[](u32 size, int align));

EXTERN_TEXT(
  0x80229E04, void* operator new[](u32 size, EGG::Heap* heap, int align)
);
