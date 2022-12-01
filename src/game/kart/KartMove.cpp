#include "KartMove.h"
#include "KartBlink.h"
#include "game/sys/RaceConfig.h"
#include "game/sys/RaceManager.h"

EXTERN_REPL(0x805799AC, void kart::KartMove::ActivateRespawn());

REPLACE(0x805799AC, void kart::KartMove::Respawn())
{
    auto state = m_accessor->m_state;

    if (state->b_OnlineRemote)
        return;

    if (state->b_PostBattleSideline) {
        state->b_PreRespawn = 1;
        return;
    }

    ActivateRespawn();
}

REPLACE(0x80581824, void kart::KartMove::BattleFlagsUpdate())
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

    if (sys::RaceConfig::s_instance->m_currentRace.m_legacyBattleMode ==
          sys::RaceConfig::RaceSetting::BATTLE_BALLOON &&
        state->b_BattleSideline && !state->b_OnlineRemote &&
        (m_battleVanishTimer++ > 60)) {
        // Make the player shrink and disappear
        if (!state->b_HasStoppedB2 && !state->b_HasVanished) {
            state->b_HasStoppedB2 = 1;
        }

        // Remove the player's map icon and name tag
        sys::RaceManager::s_instance->m_players[GetPlayerID()]->m_flags |= 0x10;

        m_battleVanishTimer = 0;
        state->b_BattleSideline = 0;
        state->b_PostBattleSideline = 1;
    }
}
