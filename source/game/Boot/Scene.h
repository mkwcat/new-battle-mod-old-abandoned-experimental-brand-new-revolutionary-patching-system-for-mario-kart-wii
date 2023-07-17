#pragma once

#include <egg/core/eggHeap.h>
#include <egg/core/eggScene.h>

namespace Boot
{

class Scene : public EGG::Scene
{
public:
    Scene();
    ~Scene() override;

    class HeapCollection
    {
    public:
        void SetGroupIDAll(u32 groupId);

        EGG::Heap* m_heaps[3];
    };

public:
    HeapCollection m_heaps;

    u8 _03C[0xC70 - 0x03C];
};

static_assert(sizeof(Scene) == 0xC70);

enum class SceneID {
    Title = 0, // Called when REL first loaded
    Menu = 1, // "メニューシーン" -> "Menu Scene"
    Race = 2, // "レースシーン" -> "Race Scene"
    Globe = 4, // "地球儀シーン" -> "Globe Scene"
    Strap = 5, // Root scene loaded immediately after initializing the system.
    FlagOpen = 12, // "フラグオープンシーン" -> "Flag Open Scene"
};

} // namespace Boot
