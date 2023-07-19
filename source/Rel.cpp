#include "system/Common.h"

#include <revolution/arc.h>
#include <revolution/cache.h>
#include <revolution/dvd.h>
#include <revolution/os.h>
#include <string.h>

typedef void (*PFN_voidfunc)();

extern PFN_voidfunc _ctors[];
extern PFN_voidfunc _ctors_end[];

extern __replace_struct _replarray[];
extern __replace_struct _replarray_end[];

extern _MRel_ReplaceRel _replrelarray[];
extern _MRel_ReplaceRel _replrelarray_end[];

extern _MRel_InsertData _replinsertarray[];
extern _MRel_InsertData _replinsertarray_end[];

extern __replace_struct _externarray[];
extern __replace_struct _externarray_end[];

u8 itembehaviordata[0x809C3614 - 0x809C2F48];
u8 itembehavior2array[0x809C38B4 - 0x809C36A0];

u32 SearchPatch(u32 offset)
{
    for (auto repl = _replrelarray; repl != _replrelarray_end; ++repl) {
        if (offset >= u32(repl->addr) && //
            offset < (u32(repl->addr) + repl->size)) {
            return u32(repl->dest) + (offset - u32(repl->addr));
        }
    }

    return 0;
}

void PatchRelocations()
{
    auto staticRel = *(OSModuleHeader**) 0x800030C8;
    auto modRel = *(OSModuleHeader**) 0x800030CC;

    // Offsets are set to pointers by OSLink
    auto imp = (OSModuleImp*) staticRel->impOffset;

    auto sections = (OSModuleSectionInfo*) staticRel->info.sectionInfoOffset;
    u32 sectionCount = staticRel->info.numSections;

    for (u32 i = 0; i < staticRel->impSize; i += sizeof(OSModuleImp), imp++) {
        if (imp->moduleId != staticRel->info.id)
            continue;

        u32 ptr = 0;

        OSReport("[PALA] Starting rel patches from %08X\n", imp->offset);

        for (auto reltab = (OSModuleRelInfo*) imp->offset;
             reltab->type != R_RVL_STOP; reltab++) {
            if (reltab->type == R_RVL_SECT) {
                ptr = sections[reltab->section].offset & 0xFFFFFFFC;
                OSReport("[PALA] Section start: %08X\n", ptr);
            } else {
                assert(ptr != 0);
                ptr += reltab->offset;
            }

            u32 offset = reltab->section == 0
                           ? 0
                           : sections[reltab->section].offset & 0xFFFFFFFC;
            offset += reltab->addend;
            u32 oldOffset = offset;

            switch (reltab->type) {
            default:
                break;

            case R_PPC_ADDR32:
                if ((offset = SearchPatch(offset)) != 0) {
                    OSReport(
                      "[PALA] Patched R_PPC_ADDR32 at %08X (%08X -> %08X)\n",
                      ptr, oldOffset, offset
                    );
                    *(u32*) ToUncached(ptr) = offset;
                }
                break;

            case R_PPC_ADDR16_LO:
            case R_PPC_ADDR16_HA:
            case R_PPC_ADDR16_HI:
                if ((offset = SearchPatch(offset)) != 0) {
                    if (reltab->type == R_PPC_ADDR16_LO) {
                        offset &= 0xFFFF;
                        oldOffset &= 0xFFFF;
                        OSReport(
                          "[PALA] Patched R_PPC_ADDR16_LO at %08X (%04X "
                          "-> %04X)\n",
                          ptr, oldOffset, offset
                        );
                    } else if (reltab->type == R_PPC_ADDR16_HI) {
                        offset >>= 16;
                        oldOffset >>= 16;
                        OSReport(
                          "[PALA] Patched R_PPC_ADDR16_HI at %08X (%04X "
                          "-> %04X)\n",
                          ptr, oldOffset, offset
                        );
                    } else if (reltab->type == R_PPC_ADDR16_HA) {
                        offset = (offset + 0x8000) >> 16;
                        oldOffset = (oldOffset + 0x8000) >> 16;
                        OSReport(
                          "[PALA] Patched R_PPC_ADDR16_HA at %08X (%04X "
                          "-> %04X)\n",
                          ptr, oldOffset, offset
                        );
                    }

                    if (ptr & 2) {
                        *(u32*) ToUncached(ptr - 2) =
                          ((*(u32*) ToUncached(ptr - 2)) & 0xFFFF0000) | offset;
                    } else {
                        *(u32*) ToUncached(ptr) =
                          ((*(u32*) ToUncached(ptr)) & 0xFFFF) | (offset << 16);
                    }
                }
                break;
            }
        }
    }
}

extern "C" void _prolog(s32 arcEntryNum, ARCHandle* arcHandle)
{
    // Do the external replaced array
    for (auto repl = _externarray; repl != _externarray_end; ++repl) {
        *ToUncached(repl->dest) = *repl->addr;
        ICInvalidateRange(repl->dest, 4);
    }

    // Do function patches
    for (auto repl = _replarray; repl != _replarray_end; ++repl) {
        *ToUncached(repl->addr) =
          0x48000000 | ((u32(repl->dest) - u32(repl->addr)) & 0x3FFFFFC);
        ICInvalidateRange(repl->addr, 4);
    }

    // Do data patches
    for (auto repl = _replinsertarray; repl != _replinsertarray_end; ++repl) {
        memcpy(repl->addr, repl->dest, repl->size);
        DCFlushRange(repl->addr, repl->size);
    }

    PatchRelocations();

    __DVDEXInit(arcEntryNum, arcHandle);

    // Run global constructors
    for (PFN_voidfunc* ctor = _ctors; ctor != _ctors_end && *ctor; ++ctor) {
        (*ctor)();
    }
}

extern "C" void _epilog()
{
}

extern "C" void _unresolved()
{
    // Infinite loop
    _unresolved();
}

#ifdef __clang__
int __dso_handle;

extern "C" void __cxa_atexit()
{
}
#endif
