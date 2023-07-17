#include <system/Common.h>

#undef EXTERN_TEXT
#define EXTERN_TEXT(_ADDR, _PROTOTYPE) _PROTOTYPE

#include <egg/core/eggDvdFile.h>
#include <egg/core/eggDvdRipper.h>
#include <egg/core/eggHeap.h>
#include <revolution/arc.h>
#include <revolution/os.h>
#include <string.h>

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

// Since the same Loader.bin file will be used for every region, ported
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
    ASM_FUNCTION(_PROTOTYPE, mflr r12; bl PortCall;.long _ADDR_E;              \
                   .long _ADDR_J;.long _ADDR_P;.long _ADDR_K;)

DEFINE_EXTERNAL_FUNCTION(
  void* memset(void* dst, int val, size_t len), //
  0x80006038, 0x80006038, 0x80006038, 0x80006038
);

DEFINE_EXTERNAL_FUNCTION(
  int snprintf(char* str, u32 n, const char* format, ...), //
  0x80010DD8, 0x8001185C, 0x80011938, 0x800119A0
);

DEFINE_EXTERNAL_FUNCTION(
  s32 DVDConvertPathToEntrynum(const char* fileName), //
  0x8015DEAC, 0x8015DE6C, 0x8015DF4C, 0x8015DFC4
);

DEFINE_EXTERNAL_FUNCTION(
  bool OSLink(OSModuleInfo* info, void* bss), //
  0x801A723C, 0x801A71FC, 0x801A72DC, 0x801A7638
);

DEFINE_EXTERNAL_FUNCTION(
  void OSFatal(u32* textColor, u32* bgColor, const char* text), //
  0x801A4E24, 0x801A4DE4, 0x801A4EC4, 0x801A5220
);

DEFINE_EXTERNAL_FUNCTION(
  bool ARCInitHandle(void* arcStart, ARCHandle* handle), //
  0x80124460, 0x80124420, 0x80124500, 0x80124578
);

DEFINE_EXTERNAL_FUNCTION(
  bool ARCOpen(ARCHandle* handle, const char* fileName, ARCFileInfo* af), //
  0x80124500, 0x801244C0, 0x801245A0, 0x80124618
);

DEFINE_EXTERNAL_FUNCTION(
  u32 ARCGetStartOffset(ARCFileInfo* af), //
  0x80124C34, 0x80124BF4, 0x80124CD4, 0x80124D4C
);

DEFINE_EXTERNAL_FUNCTION(
  u32 ARCGetLength(ARCFileInfo* af), //
  0x80124C3C, 0x80124BFC, 0x80124CDC, 0x80124D54
);

// Actually a constructor but we can't define it due to a compiler bug.
DEFINE_EXTERNAL_FUNCTION(
  EGG::DvdFile* MakeDvdFile(void* data), //
  0x802222BC, 0x8022227C, 0x8022235C, 0x802226D0
);

DEFINE_EXTERNAL_FUNCTION(
  bool EGG::DvdFile::open(int entryNum), //
  0x802223D0, 0x80222390, 0x80222470, 0x802227e4
);

#if 0

DEFINE_EXTERNAL_FUNCTION(
  bool EGG::DvdFile::open(const char* path), //
  0x80222448, 0x80222408, 0x802224E8, 0x8022285C
)

DEFINE_EXTERNAL_FUNCTION(
  bool EGG::DvdFile::open(const char* path, void* param_2), //
  0x80222490, 0x80222450, 0x80222530, 0x802228A4
)

#endif

DEFINE_EXTERNAL_FUNCTION(
  void EGG::DvdFile::close(), //
  0x802224A0, 0x80222460, 0x80222540, 0x802228B4
);

DEFINE_EXTERNAL_FUNCTION(
  s32 EGG::DvdFile::readData(void* data, s32 len, s32 offset), //
  0x802224FC, 0x802224BC, 0x8022259C, 0x80222910
);

DEFINE_EXTERNAL_FUNCTION(
  s32 EGG::DvdFile::writeData(const void* data, s32 len, s32 offset), //
  0x802225C0, 0x80222580, 0x80222660, 0x802229D4
);

DEFINE_EXTERNAL_FUNCTION(
  s32 EGG::DvdFile::getFileSize() const, //
  0x80222630, 0x802225F0, 0x802226D0, 0x80222A44
);

DEFINE_EXTERNAL_FUNCTION(
  u8* EGG::DvdRipper::loadToMainRAM(
    const char* path, u8* dst, EGG::Heap* heap,
    EGG::DvdRipper::EAllocDirection allocDirection, u32 offset, u32* amountRead,
    u32* fileSize
  ), //
  0x80222638, 0x802225F8, 0x802226D8, 0x80222A4C
);

DEFINE_EXTERNAL_FUNCTION(
  u8* EGG::DvdRipper::loadToMainRAMDecomp(
    const char* path, EGG::StreamDecomp* streamDecomp, u8* dst, Heap* heap,
    EAllocDirection allocDirection, u32 offset, u32 size, u32 maxChunkSize
  ), //
  0x8022289C, 0x8022285C, 0x8022293C, 0x80222CB0
);

DEFINE_EXTERNAL_FUNCTION(
  bool EGG::StreamDecompLZ::init(void* dst, u32 maxCompressedSize), //
  0x802415DC, 0x802423B8, 0x80242498, 0x8024280C
);

DEFINE_EXTERNAL_FUNCTION(
  bool EGG::StreamDecompLZ::decomp(const void* src, u32 len), //
  0x8024160C, 0x802423E8, 0x802424C8, 0x8024283C
);

