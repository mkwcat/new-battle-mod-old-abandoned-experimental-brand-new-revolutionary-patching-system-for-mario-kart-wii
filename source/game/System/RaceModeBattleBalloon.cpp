#include "RaceModeBattleBalloon.h"

namespace System
{

REPLACE(
  0x80538770, //
  void RaceModeBattleBalloon::PlayerHitByPlayer(u32 attackerId, u32 targetId)
)
{
    // Don't run if the battle is already over
    if (RaceManager::s_instance->HasReachedStage(4))
        return;

    auto balloonMgr = Object::BattleBalloonMgr::s_instance;

    // Don't run if the player has no balloons
    if (balloonMgr->m_playerData[targetId].m_count == 0)
        return;

    auto currentRace = &RaceInfoManager::s_instance->m_info;

    if (currentRace->m_modeFlags & RaceInfo::FLAG_TEAMS) {
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
  void RaceModeBattleBalloon::PlayerFallOutOfBounds(u32 targetId)
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
  void RaceModeBattleBalloon::PlayerHitByObject(u32 targetId)
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
  void RaceModeBattleBalloon::SidelinePlayer(u8 playerId)
)
{
}

EXTERN_REPL(
  0x80539574, //
  void RaceModeBattleBalloon::CalcBase()
);

REPLACE(
  0x80539574, //
  void RaceModeBattleBalloon::Calc()
)
{
    CalcBase();

    if (m_raceManager->m_stage != 2) {
        return;
    }

    u32 remainingCount = 0;
    u32 otherRemaining = 0;

    auto balloonMgr = Object::BattleBalloonMgr::s_instance;

    for (u32 i = 0; i < Race::ModeInfo::s_modeInfo.m_playerCount; i++) {
        bool remaining = balloonMgr->m_playerData[i].m_count > 0;

        if (remaining) {
            if (Race::ModeInfo::IsImportantPlayer(i)) {
                remainingCount++;
            } else {
                otherRemaining++;
            }
        }
    }

    if (remainingCount == 0) {
        ForceFinish();
    }

    if (remainingCount == 1 && otherRemaining == 0) {
        ForceFinish();
    }

    if (!Race::ModeInfo::s_modeInfo.m_isTeams) {
        return;
    }

    bool redTeam = false;
    bool blueTeam = false;
    auto currentRace = &RaceInfoManager::s_instance->m_info;

    for (u32 i = 0; i < Race::ModeInfo::s_modeInfo.m_playerCount; i++) {
        bool remaining = balloonMgr->m_playerData[i].m_count > 0;

        if (!remaining) {
            continue;
        }

        if (currentRace->m_players[i].m_team == RaceInfoPlayer::TEAM_RED) {
            redTeam = true;
        }

        if (currentRace->m_players[i].m_team == RaceInfoPlayer::TEAM_BLUE) {
            blueTeam = true;
        }

        if (redTeam && blueTeam) {
            break;
        }
    }

    if (!redTeam || !blueTeam) {
        ForceFinish();
    }
}

} // namespace System
