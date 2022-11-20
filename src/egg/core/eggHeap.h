#pragma once

namespace EGG
{

class Heap
{
public:
    virtual ~Heap();

    virtual s32 _0(); // getHeapKind
    virtual s32 _1(); // initAllocator
    virtual void* alloc(u32 len, s32 align) = 0;
    virtual void free(void* block) = 0;
    virtual s32 _2(); // destroy
    virtual s32 _3(); // resizeForMBlock
    virtual s32 _4(); // getAllocatableSize
    virtual s32 _5(); // adjust
};

} // namespace EGG

void* operator new(u32 size);

void* operator new[](u32 size, u32 align);

void* operator new(u32 size, EGG::Heap* heap, int align);

void* operator new[](u32 size);

void* operator new[](u32 size, int align);

void* operator new[](u32 size, EGG::Heap* heap, int align);
