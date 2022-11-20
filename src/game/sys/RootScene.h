#pragma once

#include <host_sys/Scene.h>

namespace sys
{

class RootScene : public host_sys::Scene
{
public:
    static RootScene* s_instance;

private:
    u8 _C70[0xCB8 - 0xC70];
};

static_assert(sizeof(RootScene) == 0xCB8);

} // namespace sys
