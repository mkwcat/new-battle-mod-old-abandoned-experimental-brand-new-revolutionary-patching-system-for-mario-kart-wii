#pragma once

namespace ui
{

class GlobalContext
{
public:
    EXTERN_TEXT(0x805E2F60, GlobalContext());

private:
    u8 fill[0x510];
};

static_assert(sizeof(GlobalContext) == 0x510);

} // namespace ui
