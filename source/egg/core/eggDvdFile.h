#pragma once

#include "eggFile.h"
#include <revolution/dvd.h>

namespace EGG
{

class DvdFile : public File
{
public:
    /* 0x8022235C */
    DvdFile();

    /* 0x802223A0 */
    virtual ~DvdFile();

    /* 0x80222470 */
    virtual bool open(int entryNum);

    /* 0x802224E8 */
    virtual bool open(const char* path);

    /* 0x80222530 */
    virtual bool open(const char* path, void* param_2);

    /* 0x80222540 */
    virtual void close();

    /* 0x8022259C */
    virtual s32 readData(void* data, s32 len, s32 offset);

    /* 0x80222660 */
    virtual s32 writeData(const void* data, s32 len, s32 offset);

    /* 0x802226D0 */
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
