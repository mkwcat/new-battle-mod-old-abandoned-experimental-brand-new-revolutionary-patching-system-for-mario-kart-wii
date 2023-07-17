#pragma once

namespace Net
{

class NetManager
{
public:
    EXTERN_TEXT(0x80655B24, static NetManager* CreateInstance());

    FILL(0x0, 0x29C8);
};

static_assert(sizeof(NetManager) == 0x29C8);

} // namespace Net
