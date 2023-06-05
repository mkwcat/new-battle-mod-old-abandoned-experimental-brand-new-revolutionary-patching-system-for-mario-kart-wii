#include "InputManager.h"
#include <game/ui/SectionManager.h>

REPLACE(
  0x805242D8, //
  void sys::InputManager::Init()
)
{
    extern void
    UNDEF_80521554(PlayerInput*, Pad*, Pad*); // KartInput_setController
    extern void UNDEF_80522364(u8*, Pad*);

    for (u8 i = 0; i < 4; i++) {
        if (!m_wiiPads[i].m_unk_0x50)
            continue;

        UNDEF_80521554(&m_playerInputs[i], &m_wiiPads[i], nullptr);
        m_playerInputs[i].m_controller3 = m_playerInputs[i].m_controller;
        UNDEF_80522364(
          m_playerInputs[i].m_unk_0xC8, m_playerInputs[i].m_controller
        );
    }

    for (u8 i = 0; i < 4; i++) {
        if (!m_gcPads[i].m_unk_0x50)
            continue;

        UNDEF_80521554(&m_playerInputs[i], &m_gcPads[i], nullptr);
        m_playerInputs[i].m_controller3 = m_playerInputs[i].m_controller;
        UNDEF_80522364(
          m_playerInputs[i].m_unk_0xC8, m_playerInputs[i].m_controller
        );
    }

    for (u8 i = 0; i < 4; i++) {
        UNDEF_80521554(&m_playerInputs[i], &m_dummyPad, nullptr);
        m_playerInputs[i].m_controller3 = m_playerInputs[i].m_controller;
        UNDEF_80522364(
          m_playerInputs[i].m_unk_0xC8, m_playerInputs[i].m_controller
        );
    }

    // This will register P1 GameCube controller as the player 1 controller in
    // debug mode
    auto mgr = ui::SectionManager::s_instance;
    if (mgr->m_debugMode) {
        mgr->m_registeredPadManager.ForceRegisterGCN();
        mgr->m_registeredPadManager.UNDEF_8061B5A4();
    }
}
