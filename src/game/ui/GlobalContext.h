#pragma once

namespace ui
{

class GlobalContext
{
public:
    EXTERN_TEXT(
      0x805E2F60, //
      GlobalContext()
    );

private:
    u8 _0[0x4E8 - 0x0];

public:
    u8 m_licenseId;

private:
    u8 _4E9[0x510 - 0x4E9];
};

static_assert(sizeof(GlobalContext) == 0x510);

} // namespace ui
