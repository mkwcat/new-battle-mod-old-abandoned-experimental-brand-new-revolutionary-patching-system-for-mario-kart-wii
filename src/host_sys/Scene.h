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

    EGG::Heap* heaps[3];

private:
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
