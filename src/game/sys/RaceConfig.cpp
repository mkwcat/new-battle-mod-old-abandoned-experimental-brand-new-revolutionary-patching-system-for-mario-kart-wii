#include "RaceConfig.h"

EXTERN_DATA(0x809BD728, sys::RaceConfig* sys::RaceConfig::s_instance);

// This is so our new fields get copied
REPLACE(0x805302C4, void sys::RaceConfig::InitRace())
{
    m_nextRace.InitRace(&m_currentRace);
    m_currentRace = m_nextRace;

    switch (m_nextRace.m_battleMode) {
    case RaceSetting::BATTLE_BALLOON:
        m_currentRace.m_legacyBattleMode = RaceSetting::BATTLE_BALLOON;

    case RaceSetting::BATTLE_COIN:
        m_currentRace.m_legacyBattleMode = RaceSetting::BATTLE_COIN;

    case RaceSetting::BATTLE_SHINE_THIEF:
        m_currentRace.m_legacyBattleMode = RaceSetting::BATTLE_COIN;
    }
}
