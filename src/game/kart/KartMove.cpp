#include "KartMove.h"
#include "KartBlink.h"
#include "game/sys/RaceConfig.h"
#include "game/sys/RaceManager.h"

REPLACE(
  0x80581824, //
  void kart::KartMove::BattleFlagsUpdate()
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

    if (sys::RaceConfig::s_instance->m_currentRace.IsBalloonBattle() &&
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
            sys::RaceManager::s_instance->m_players[GetPlayerID()]->m_flags |=
              0x10;

            m_battleVanishTimer = 0;
            state->b_BattleSideline = 0;
            state->b_PostBattleSideline = 1;
        }
    }
}
