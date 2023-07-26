#include "eggDvdFile.h"

namespace EGG
{

EXTERN_TEXT(
  0x8022235C, //
  DvdFile::DvdFile()
);

EXTERN_TEXT(
  0x802223A0, //
  DvdFile::~DvdFile()
);

EXTERN_TEXT(
  0x80222470, //
  bool DvdFile::open(int entryNum)
);

EXTERN_TEXT(
  0x802224E8, //
  bool DvdFile::open(const char* path)
);

EXTERN_TEXT(
  0x80222530, //
  bool DvdFile::open(const char* path, void* param_2)
);

EXTERN_TEXT(
  0x80222540, //
  void DvdFile::close()
);

EXTERN_TEXT(
  0x8022259C, //
  s32 DvdFile::readData(void* data, s32 len, s32 offset)
);

EXTERN_TEXT(
  0x80222660, //
  s32 DvdFile::writeData(const void* data, s32 len, s32 offset)
);

EXTERN_TEXT(
  0x802226D0, //
  s32 DvdFile::getFileSize() const
);

} // namespace EGG
