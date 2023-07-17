#include <revolution/arc.h>

EXTERN_TEXT(
  0x80124500, //
  bool ARCInitHandle(void* arcStart, ARCHandle* handle)
);

EXTERN_TEXT(
  0x801245A0, //
  bool ARCOpen(ARCHandle* handle, const char* fileName, ARCFileInfo* af)
);

EXTERN_TEXT(
  0x80124844, //
  bool ARCFastOpen(ARCHandle* handle, s32 entrynum, ARCFileInfo* af)
);

EXTERN_TEXT(
  0x80124894, //
  s32 ARCConvertPathToEntrynum(ARCHandle* handle, const char* pathPtr)
);

// 0x80124AF8: entryToPath

// UNUSED: ARCEntrynumIsDir

EXTERN_TEXT(
  0x80124CC0, //
  void* ARCGetStartAddrInMem(ARCFileInfo* af)
);

EXTERN_TEXT(
  0x80124CD4, //
  u32 ARCGetStartOffset(ARCFileInfo* af)
);

EXTERN_TEXT(
  0x80124CDC, //
  u32 ARCGetLength(ARCFileInfo* af)
);

EXTERN_TEXT(
  0x80124CE4, //
  bool ARCClose(ARCFileInfo* af)
);

EXTERN_TEXT(
  0x80124CEC, //
  bool ARCChangeDir(ARCHandle* handle, const char* dirName)
);

// UNUSED: ARCGetCurrentDir

EXTERN_TEXT(
  0x80124D44, //
  bool ARCOpenDir(ARCHandle* handle, const char* dirName, ARCDir* dir)
);

EXTERN_TEXT(
  0x80124DC0, //
  bool ARCReadDir(ARCDir* dir, ARCDirEntry* dirent)
);

EXTERN_TEXT(
  0x80124E78, //
  bool ARCCloseDir(ARCDir* dir)
);
