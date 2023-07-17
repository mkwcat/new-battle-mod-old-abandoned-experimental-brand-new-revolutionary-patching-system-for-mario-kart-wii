#pragma once

#include "eggFile.h"
#include <revolution/dvd.h>

namespace EGG
{

class DvdFile : public File
{
public:
    DvdFile();
    virtual ~DvdFile();

    virtual bool open(int entryNum);
    virtual bool open(const char* path);
    virtual bool open(const char* path, void* param_2);
    virtual void close();
    virtual s32 readData(void* data, s32 len, s32 offset);
    virtual s32 writeData(const void* data, s32 len, s32 offset);
    virtual s32 getFileSize() const;

public:
    /* 0x4 */ bool m_isOpen;

    FILL(0x8, 0x3C);

    /* 0x3C */ DVDFileInfo m_fileInfo;
    /* 0x78 */ DvdFile* m_dvdFile; // Pointer to itself?

    FILL(0x7C, 0xF4);
};

static_assert(sizeof(EGG::DvdFile) == 0xF4);

} // namespace EGG
