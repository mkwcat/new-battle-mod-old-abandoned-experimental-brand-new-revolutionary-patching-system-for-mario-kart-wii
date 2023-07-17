#pragma once

typedef struct {
    FILL(0x0, 0x8);
    int fstSize;
    int fileStart;
    FILL(0x10, 0x20);
} ARCHeader;

static_assert(sizeof(ARCHeader) == 0x20);

typedef struct {
    FILL(0x0, 0x4);
    void* FSTStart;
    FILL(0x8, 0xC);
    u32 entryNum;
    FILL(0x10, 0x1C);
} ARCHandle;

static_assert(sizeof(ARCHandle) == 0x1C);

typedef struct {
    ARCHandle* handle;
    u32 startOffset;
    u32 length;
} ARCFileInfo;

static_assert(sizeof(ARCFileInfo) == 0xC);

typedef struct {
    ARCHandle* handle;
    u32 entryNum;
    u32 location;
    u32 next;
} ARCDir;

static_assert(sizeof(ARCDir) == 0x10);

typedef struct {
    FILL(0x0, 0x4);
    u32 entryNum;
    bool isDir;
    char* name;
} ARCDirEntry;

static_assert(sizeof(ARCDirEntry) == 0x10);

extern "C" {

bool ARCInitHandle(void* arcStart, ARCHandle* handle);

bool ARCOpen(ARCHandle* handle, const char* fileName, ARCFileInfo* af);

bool ARCFastOpen(ARCHandle* handle, s32 entrynum, ARCFileInfo* af);

s32 ARCConvertPathToEntrynum(ARCHandle* handle, const char* pathPtr);

void* ARCGetStartAddrInMem(ARCFileInfo* af);

u32 ARCGetStartOffset(ARCFileInfo* af);

u32 ARCGetLength(ARCFileInfo* af);

bool ARCClose(ARCFileInfo* af);

bool ARCChangeDir(ARCHandle* handle, const char* dirName);

bool ARCOpenDir(ARCHandle* handle, const char* dirName, ARCDir* dir);

bool ARCReadDir(ARCDir* dir, ARCDirEntry* dirent);

bool ARCCloseDir(ARCDir* dir);
}
