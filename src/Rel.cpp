#include "system/Common.h"

#include "dwc/WiimmfiCA.cpp"
#include "dwc/dwc_auth.cpp"
#include "dwc/dwc_init.cpp"
#include "dwc/dwc_memfunc.cpp"
#include "egg/core/eggHeap.cpp"
#include "game/enemy/AIBattleManager.cpp"
#include "game/kart/KartCollide.cpp"
#include "game/kart/KartMove.cpp"
#include "game/kart/KartObjectManager.cpp"
#include "game/net/Nwc24Manager.cpp"
#include "game/object/BattleBalloon.cpp"
#include "game/sys/InputManager.cpp"
#include "game/sys/MiiManager.cpp"
#include "game/sys/NandManager.cpp"
#include "game/sys/RaceConfig.cpp"
#include "game/sys/RaceManager.cpp"
#include "game/sys/RootScene.cpp"
#include "game/sys/SaveManager.cpp"
#include "game/ui/ExternTypeInfo.cpp"
#include "game/ui/Section.cpp"
#include "game/ui/SectionManager.cpp"
#include "game/ui/SystemMessageGroup.cpp"
#include "host_sys/RKSystem.cpp"
#include "host_sys/SystemManager.cpp"
#include "nw4r/lyt/lyt_init.cpp"
#include "platform/string.cpp"
#include "rvl/cache.cpp"
#include "rvl/nhttp.cpp"
#include "rvl/os.cpp"
#include "system/Common.cpp"

typedef void (*PFN_voidfunc)();

extern PFN_voidfunc _ctors[];
extern PFN_voidfunc _ctors_end[];

extern __replace_struct _replarray[];
extern __replace_struct _replarray_end[];

extern __replace_struct _externarray[];
extern __replace_struct _externarray_end[];

u8 itembehaviordata[0x809C3614 - 0x809C2F48];
u8 itembehavior2array[0x809C38B4 - 0x809C36A0];

u32 SearchPatch(u32 offset)
{
#if 0
    if (offset >= 0x809C2F48 && offset < 0x809C3614)
        return u32(&itembehaviordata) + (offset - 0x809C2F48);

    if (offset >= 0x809C36A0 && offset < 0x809C38B4)
        return u32(&itembehavior2array) + (offset - 0x809C36A0);
#endif

    return 0; // For now
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
                      ptr, oldOffset, offset);
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
                        OSReport("[PALA] Patched R_PPC_ADDR16_LO at %08X (%04X "
                                 "-> %04X)\n",
                          ptr, oldOffset, offset);
                    } else if (reltab->type == R_PPC_ADDR16_HI) {
                        offset >>= 16;
                        oldOffset >>= 16;
                        OSReport("[PALA] Patched R_PPC_ADDR16_HI at %08X (%04X "
                                 "-> %04X)\n",
                          ptr, oldOffset, offset);
                    } else if (reltab->type == R_PPC_ADDR16_HA) {
                        offset = (offset + 0x8000) >> 16;
                        oldOffset = (oldOffset + 0x8000) >> 16;
                        OSReport("[PALA] Patched R_PPC_ADDR16_HA at %08X (%04X "
                                 "-> %04X)\n",
                          ptr, oldOffset, offset);
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

extern "C" void _prolog()
{
    PatchRelocations();

    // Do the external replaced array
    for (auto repl = _externarray; repl != _externarray_end; ++repl) {
        *ToUncached(repl->dest) = *repl->addr;
        ICInvalidateRange(repl->dest, 4);
    }

    // Do function patches
    for (auto repl = _replarray; repl != _replarray_end; ++repl) {
        *ToUncached(repl->addr) =
          0x48000000 | ((u32(repl->dest) - u32(repl->addr)) & 0x3FFFFFC);
        ICInvalidateRange(repl->dest, 4);
    }

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