DEFINE_EXTERNAL_FUNCTION(
  u32 EGG::StreamDecompLZ::getHeaderSize(), //
  0x80241638, 0x80242414, 0x802424F4, 0x80242868
);

DEFINE_EXTERNAL_FUNCTION(
  u32 EGG::StreamDecompLZ::getUncompressedSize(const void* src), //
  0x80241640, 0x8024241C, 0x802424FC, 0x80242870
);

constexpr u32 MODULE_MAX_SIZE = 0x80000;

char g_modulePath[] = "./rel/BattleE.rel.LZ";

const char g_contentsArc[] = "/MKWBattleModData/MKWBattleModData.arc";

static bool GetPortByLR(u32 lr)
{
    switch (lr) {
    case 0x8000A254: // RMCE
        g_portIndex = 0;
        return true;

    case 0x8000A1F0: // RMCJ
        g_portIndex = 1;
        g_modulePath[12] = 'J';
        return true;

    case 0x8000A294: // RMCP
        g_portIndex = 2;
        g_modulePath[12] = 'P';
        return true;

    case 0x8000A39C: // RMCK
        g_portIndex = 3;
        g_modulePath[12] = 'K';
        return true;

    default:
        return false;
    }
}

static bool GetPortByCode()
{
    switch (GetCodeRegion()) {
    case Region::E: // RMCE
        g_portIndex = 0;
        return true;

    case Region::J: // RMCJ
        g_portIndex = 1;
        g_modulePath[12] = 'J';
        return true;

    case Region::P: // RMCP
        g_portIndex = 2;
        g_modulePath[12] = 'P';
        return true;

    case Region::K: // RMCK
        g_portIndex = 3;
        g_modulePath[12] = 'K';
        return true;

    default:
        return false;
    }
}

static bool GetPortByTitleID()
{
    switch (*(u32*) 0x80000000) {
    case 0x524D4345: // RMCE
        g_portIndex = 0;
        return true;

    case 0x524D434A: // RMCJ
        g_portIndex = 1;
        g_modulePath[12] = 'J';
        return true;

    case 0x524D4350: // RMCP
        g_portIndex = 2;
        g_modulePath[12] = 'P';
        return true;

    case 0x524D434B: // RMCK
    case 0x524D4343: // RMCC
        g_portIndex = 3;
        g_modulePath[12] = 'K';
        return true;

    default:
        return false;
    }
}

bool LoaderMain(OSModuleInfo* info, void* bss, EGG::Heap* heap, u32 lr)
{
    if (!GetPortByLR(lr) && !GetPortByCode() && !GetPortByTitleID()) {
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

    bool osLinkOk = OSLink(info, bss);
    LOADER_ASSERT(osLinkOk);

    u8* moduleBlock = reinterpret_cast<u8*>(heap->alloc(MODULE_MAX_SIZE, 32));
    LOADER_ASSERT(!!moduleBlock);

    ARCHandle* arcHandle =
      reinterpret_cast<ARCHandle*>(heap->alloc(sizeof(ARCHandle), 4));
    LOADER_ASSERT(!!arcHandle);

    EGG::DvdFile* dvdFile = MakeDvdFile(heap->alloc(sizeof(EGG::DvdFile), 4));
    LOADER_ASSERT(!!dvdFile);

    s32 arcEntryNum = DVDConvertPathToEntrynum(g_contentsArc);
    LOADER_ASSERT(arcEntryNum != -1);

    // Open MKWBattleModData.arc
    bool dvdOpenOk = dvdFile->open(arcEntryNum);
    LOADER_ASSERT(dvdOpenOk);

    // Read the 32 byte ARC header to get the size of the full header
    ARCHeader arcSmallHeader alignas(32);
    bool arcHeaderReadOk =
      dvdFile->readData(&arcSmallHeader, sizeof(ARCHeader), 0) ==
      sizeof(ARCHeader);
    LOADER_ASSERT(arcHeaderReadOk);

    s32 arcHeaderSize = (arcSmallHeader.fileStart + 31) & ~31;
    void* arcHeader = heap->alloc(arcHeaderSize, 32);
    LOADER_ASSERT(!!arcHeader);

    // Read the full header
    bool arcFullHeaderReadOk =
      dvdFile->readData(arcHeader, arcHeaderSize, 0) == arcHeaderSize;
    LOADER_ASSERT(arcFullHeaderReadOk);

    bool arcInitHandleOk = ARCInitHandle(arcHeader, arcHandle);
    LOADER_ASSERT(arcInitHandleOk);

    ARCFileInfo arcFileInfo;
    bool arcOpenOk = ARCOpen(arcHandle, g_modulePath, &arcFileInfo);
    LOADER_ASSERT(arcOpenOk);

    EGG::StreamDecompLZ lzStream;

    moduleBlock = EGG::DvdRipper::loadToMainRAMDecomp(
      g_contentsArc, &lzStream, moduleBlock, heap,
      EGG::DvdRipper::ALLOC_DIR_TOP, ARCGetStartOffset(&arcFileInfo),
      ARCGetLength(&arcFileInfo), 0x1000
    );
    LOADER_ASSERT(!!moduleBlock);

    auto header = reinterpret_cast<OSModuleHeader*>(moduleBlock);

    LOADER_ASSERT(header->bssSize <= MODULE_MAX_SIZE - header->fixSize);

    void* bssBlock = moduleBlock + header->fixSize;
    LOADER_ASSERT(!!bssBlock);

    bool osLinkModOk = OSLink(&header->info, bssBlock);
    LOADER_ASSERT(osLinkModOk);

    memset(bssBlock, 0, header->bssSize);

    (*(void (*)(...)) header->prolog)(arcEntryNum, arcHandle);

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
