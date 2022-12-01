#pragma once

#include <egg/core/eggHeap.h>
#include <egg/core/eggScene.h>

namespace host_sys
{

class Scene : public EGG::Scene
{
public:
    Scene();
    ~Scene() override;

    class HeapCollection
    {
    public:
        EXTERN_TEXT(0x80009BC0, void SetGroupIDAll(u32 groupId));

        EGG::Heap* m_heaps[3];
    };

public:
    HeapCollection m_heaps;

    u8 _03C[0xC70 - 0x03C];
};

static_assert(sizeof(Scene) == 0xC70);

enum class SceneID {
    // --- <SceneCreatorREL>
    Title = 0, //!< Called when REL first loaded
    Menu = 1, //!< "メニューシーン" -> "Menu Scene"
    Race = 2, //!< "レースシーン" -> "Race Scene"
    Globe = 4, //!< "地球儀シーン" -> "Globe Scene"

    // --- <SceneCreatorStatic>
    Strap = 5, //!< Root scene loaded immediately after initializing the system.
    // --- </SceneCreatorStatic>

    FlagOpen = 12, //!< "フラグオープンシーン" -> "Flag Open Scene"
    // --- </SceneCreatorREL>
};

} // namespace host_sys
