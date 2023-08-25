// System/RaceInfo.cpp
// MKW: 0x8052D96C - 0x80532084
//
// Decompiled by vabold
// https://github.com/riidefi/mkw/blob/master/source/game/system/RaceConfig.cpp

#include "RaceInfo.h"

namespace System
{

EXTERN_DATA(
  0x809BD728, //
  RaceInfoManager* RaceInfoManager::s_instance
);

EXTERN_TEXT(
  0x8052D96C, //
  RaceInfoPlayer::RaceInfoPlayer()
);

EXTERN_TEXT(
  0x8052DAF0, //
  u32 RaceInfoPlayer::ComputeGPRank()
);

EXTERN_TEXT(
  0x8052DBC8, //
  RaceInfo::RaceInfo()
);

EXTERN_TEXT(
  0x8052DCA8, //
  void RaceInfo::ComputeWinningTeam()
);

// 0x8052DD18: RaceInfoPlayer::ETeam RaceInfoPlayer::GetTeam() const

// 0x8052DD20: const RaceInfoPlayer* RaceInfo::GetPlayer(s32 playerIndex) const

// 0x8052DD30: u8 RaceInfoManager::GetPlayerCount()

EXTERN_TEXT(
  0x8052DD40, //
  void RaceInfoManager::Init()
);

// 0x8052E42C: void RaceInfoPlayer::SetCharacter(s32 characterId)

// 0x8052E434: RaceInfoPlayer* RaceInfo::GetPlayer(s32 playerIndex)

// 0x8052E444: void RaceInfoPlayer::SetVehicle(s32 vehicleId)

// 0x8052E44C: void RaceInfoPlayer::SetType(RaceInfoPlayer::EPlayerType type)

EXTERN_TEXT(
  0x8052E454, //
  void RaceInfoManager::Reset()
);

EXTERN_TEXT(
  0x8052E640, //
  void RaceInfoPlayer::Reset()
);

// 0x8052E658: void RaceInfoPlayer::SetStartPosition(u8 pos)

// 0x8052E660: void RaceInfoPlayer::SetGPRank(u8 rank)

EXTERN_TEXT(
  0x8052E668, //
  void RaceInfo::Reset()
);

// 0x8052E764: Unused empty function
// 0x8052E768: Unused empty function
// 0x8052E76C: Unused empty function

EXTERN_TEXT(
  0x8052E770, //
  u8 RaceInfo::NextRace()
);

EXTERN_TEXT(
  0x8052E870, //
  s32 RaceInfoManager::GetUpdatedRating(u8 playerId)
);

EXTERN_TEXT(
  0x8052E950, //
  void RaceInfo::UpdatePoints()
);

// 0x8052ED18: RaceInfo::ECameraMode RaceInfo::GetCameraMode()

// 0x8052ED20: RaceInfoPlayer::EPlayerType RaceInfoPlayer::GetType()

EXTERN_TEXT(
  0x8052ED28, //
  void RaceInfo::PostPlayersSetupInputs(RaceInfo* prev)
);

EXTERN_TEXT(
  0x8052EEF0, //
  void RaceInfo::SetupGhost(u8 playerId, u8 inputIndex)
);

EXTERN_TEXT(
  0x8052EFD4, //
  void RaceInfo::PlayersReset()
);

EXTERN_TEXT(
  0x8052EFD4, //
  void RaceInfo::PlayersSetup()
);

EXTERN_TEXT(
  0x8052F1E0, //
  void RaceInfo::PlayersSetupStartOrder()
);

EXTERN_TEXT(
  0x8052F4E8, //
  void RaceInfo::PlayersSetupInputs(u8 screenCount)
);

EXTERN_TEXT(
  0x8052F788, //
  void RaceInfo::PlayersComputeCount(
    u8* playerCount, u8* screenCount, u8* localPlayerCount
  )
);

EXTERN_TEXT(
  0x8052F924, //
  void RaceInfo::SetupRNGSeed()
);

EXTERN_TEXT(
  0x8052FA0C, //
  void RaceInfo::SetupCompetitionInfo()
);

REPLACE(
  0x8052FB90, //
  void RaceInfo::SetupRace(RaceInfo* prev)
)
{
    if (GetIsCompetition()) {
        SetupCompetitionInfo();
    }

    PlayersSetupStartOrder();

    for (u8 i = 0; i < 12; i++) {
        RaceInfoPlayer* player = GetPlayer(i);
        player->m_screenId = -1;
        player->m_inputIndex = -1;
    }

    for (u8 i = 0; i < 4; i++) {
        m_screenPlayerIds[i] = -1;
    }

    u8 playerCount = 0;
    u8 screenCount = 0;
    u8 localPlayerCount = 0;
    PlayersComputeCount(&playerCount, &screenCount, &localPlayerCount);

    u8 screenCountRace = screenCount;

    if (m_cameraMode == CAMERA_MODE_GAMEPLAY_INTRO) {
        screenCount = 1;
    }

    if (m_raceNum == 0 && !IsWiFiMode()) {
        for (u8 i = 0; i < playerCount; i++) {
            RaceInfoPlayer* player = GetPlayer(i);
            player->m_prevScore = 0;
            player->SetStartPosition(playerCount - i);
            player->SetGPRank(playerCount - i);
        }
    }

    PlayersSetupInputs(screenCount);
    PostPlayersSetupInputs(prev);
    SetupRNGSeed();

    m_playerCount = playerCount;
    m_screenCount = screenCount;
    m_screenCountRace = screenCountRace;
    m_localPlayerCount = localPlayerCount;

    if (IsBattle()) {
        switch (m_battleMode) {
        case BATTLE_MODE_BALLOON:
            m_legacyBattleMode = BATTLE_MODE_BALLOON;
            break;

        case BATTLE_MODE_COIN:
            m_legacyBattleMode = BATTLE_MODE_COIN;
            break;

        case BATTLE_MODE_SHINE_THIEF:
            m_legacyBattleMode = BATTLE_MODE_COIN;
            break;
        }
    }
}

// This is so our new fields get copied
REPLACE(
  0x805302C4, //
  void RaceInfoManager::SetupRace()
)
{
    m_infoNext.SetupRace(&m_info);
    m_info = m_infoNext;
}

} // namespace System
