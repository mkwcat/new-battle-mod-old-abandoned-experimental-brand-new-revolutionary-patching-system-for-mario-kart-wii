#include "RaceModeBattleBalloon.h"
#include "RaceConfig.h"
#include "RaceManager.h"
#include "game/kart/KartMove.h"
#include "game/kart/KartObjectManager.h"
#include "game/object/BattleBalloon.h"

REPLACE(
  0x80538770, void sys::RaceModeBattleBalloon::PlayerHitByPlayer(
                u32 attackerId, u32 targetId
              )
)
{
    // Don't run if the battle is already over
    if (RaceManager::s_instance->HasReachedStage(4))
        return;

    auto balloonMgr = object::BattleBalloonMgr::s_instance;

    // Don't run if the player has no balloons
    if (balloonMgr->m_playerData[targetId].m_count == 0)
        return;

    auto currentRace = &RaceConfig::s_instance->m_currentRace;

    if (currentRace->m_modeFlags & RaceConfig::RaceSetting::FLAG_TEAMS) {
        // Check to see if the attacker and target are on the same team.
        if (currentRace->m_players[attackerId].m_team ==
            currentRace->m_players[targetId].m_team)
            return;
    }

    balloonMgr->PopBalloons(targetId, 0, 1, 0, 1, 0);

    if (balloonMgr->m_playerData[targetId].m_count == 0) {
        kart::KartObjectManager::s_instance->GetObject(targetId)
          ->GetKartMove()
          ->BattleSideline();
    }
}

REPLACE(
  0x80538CE0, void sys::RaceModeBattleBalloon::PlayerHitByObject(u32 targetId)
)
{
    // Don't run if the battle is already over
    if (RaceManager::s_instance->HasReachedStage(4))
        return;

    auto balloonMgr = object::BattleBalloonMgr::s_instance;

    // Don't run if the player has no balloons
    if (balloonMgr->m_playerData[targetId].m_count == 0)
        return;

    balloonMgr->PopBalloons(targetId, 0, 1, 0, 1, 0);

    if (balloonMgr->m_playerData[targetId].m_count == 0) {
        kart::KartObjectManager::s_instance->GetObject(targetId)
          ->GetKartMove()
          ->BattleSideline();
    }
}

REPLACE(
  0x80538E00, void sys::RaceModeBattleBalloon::SidelinePlayer(u8 playerId)
)
{
    // Don't run if the battle is already over
    if (RaceManager::s_instance->HasReachedStage(4))
        return;

    auto balloonMgr = object::BattleBalloonMgr::s_instance;

    balloonMgr->PopBalloons(
      playerId, 0, 1, 0, balloonMgr->m_playerData[playerId].m_count, 0
    );

    RaceManager::s_instance->UNDEF_80533d84(playerId);
    RaceManager::s_instance->m_players[playerId]->m_flags |= 0x10;
#if 0
    RaceManager::s_instance->EndPlayerRace(playerId);
    RaceManager::s_instance->UNDEF_80533d84(playerId);

    // RaceManager::s_instance->m_stage = 3;
#endif
}
