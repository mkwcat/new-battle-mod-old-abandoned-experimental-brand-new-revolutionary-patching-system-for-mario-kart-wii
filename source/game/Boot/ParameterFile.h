#pragma once

namespace Boot
{

class ParameterFile
{
public:
    /* 0x80009C8C */
    ParameterFile();

    /* 0x80009CE0 */
    virtual ~ParameterFile();

    /* 0x80009DDC */
    virtual void Read(EGG::Heap* heap);

    // Emitted in Boot/ParameterFile.cpp
    EXTERN_TEXT_INLINE(
      0x80009F58, //
      virtual void VT_0x10()
    )
    {
    }

    // Emitted in Boot/ParameterFile.cpp
    EXTERN_TEXT_INLINE(
      0x80009F54, //
      virtual void VT_0x14()
    )
    {
    }

    // Emitted in Boot/ParameterFile.cpp
    EXTERN_TEXT_INLINE(
      0x80009F50, //
      virtual void VT_0x18()
    )
    {
    }

private:
    FILL(0x04, 0x1C);
};

static_assert(sizeof(ParameterFile) == 0x1C);

} // namespace Boot
