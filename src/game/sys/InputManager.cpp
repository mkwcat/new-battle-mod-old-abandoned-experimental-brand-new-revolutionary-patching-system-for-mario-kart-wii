#include "InputManager.h"

REPLACE(0x805242D8, void sys::InputManager::Init())
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

        UNDEF_80521554(&m_playerInputs[i], &m_wiiPads[i], nullptr);
        m_playerInputs[i].m_controller3 = m_playerInputs[i].m_controller;
        UNDEF_80522364(
          m_playerInputs[i].m_unk_0xC8, m_playerInputs[i].m_controller
        );
    }

    // Note: We skip dummy controller initialization for now. This also allows
    // us to use GameCube controllers by default in race (for debugging).
}
