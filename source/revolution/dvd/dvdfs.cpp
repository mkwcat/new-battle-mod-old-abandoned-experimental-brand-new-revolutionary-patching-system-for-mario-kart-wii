#include <revolution/dvd.h>

extern "C" {

static constexpr u32 DVDEX_ARC_ENTRYNUM_BASE = 800000;

static s32 s_dvdExArc = -1;
static ARCHandle* s_dvdExArcHandle = nullptr;

// 8015DF1C: __DVDFSInit

void __DVDEXInit(s32 arcEntryNum, ARCHandle* arcHandle)
{
    if (s_dvdExArcHandle != nullptr) {
        return;
    }

    if (arcEntryNum == -1) {
        return;
    }

    s_dvdExArc = arcEntryNum;
    s_dvdExArcHandle = arcHandle;

    bool arcChangeDirOk = ARCChangeDir(s_dvdExArcHandle, "/.");
    assert(arcChangeDirOk);
}

EXTERN_REPL(
  0x8015DF4C, //
  s32 __DVDPathToEntrynum(const char* fileName)
);

REPLACE(
  0x8015DF4C, //
  s32 DVDConvertPathToEntrynum(const char* fileName)
)
{
    OSReport("DVDConvertPathToEntrynum(): %s\n", fileName);

    if (s_dvdExArcHandle != nullptr) {
        s32 entryNum = ARCConvertPathToEntrynum(
          s_dvdExArcHandle, *fileName == '/' ? fileName + 1 : fileName
        );

        if (entryNum != -1) {
            return entryNum + DVDEX_ARC_ENTRYNUM_BASE;
        }
    }

    return __DVDPathToEntrynum(fileName);
}

// UNUSED: DVDEntrynumIsDir

EXTERN_REPL(
  0x8015E254, //
  bool __DVDFastOpen(s32 entryNum, DVDFileInfo* fileInfo)
);

REPLACE(
  0x8015E254, //
  bool DVDFastOpen(s32 entryNum, DVDFileInfo* fileInfo)
)
{
    if (s_dvdExArcHandle == nullptr || entryNum < DVDEX_ARC_ENTRYNUM_BASE) {
        return __DVDFastOpen(entryNum, fileInfo);
    }

    ARCFileInfo af;
    bool ret =
      ARCFastOpen(s_dvdExArcHandle, entryNum - DVDEX_ARC_ENTRYNUM_BASE, &af);

    if (!ret) {
        return false;
    }

    ret = __DVDFastOpen(s_dvdExArc, fileInfo);

    if (!ret) {
        return false;
    }

    fileInfo->startAddr += ARCGetStartOffset(&af) >> 2;
    fileInfo->length = ARCGetLength(&af);

    return true;
}

REPLACE(
  0x8015E2BC, //
  bool DVDOpen(const char* fileName, DVDFileInfo* fileInfo)
)
{
    s32 entryNum = DVDConvertPathToEntrynum(fileName);

    if (entryNum == -1) {
        return false;
    }

    return DVDFastOpen(entryNum, fileInfo);
}

EXTERN_TEXT(
  0x8015E568, //
  bool DVDClose(DVDFileInfo* fileInfo)
);

EXTERN_TEXT_STATIC(
  0x8015E58C, //
  void entryToPath()
);

// UNUSED: DVDGetCurrentDir

// UNUSED: DVDChangeDir

EXTERN_TEXT(
  0x8015E74C, //
  void DVDReadAsyncPrio()
);

EXTERN_TEXT_STATIC(
  0x8015E81C, //
  void cbForReadAsync()
);

EXTERN_TEXT(
  0x8015E834, //
  s32 DVDReadPrio(
    DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32 prio
  )
);

EXTERN_TEXT_STATIC(
  0x8015E95C, //
  void cbForReadSync()
);

// UNUSED: DVDSeekAsyncPrio

// UNUSED: cbForSeekAsync

// UNUSED: DVDSeekPrio

// UNUSED: cbForSeekSync

// UNUSED: DVDGetFileInfoStatus

// UNUSED: DVDFastOpenDir

// UNUSED: DVDOpenDir

// UNUSED: DVDReadDir

// UNUSED: DVDCloseDir

// UNUSED: DVDRewindDir

// UNUSED: DVDGetFSTLocation

// UNUSED: DVDGetTransferredSize
} // extern "C"
