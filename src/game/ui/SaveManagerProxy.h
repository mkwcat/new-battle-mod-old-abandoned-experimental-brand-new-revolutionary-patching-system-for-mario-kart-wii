#pragma once

namespace UI
{

class SaveManagerProxy
{
public:
    EXTERN_TEXT(0x806209E8, SaveManagerProxy());
    EXTERN_TEXT(0x80620B04, void Init());
    EXTERN_TEXT(0x80620C5C, s32 GetErrorSection());

private:
    u8 fill[0x128];
};

static_assert(sizeof(SaveManagerProxy) == 0x128);

} // namespace UI
