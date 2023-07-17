#pragma once

#include <revolution/arc.h>

extern "C" {

typedef struct {
    FILL(0x00, 0x0C);
    s32 state;
    FILL(0x10, 0x30);
} DVDCommandBlock;

static_assert(sizeof(DVDCommandBlock) == 0x30);

typedef struct {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    void* callback;
} DVDFileInfo;

static_assert(sizeof(DVDFileInfo) == 0x3C);

void __DVDEXInit(s32 arcEntryNum, ARCHandle* arcHandle);

bool DVDFastOpen(s32 entryNum, DVDFileInfo* fileInfo);

bool DVDOpen(const char* fileName, DVDFileInfo* fileInfo);

bool DVDClose(DVDFileInfo* fileInfo);

s32 DVDReadPrio(
  DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32 prio
);

#define DVDRead(fileInfo, addr, length, offset)                                \
  DVDReadPrio((fileInfo), (addr), (length), (offset), 2)

s32 DVDConvertPathToEntrynum(const char* fileName);
}
