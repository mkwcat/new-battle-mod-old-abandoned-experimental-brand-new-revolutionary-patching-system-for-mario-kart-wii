#include "system/Common.h"

#include "dwc/WiimmfiCA.cpp"
#include "dwc/dwc_auth.cpp"
#include "dwc/dwc_init.cpp"
#include "dwc/dwc_memfunc.cpp"
#include "egg/core/eggHeap.cpp"
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

extern "C" void _prolog()
{
    // Do function patches
    for (auto repl = _replarray; repl != _replarray_end; ++repl) {
        *repl->addr =
          0x48000000 | ((u32(repl->dest) - u32(repl->addr)) & 0x3FFFFFC);
        DCFlushRange(repl->addr, 4);
        ICInvalidateRange(repl->addr, 4);
    }

    // Run global constructors
    for (PFN_voidfunc* ctor = _ctors; ctor != _ctors_end && *ctor; ++ctor) {
        (*ctor)();
    }
}

extern "C" void _epilog()
{
    // Infinite loop
    _epilog();
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
