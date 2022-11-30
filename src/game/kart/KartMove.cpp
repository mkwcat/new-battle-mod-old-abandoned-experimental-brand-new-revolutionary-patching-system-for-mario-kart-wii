#include "KartMove.h"
#include "KartBlink.h"
#include "game/sys/RaceConfig.h"
#include "game/sys/RaceManager.h"

EXTERN_REPL(0x805799AC, void kart::KartMove::ActivateRespawn());

REPLACE(0x805799AC, void kart::KartMove::Respawn())
{
    auto state = m_accessor->m_state;

    if (state->m_flags4 & KartState::FLAGS4_ONLINE_REMOTE)
        return;

    if (state->m_flags4 & KartState::FLAGS4_POST_BATTLE_SIDELINE) {
        state->m_flags0 |= KartState::FLAGS0_PRE_RESPAWN;
        return;
    }

    ActivateRespawn();
}

REPLACE(0x80581824, void kart::KartMove::BattleFlagsUpdate())
{
    auto state = m_accessor->m_state;

    if (state->m_flags1 & KartState::FLAGS1_BLINKING) {
        m_battleBlinkTimer--;

        if (m_battleBlinkTimer < 1) {
            state->m_flags1 &= ~KartState::FLAGS1_BLINKING;
            GetKartBlink()->Calc(1);
        } else {
            GetKartBlink()->Calc(0);
        }
    }

    if (sys::RaceConfig::s_instance->m_currentRace.m_legacyBattleMode ==
          sys::RaceConfig::RaceSetting::BATTLE_BALLOON &&
        (state->m_flags4 & KartState::FLAGS4_BATTLE_SIDELINE) &&
        !(state->m_flags4 & KartState::FLAGS4_ONLINE_REMOTE)) {
        //!(state->m_flags0 & KartState::FLAGS0_PRE_RESPAWN) &&
        //!(state->m_flags2 & KartState::FLAGS2_MAYBE_POST_RESPAWN) &&
        //!(state->m_flags2 & KartState::FLAGS2_MAYBE_POST_RESPAWN2) &&
        if (m_battleVanishTimer++ > 60) {
            // Make the player shrink and disappear
            if (!(state->m_flags2 & (KartState::FLAGS2_HAS_STOPPED |
                                      KartState::FLAGS2_HAS_VANISHED))) {
                state->m_flags2 |= KartState::FLAGS2_HAS_STOPPED;
            }

            // Remove the player's map icon and name tag
            sys::RaceManager::s_instance->m_players[GetPlayerID()]->m_flags |=
              0x10;

            m_battleVanishTimer = 0;
            state->m_flags4 &= ~KartState::FLAGS4_BATTLE_SIDELINE;
            state->m_flags4 |= KartState::FLAGS4_POST_BATTLE_SIDELINE;
        }
    }
}
