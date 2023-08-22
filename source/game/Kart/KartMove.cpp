#include "KartMove.h"
#include "KartBlink.h"
#include <System/RaceInfo.h>
#include <System/RaceManager.h>

namespace Kart
{

struct JumpPadParam {
    f32 m_minSpeed;
    f32 m_maxSpeed;
    f32 m_velY;
};

INSERT_DATA(
  0x808B5BD0, 0x60, //
  JumpPadParam s_jumpPadParam[8] = {
    /* 00 */ {50.0, 50.0, 35.0},
    /* 01 */ {50.0, 50.0, 47.0},
    /* 02 */ {59.0, 59.0, 30.0},
    /* 03 */ {73.0, 73.0, 45.0},
    /* 04 */ {73.0, 73.0, 53.0},
    /* 05 */ {56.0, 56.0, 50.0},
    /* 06 */ {55.0, 55.0, 35.0},
    /* 07 */ {85.0, 85.0, 75.0}, // Modified for the Feather item
  }
);

EXTERN_TEXT(
  0x805799AC, //
  void KartMove::StartRespawn()
);

void KartMove::StartFeatherJump()
{
    m_specialFloor |= SPECIAL_FLOOR_JUMP_PAD;

    auto kartState = GetKartState();

    if (kartState->b_Unknown1_14) {
        kartState->m_jumpPadType = 2;
    } else {
        kartState->m_jumpPadType = 7;
    }

    GetKartSound()->PlayDashSound();
    PlayVoiceSe(0x6);
}

EXTERN_TEXT(
  0x80581778, //
  void KartMove::BattleSideline()
);

REPLACE(
  0x80581824, //
  void KartMove::BattleFlagsUpdate()
)
{
    auto state = m_accessor->m_state;

    if (state->b_Blinking) {
        m_battleBlinkTimer--;

        if (m_battleBlinkTimer < 1) {
            state->b_Blinking = 0;
            GetKartBlink()->Calc(1);
        } else {
            GetKartBlink()->Calc(0);
        }
    }

    if (System::RaceInfoManager::s_instance->m_info.IsBalloonBattle() &&
        state->b_BattleSideline && !state->b_OnlineRemote) {
        // Increase to 90 frames if it's an out of bounds sideline. This is to
        // prevent the player shrink from occurring before the balloon actually
        // pops.
        u32 vanishDelay = state->b_PreRespawn ? 90 : 70;
        if (m_battleVanishTimer++ > vanishDelay) {
            // Make the player shrink and disappear
            if (!state->b_HasStoppedB2 && !state->b_HasVanished) {
                state->b_HasStoppedB2 = 1;
            }

            // Remove the player's map icon and name tag
            System::RaceManager::s_instance->m_players[GetPlayerID()]
              ->m_flags |= 0x10;

            m_battleVanishTimer = 0;
            state->b_BattleSideline = 0;
            state->b_PostBattleSideline = 1;
        }
    }
}

} // namespace Kart
