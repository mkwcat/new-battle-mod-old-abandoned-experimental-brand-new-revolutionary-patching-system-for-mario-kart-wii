#include <system/Common.h>

#undef EXTERN_TEXT
#define EXTERN_TEXT(_ADDR, _PROTOTYPE) _PROTOTYPE

#include <egg/core/eggDvdRipper.h>
#include <egg/core/eggHeap.h>
#include <rvl/os.h>

// Loader entry point. Defined in section .start so the linker will always place
// this first.
__attribute__((section(".start"))) ASM_FUNCTION(extern "C" bool _start(),
                                                // clang-format off
    // r3 = module
    // r4 = bss
    mr      r5, r24; // heap
    mflr    r6;
    b       LoaderMain;
                                                // clang-format on
);

// Function definitions. Define as extern "C" to avoid symbol name mangling for
// references from ASM.
extern "C" {
void PortCall();
bool LoaderMain(OSModuleInfo* info, void* bss, EGG::Heap* heap, u32 lr);
static void LoaderAssertFail(const char* expr, s32 line);
}

#define LOADER_ASSERT(_EXPR)                                                   \
  (((_EXPR) ? (void) 0 : LoaderAssertFail(#_EXPR, __LINE__)))

// Since the same loader.bin file will be used for every region, ported
// addresses need to be realized on the fly. Every external symbol will be
// defined in this file.

// Regions in the order E, J, P, K
u8 g_portIndex = 0xFF;

ASM_FUNCTION(void PortCall(),
             // clang-format off
    mflr    r11; // Addresses
    mtlr    r12; // Restore return address
    lis     r12, g_portIndex@ha;
    lbz     r12, g_portIndex@l(r12);
    slwi    r12, r12, 2;
    lwzx    r12, r11, r12;
    mtctr   r12;
    bctr;
             // clang-format on
);

#define DEFINE_EXTERNAL_FUNCTION(                                              \
  _PROTOTYPE, _ADDR_E, _ADDR_J, _ADDR_P, _ADDR_K                               \
)                                                                              \
  ASM_FUNCTION(_PROTOTYPE, mflr r12; bl PortCall;.long _ADDR_E;.long _ADDR_J;  \
                 .long _ADDR_P;.long _ADDR_K;)

// clang-format off

DEFINE_EXTERNAL_FUNCTION(
  int snprintf(char* str, u32 n, const char* format, ...),
  0x80010DD8, 0x8001185C, 0x80011938, 0x800119A0
)

DEFINE_EXTERNAL_FUNCTION(
  bool OSLink(OSModuleInfo* info, void* bss),
  0x801A723C, 0x801A71FC, 0x801A72DC, 0x801A7638
);

DEFINE_EXTERNAL_FUNCTION(
  void OSFatal(u32* textColor, u32* bgColor, const char* text),
  0x801A4E24, 0x801A4dE4, 0x801A4EC4, 0x801A5220
)

DEFINE_EXTERNAL_FUNCTION(
  u8* EGG::DvdRipper::loadToMainRAM(
    const char* path, u8* dst, EGG::Heap* heap,
    EGG::DvdRipper::EAllocDirection allocDirection, u32 offset, u32* amountRead,
    u32* fileSize
  ),
  0x80222638, 0x802225F8, 0x802226D8, 0x80222A4C
);

// clang-format on

char g_modulePath[] = "/rel/BattleE.rel";

static bool GetPortByLR(u32 lr)
{
    switch (lr) {
    case 0x8000A254: // RMCE
        g_portIndex = 0;
        return true;

    case 0x8000A1F0: // RMCJ
        g_portIndex = 1;
        g_modulePath[11] = 'J';
        return true;

    case 0x8000A294: // RMCP
        g_portIndex = 2;
        g_modulePath[11] = 'P';
        return true;

    case 0x8000A39C: // RMCK
        g_portIndex = 3;
        g_modulePath[11] = 'K';
        return true;

    default:
        return false;
    }
}

static bool GetPortByCheck()
{
    switch (GetCodeRegion()) {
    case Region::E: // RMCE
        g_portIndex = 0;
        return true;

    case Region::J: // RMCJ
        g_portIndex = 1;
        g_modulePath[11] = 'J';
        return true;

    case Region::P: // RMCP
        g_portIndex = 2;
        g_modulePath[11] = 'P';
        return true;

    case Region::K: // RMCK
        g_portIndex = 3;
        g_modulePath[11] = 'K';
        return true;

    default:
        return false;
    }
}

static bool GetPortByRegionChar()
{
    switch (*(u32*) 0x80000000) {
    case 0x524D4345: // RMCE
        g_portIndex = 0;
        return true;

    case 0x524D434A: // RMCJ
        g_portIndex = 1;
        g_modulePath[11] = 'J';
        return true;

    case 0x524D4350: // RMCP
        g_portIndex = 2;
        g_modulePath[11] = 'P';
        return true;

    case 0x524D434B: // RMCK
    case 0x524D4343: // RMCC
        g_portIndex = 3;
        g_modulePath[11] = 'K';
        return true;

    default:
        return false;
    }
}

bool LoaderMain(OSModuleInfo* info, void* bss, EGG::Heap* heap, u32 lr)
{
    if (!GetPortByLR(lr) && !GetPortByCheck() && !GetPortByRegionChar()) {
        // No valid region could be found! It's likely that this is not even
        // Mario Kart Wii, or at least not any released version of it. The
        // reason why there are so many backup region checks is because if the
        // region can't be found then we can't display any error message.

        // However we can display a solid color to the screen using HW_VISOLID.
        // This doesn't work on Dolphin, but it does work on Wii/vWii. This
        // color is blue.
        *(u32*) 0xCD000024 = ((255 << 24) | (107 << 16) | (29 << 8) | 1);
        while (true) {
        }
    }

    u8* moduleBlock = EGG::DvdRipper::loadToMainRAM(
      g_modulePath, nullptr, heap, EGG::DvdRipper::ALLOC_DIR_TOP, 0, nullptr,
      nullptr
    );
    LOADER_ASSERT(!!moduleBlock);

    auto header = reinterpret_cast<OSModuleHeader*>(moduleBlock);

    void* bssBlock = heap->alloc(header->bssSize, 32);
    LOADER_ASSERT(!!bssBlock);

    bool osLinkModOk = OSLink(&header->info, bssBlock);
    LOADER_ASSERT(osLinkModOk);

    // Call prolog to do the pre-link StaticR.rel patches. This is necessary for
    // data relocation patches.
    (*(void (*)()) header->prolog)();

    bool osLinkOk = OSLink(info, bss);
    LOADER_ASSERT(osLinkOk);

    // Call epilog to do the post-link patches. This function is normally
    // reserved for unloading a rel file, but we repurpose it here.
    (*(void (*)()) header->epilog)();

    return true;
}

__attribute__((noinline)) static void
LoaderAssertFail(const char* expr, s32 line)
{
    char printMsg[0x400];
    snprintf(
      printMsg, 0x400,
      "Loader assertion failed\n"
      "  %s\n"
      "  line %d\n",
      expr, line
    );

    u32 textColor = 0xFFFFFFFF;
    u32 bgColor = 0x000000FF;
    OSFatal(&textColor, &bgColor, printMsg);
    while (1) {
    }
}
