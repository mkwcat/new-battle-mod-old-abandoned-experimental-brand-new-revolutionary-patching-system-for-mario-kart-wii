#pragma once

namespace ui
{

class RegisteredPadManager
{
public:
    EXTERN_TEXT(0x8061AE6C, RegisteredPadManager());
    EXTERN_TEXT(0x8061AE7C, ~RegisteredPadManager());

    EXTERN_TEXT(0x8061AEBC, void Init());
    EXTERN_TEXT(0x8061AF20, void Calc());
    EXTERN_TEXT(0x8061B358, u32 GetFlags(s32 localPlayerId));

private:
    u8 _00[0x5C - 0x00];
};

static_assert(sizeof(RegisteredPadManager) == 0x5C);

} // namespace ui
