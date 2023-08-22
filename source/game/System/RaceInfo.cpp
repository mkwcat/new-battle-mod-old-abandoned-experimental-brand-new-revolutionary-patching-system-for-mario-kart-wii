#include "RaceInfo.h"

EXTERN_DATA(
  0x809BD728, //
  System::RaceInfoManager* System::RaceInfoManager::s_instance
);

// This is so our new fields get copied
REPLACE(
  0x805302C4, //
  void System::RaceInfoManager::InitRace()
)
{
    m_infoNext.InitRace(&m_info);
    m_info = m_infoNext;

    switch (m_infoNext.m_battleMode) {
    case RaceInfo::BATTLE_BALLOON:
        m_info.m_legacyBattleMode = RaceInfo::BATTLE_BALLOON;
        break;

    case RaceInfo::BATTLE_COIN:
        m_info.m_legacyBattleMode = RaceInfo::BATTLE_COIN;
        break;

    case RaceInfo::BATTLE_SHINE_THIEF:
        m_info.m_legacyBattleMode = RaceInfo::BATTLE_COIN;
        break;
    }
}
