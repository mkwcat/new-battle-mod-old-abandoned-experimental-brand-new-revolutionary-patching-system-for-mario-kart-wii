#include "dwc_auth_interface.h"
#include "dwc_memfunc.h"
#include <egg/core/eggDvdFile.h>
#include <revolution/os.h>
#include <string.h>

extern "C" {

#define WIIMMFI_PATCHER_STRING "TLSCODE"

#define DWC_VERSION_STRING                                                     \
    "<< RVL_SDK - DWC \trelease build: Mar  1 2008 21:50:41 (0x4199_60831) >>"

EXTERN_TEXT(
  0x800E9414, //
  void DWCi_NpSetInitFlag(int flag)
);

EXTERN_TEXT(
  0x800E9DE8, //
  u64 DWCi_Np_GetConsoleId()
);

EXTERN_TEXT(
  0x800CCE9C, //
  void* DWCi_GsMalloc(u32 size)
);

EXTERN_TEXT(
  0x800CCFD4, //
  void* DWCi_GsFree(void* block)
);

EXTERN_TEXT(
  0x800CCF04, //
  void* DWCi_GsRealloc(void* block, u32 size)
);

EXTERN_TEXT(
  0x800CCFF8, //
  void* DWCi_GsMemalign(u32 size, u32 align)
);

EXTERN_TEXT(
  0x800F3844, //
  void gsiMemoryCallbacksSet(
    void* fMalloc, void* fFree, void* fRealloc, void* fMemalign
  )
);

EXTERN_DATA(
  0x803862B0, //
  u32 dwci_gamecode
);

EXTERN_DATA(
  0x8027A474, //
  const char* authServerHosts[3]
);

REPLACE(
  0x800CCC80, //
  int DWC_Init(
    int authSvr, char* gameName, u32 gameCode, DWCAllocEx allocator,
    DWCFreeEx freeer
  )
)
{
    OSRegisterVersion(DWC_VERSION_STRING);

    DWCi_SetMemFunc(allocator, freeer);
    DWCi_Auth_InitInterface(2); // Force payload authserver

    dwci_gamecode = gameCode;

    extern char ext_0x802F3620[];
    strcpy(ext_0x802F3620, gameName);

    extern char ext_0x8027DA78[];
    strcpy(ext_0x8027DA78, "gamestats.gs.wiimmfi.de");

    extern char ext_0x80276054[];
    strcpy(ext_0x80276054, WIIMMFI_PATCHER_STRING);

    extern char ext_0x8027A404[];
    char* urls = ext_0x8027A404;
    strcpy(urls + 0xA4, "https://naswii.wiimmfi.de/pr");
    strcpy(urls + 0x954, "%s.available.gs.wiimmfi.de");
    strcpy(urls + 0x10CC, "gpcm.gs.wiimmfi.de");
    strcpy(urls + 0x1AE4, "gpsp.gs.wiimmfi.de");
    strcpy(urls + 0x2C80, "%s.master.gs.wiimmfi.de");
    strcpy(urls + 0x389C, "natneg1.gs.wiimmfi.de");
    strcpy(urls + 0x38B8, "natneg2.gs.wiimmfi.de");
    strcpy(urls + 0x38D4, "natneg3.gs.wiimmfi.de");
    strcpy(urls + 0x3A24, "%s.ms%d.gs.wiimmfi.de");
    strcpy(urls + 0x3AB0, "gs.wiimmfi.de");

    authServerHosts[0] = "https://ca.nas.wiimmfi.de/ca";
    authServerHosts[1] = "https://naswii.wiimmfi.de/ac";

    switch (GetCodeRegion()) {
    case Region::P:
        authServerHosts[2] = "https://main.nas.wiimmfi.de/pp";
        break;
    case Region::E:
        authServerHosts[2] = "https://main.nas.wiimmfi.de/pe";
        break;
    case Region::J:
        authServerHosts[2] = "https://main.nas.wiimmfi.de/pj";
        break;
    case Region::K:
        authServerHosts[2] = "https://main.nas.wiimmfi.de/pk";
        break;
    }

    gsiMemoryCallbacksSet(
      (void*) &DWCi_GsMalloc, (void*) &DWCi_GsFree, (void*) &DWCi_GsRealloc,
      (void*) &DWCi_GsMemalign
    );

    DWCi_NpSetInitFlag(1);
    DWCi_Np_GetConsoleId();

    return 0;
}

struct LECTHeader {
    /* 0x00 */ char magic[4];
    /* 0x04 */ u32 lect_version;
    /* 0x08 */ u32 build_version;
    /* 0x0C */ void* address;
    /* 0x10 */ u32 entry;
    /* 0x14 */ u32 size;
    /* 0x18 */ u32 param_sect_offset;
    /* 0x1C */ char region;
    /* 0x1D */ char debug_mode;
    /* 0x1E */ u8 le_phase;
    /* 0x1F */ u8 pad;
    /* 0x20 */ char build_date[32];
};

static_assert(sizeof(LECTHeader) == 0x40);

void DWC_InitWiimmfiPayload()
{
    EGG::DvdFile file;

    bool dvdOpenOk = file.open("/Boot/WiimmfiP.bin");
    assert(dvdOpenOk);

    LECTHeader lect alignas(32);
    bool lectHeaderReadOk =
      file.readData(&lect, sizeof(LECTHeader), 0) == sizeof(LECTHeader);
    assert(lectHeaderReadOk);

    assert(memcmp(lect.magic, "LECT", 4) == 0);
    assert(lect.lect_version == 5);
    assert(lect.region == 'P');

    bool lectReadOk = file.readData(lect.address, lect.size, 0) == lect.size;
    assert(lectReadOk);

    (*(void (*)()) lect.entry)();
}

//
}
