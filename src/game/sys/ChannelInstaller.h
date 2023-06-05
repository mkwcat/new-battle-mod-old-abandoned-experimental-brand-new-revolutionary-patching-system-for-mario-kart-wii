#pragma once

namespace sys
{

class ChannelInstaller
{
public:
    EXTERN_TEXT(
      0x80510468, //
      static ChannelInstaller* CreateInstance()
    );

    FILL(0x0, 0x7C);
};

static_assert(sizeof(ChannelInstaller) == 0x7C);

} // namespace sys
