#pragma once

#include <egg/core/eggHeap.h>
#include <host_sys/Scene.h>

namespace sys
{

class RootScene : public host_sys::Scene
{
public:
    static RootScene* s_instance;

    void Allocate(); // Replaced 0x80542D4C

private:
    FILL(0xC70, 0xC78);
    EGG::Heap* m_soundHeap;
    FILL(0xC7C, 0xCB8);
};

static_assert(sizeof(RootScene) == 0xCB8);

} // namespace sys
