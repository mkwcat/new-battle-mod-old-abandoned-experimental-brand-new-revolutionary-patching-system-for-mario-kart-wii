#include "SystemMessageGroup.h"
#include <Boot/SystemManager.h>

namespace UI
{

INCBIN("game/ui/msg/System_E.bmg", SystemMsg_E);
INCBIN("game/ui/msg/System_F.bmg", SystemMsg_F);
INCBIN("game/ui/msg/System_G.bmg", SystemMsg_G);
INCBIN("game/ui/msg/System_I.bmg", SystemMsg_I);
INCBIN("game/ui/msg/System_J.bmg", SystemMsg_J);
INCBIN("game/ui/msg/System_K.bmg", SystemMsg_K);
INCBIN("game/ui/msg/System_M.bmg", SystemMsg_M);
INCBIN("game/ui/msg/System_Q.bmg", SystemMsg_Q);
INCBIN("game/ui/msg/System_S.bmg", SystemMsg_S);
INCBIN("game/ui/msg/System_U.bmg", SystemMsg_U);

void SystemMessageGroup::LoadP()
{
    switch (Boot::SystemManager::s_instance->m_language) {
    default:
    case Boot::SystemManager::Language::English:
        MessageGroup::Load(SystemMsg_E);
        break;

    case Boot::SystemManager::Language::German:
        MessageGroup::Load(SystemMsg_G);
        break;

    case Boot::SystemManager::Language::French:
        MessageGroup::Load(SystemMsg_F);
        break;

    case Boot::SystemManager::Language::Spanish:
        MessageGroup::Load(SystemMsg_S);
        break;

    case Boot::SystemManager::Language::Italian:
        MessageGroup::Load(SystemMsg_I);
        break;
    }
}

void SystemMessageGroup::LoadE()
{
    switch (Boot::SystemManager::s_instance->m_language) {
    default:
    case Boot::SystemManager::Language::English:
        MessageGroup::Load(SystemMsg_U);
        break;

    case Boot::SystemManager::Language::French:
        MessageGroup::Load(SystemMsg_Q);
        break;

    case Boot::SystemManager::Language::Spanish:
        MessageGroup::Load(SystemMsg_M);
        break;
    }
}

void SystemMessageGroup::LoadJ()
{
    MessageGroup::Load(SystemMsg_J);
}

void SystemMessageGroup::LoadK()
{
    MessageGroup::Load(SystemMsg_K);
    // TODO: Chinese?
}

// We don't need to replace the function as we replace the only call to it. For
// reference the address is at 0x80637A20.
void SystemMessageGroup::Load()
{
    switch (GetCodeRegion()) {
    default:
    case Region::P:
        LoadP();

    case Region::E:
        LoadE();

    case Region::J:
        LoadJ();

    case Region::K:
        LoadK();
    }
}

} // namespace UI
