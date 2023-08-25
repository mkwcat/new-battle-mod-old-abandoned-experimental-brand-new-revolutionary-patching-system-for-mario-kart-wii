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

    auto info = RaceInfoManager::GetInfo();

    if (info->GetIsTeams()) {
        // Check to see if the attacker and target are on the same team.
        if (info->GetPlayer(attackerId)->GetTeam() == //
            info->GetPlayer(targetId)->GetTeam())
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
    auto info = RaceInfoManager::GetInfo();

    CalcBase();

    if (m_raceManager->m_stage != 2) {
        return;
    }

    u32 remainingCount = 0;
    u32 otherRemaining = 0;

    auto balloonMgr = Object::BattleBalloonMgr::s_instance;

    for (u32 i = 0; i < info->GetPlayerCount(); i++) {
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

    if (!info->GetIsTeams()) {
        return;
    }

    bool redTeam = false;
    bool blueTeam = false;

    for (u32 i = 0; i < info->GetPlayerCount(); i++) {
        bool remaining = balloonMgr->m_playerData[i].m_count > 0;

        if (!remaining) {
            continue;
        }

        if (info->GetPlayer(i)->GetTeam() == RaceInfoPlayer::TEAM_RED) {
            redTeam = true;
        }

        if (info->GetPlayer(i)->GetTeam() == RaceInfoPlayer::TEAM_BLUE) {
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
