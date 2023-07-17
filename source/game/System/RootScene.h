#pragma once

#include <Boot/Scene.h>
#include <egg/core/eggHeap.h>

namespace System
{

class RootScene : public Boot::Scene
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

} // namespace System
