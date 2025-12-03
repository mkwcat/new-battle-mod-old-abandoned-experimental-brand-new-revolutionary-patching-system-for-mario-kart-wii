#include "ParameterFile.h"

namespace Boot
{

EXTERN_TEXT(
  0x80009C8C, //
  ParameterFile::ParameterFile()
);

EXTERN_TEXT(
  0x80009CE0, //
  ParameterFile::~ParameterFile()
);

EXTERN_TEXT(
  0x80009DDC, //
  void ParameterFile::Read(EGG::Heap* heap)
);

} // namespace Boot
