#include "RaceManager.h"
#include "RaceConfig.h"
#include <Kart/KartMove.h>
#include <Kart/KartObjectManager.h>
#include <Object/BattleBalloon.h>

namespace System
{

EXTERN_DATA(
  0x809BD730, //
  RaceManager* System::RaceManager::s_instance
);

REPLACE(
  0x80538770, //
  void RaceManager::BalloonBattle::PlayerHitByPlayer(
    u32 attackerId, u32 targetId
  )
)
{
    // Don't run if the battle is already over
    if (RaceManager::s_instance->HasReachedStage(4))
        return;

    auto balloonMgr = Object::BattleBalloonMgr::s_instance;

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
        Kart::KartObjectManager::s_instance->GetObject(targetId)
          ->GetKartMove()
          ->BattleSideline();
    }
}

REPLACE(
  0x80538BC0, //
  void RaceManager::BalloonBattle::PlayerFallOutOfBounds(u32 targetId)
)
{
    // Don't run if the battle is already over
    if (RaceManager::s_instance->HasReachedStage(4))
        return;

    auto balloonMgr = Object::BattleBalloonMgr::s_instance;

    // Don't run if the player has no balloons
    if (balloonMgr->m_playerData[targetId].m_count == 0)
        return;

    balloonMgr->PopBalloons(targetId, 1, 1, 0, 1, 0);

    if (balloonMgr->m_playerData[targetId].m_count == 0) {
        Kart::KartObjectManager::s_instance->GetObject(targetId)
          ->GetKartMove()
          ->BattleSideline();
    }
}

REPLACE(
  0x80538CE0, //
  void RaceManager::BalloonBattle::PlayerHitByObject(u32 targetId)
)
{
    // Don't run if the battle is already over
    if (RaceManager::s_instance->HasReachedStage(4))
        return;

    auto balloonMgr = Object::BattleBalloonMgr::s_instance;

    // Don't run if the player has no balloons
    if (balloonMgr->m_playerData[targetId].m_count == 0)
        return;

    balloonMgr->PopBalloons(targetId, 0, 1, 0, 1, 0);

    if (balloonMgr->m_playerData[targetId].m_count == 0) {
        Kart::KartObjectManager::s_instance->GetObject(targetId)
          ->GetKartMove()
          ->BattleSideline();
    }
}

REPLACE(
  0x80538E00, //
  void RaceManager::BalloonBattle::SidelinePlayer(u8 playerId)
)
{
}

} // namespace System
