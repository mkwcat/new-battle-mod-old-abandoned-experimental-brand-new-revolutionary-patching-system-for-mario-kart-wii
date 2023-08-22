#pragma once

#include "GhostData.h"

// A class for loading a prm file from the disc, an unused file type
class ParamFile
{
public:
    virtual ~ParamFile();
    u8 _0[0x18 - 0x0];
};

namespace System
{

struct RaceInfoMission {
    enum EMissionType {
        MODE_MINITURBO = 0,
        MODE_LAP_RUN_01 = 1,
        MODE_LAP_RUN_02 = 2,
        MODE_DRIFT = 3,
        MODE_ITEM_BOX = 4,
        MODE_ENEMY_DOWN_01 = 5,
        MODE_ENEMY_DOWN_02 = 6,
        MODE_ENEMY_DOWN_03 = 7,
        MODE_COIN_GET = 8,
        MODE_TO_GATE = 9,
        MODE_ROCKET_START = 10,
        MODE_ITEM_HIT = 11,
        MODE_WHEELIE = 12,
        MODE_SLIPSTREAM = 13
    };

    enum ERankIndex {
        RANK_INDEX_C = 0,
        RANK_INDEX_B = 1,
        RANK_INDEX_A = 2,
        RANK_INDEX_STAR_1 = 3,
        RANK_INDEX_STAR_2 = 4,
        RANK_INDEX_STAR_3 = 5,
        RANK_INDEX_COUNT = 6,
    };

    struct CPUInfo {
        /* 0x00 */ u8 m_courseId;
        /* 0x01 */ u8 m_characterId;
    };

    /* 0x00 */ u16 m_mrId;
    /* 0x02 */ u16 m_type;
    /* 0x04 */ u8 m_courseId;
    /* 0x05 */ u8 m_characterId;
    /* 0x06 */ u8 m_vehicleId;
    /* 0x07 */ u8 m_engineClass;
    /* 0x08 - 0x2C */ u8 _0x08[0x2C - 0x08];
    // Time limit in seconds
    /* 0x2C */ u16 m_timeLimit;
    /* 0x2E */ u8 m_0x2E;
    /* 0x2F */ bool m_forceWiiWheel;
    /* 0x30 */ u32 m_rankScore[RANK_INDEX_COUNT];
    /* 0x48 */ u16 m_cameraAngle;
    /* 0x4A */ u16 m_targetObject;
    /* 0x4C */ u16 m_0x4C;
    /* 0x4E */ u16 m_0x4E;
    /* 0x50 */ u16 m_cannonFlag;
    /* 0x52 */ u16 m_0x52;
    /* 0x54 */ u32 m_0x54;
    /* 0x58 */ u16 m_cpuCount;
    /* 0x5A */ CPUInfo m_cpuInfo[11];
};

static_assert(sizeof(RaceInfoMission) == 0x70);

class RaceInfoPlayer
{
public:
    EXTERN_TEXT(
      0x8052D96C, //
      RaceInfoPlayer()
    );

    EXTERN_TEXT(
      0x8052DC68, //
      virtual ~RaceInfoPlayer()
    );

    EXTERN_TEXT(
      0x8052DAF0, //
      u32 ComputeGPRank()
    );

    enum EPlayerType {
        PLAYER_MASTER,
        PLAYER_CPU,
        PLAYER_UNKNOWN2,
        PLAYER_GHOST,
        PLAYER_REAL_ONLINE,
        PLAYER_NONE
    };

    enum ETeam {
        TEAM_RED,
        TEAM_BLUE,
        TEAM_NONE
    };

    /* 0x04 */ u8 m_0x04;
    /* 0x05 */ u8 m_localPlayerId;
    /* 0x06 */ u8 m_controllerId;
    /* 0x08 */ u32 m_vehicleId;
    /* 0x0C */ u32 m_characterId;
    /* 0x10 */ EPlayerType m_playerType;
    /* 0x14 - 0xCC */ u8 _0x14[0xCC - 0x14];
    /* 0xCC */ ETeam m_team;
    /* 0xD0 - 0xD8 */ u8 _0xD0[0xD8 - 0xD0];
    /* 0xD8 */ u16 m_lastScore;
    /* 0xDA */ u16 m_score;
    /* 0xDC */ u16 m_0xDC;
    /* 0xDE */ u16 m_gpRankScore;
    /* 0xE0 */ u8 m_0xE0;
    /* 0xE1 */ u8 m_lastFinishPos;
    /* 0xE2 - 0xE8 */ u8 _0xE2[0xE8 - 0xE2];
    /* 0xE8 */ u16 m_rating; // online VR/BR
    /* 0xEA - 0xF0 */ u8 _0xEA[0xF0 - 0xEA];
};

static_assert(sizeof(RaceInfoPlayer) == 0xF0);

class RaceInfo
{
public:
    EXTERN_TEXT(
      0x8052DBC8, //
      RaceInfo()
    );

    virtual ~RaceInfo();

    EXTERN_TEXT(
      0x8052ED28, //
      void SetupNextRaceInput(const RaceInfo* lastRace)
    );

    EXTERN_TEXT(
      0x8052FB90, //
      void InitRace(RaceInfo* race)
    );

    bool IsBattle()
    {
        return m_gameMode == MODE_BATTLE || m_gameMode == MODE_PUBLIC_BATTLE ||
               m_gameMode == MODE_PRIVATE_BATTLE;
    }

    bool IsBalloonBattle()
    {
        return IsBattle() && m_battleMode == BATTLE_BALLOON;
    }

    enum EEngineClass {
        CC_50 = 0,
        CC_100 = 1,
        CC_150 = 2,
        // Note: Battle mode actually sets it to 50cc (which is ignored by
        // code), but setting it to this in other modes results in Battle CC
        CC_BATTLE = 3
    };

    enum EGameMode {
        MODE_GRAND_PRIX = 0,
        MODE_VS_RACE = 1,
        MODE_TIME_TRIAL = 2,
        MODE_BATTLE = 3,
        MODE_MISSION_TOURNAMENT = 4,
        MODE_GHOST_RACE = 5,
        MODE_6 = 6,
        MODE_PRIVATE_VS = 7,
        MODE_PUBLIC_VS = 8,
        MODE_PUBLIC_BATTLE = 9,
        MODE_PRIVATE_BATTLE = 10,
        MODE_AWARD = 11,
        MODE_CREDITS = 12
    };

    enum ECameraMode {
        CAMERA_MODE_GAMEPLAY_NO_INTRO,
        CAMERA_MODE_REPLAY,
        CAMERA_MODE_TITLE_ONE_PLAYER,
        CAMERA_MODE_TITLE_TWO_PLAYER,
        CAMERA_MODE_TITLE_FOUR_PLAYER,
        CAMERA_MODE_GAMEPLAY_INTRO,
        CAMERA_MODE_LIVE_VIEW,
        CAMERA_MODE_GRAND_PRIX_WIN,
        CAMERA_MODE_SOLO_VS_WIN,
        CAMERA_MODE_TEAM_VS_WIN,
        CAMERA_MODE_BATTLE_WIN,
        CAMERA_MODE_UNK_11,
        CAMERA_MODE_LOSS,
    };

    enum EBattleMode {
        BATTLE_BALLOON = 0,
        BATTLE_COIN = 1,

        BATTLE_SHINE_THIEF = 2, // Added
    };

    enum ECPUMode {
        CPU_EASY = 0,
        CPU_NORMAL = 1,
        CPU_HARD = 2,
        CPU_NONE = 3
    };

    enum EItemMode {
        ITEM_BALANCED = 0,
        ITEM_FRANTIC = 1,
        ITEM_STRATEGIC = 2,
        ITEM_NONE = 3
    };

    enum ModeFlags {
        FLAG_MIRROR = 1 << 0,
        FLAG_TEAMS = 1 << 1,
        FLAG_TOURNAMENT = 1 << 2
    };

    /* 0x004 */ u8 m_playerCount;
    /* 0x005 */ u8 m_hudCount;
    /* 0x006 */ u8 m_localPlayerCount;
    /* 0x008 */ RaceInfoPlayer m_players[12];
    /* 0xB48 */ u32 m_courseId;
    /* 0xB4C */ EEngineClass m_engineClass;
    /* 0xB50 */ EGameMode m_gameMode;
    /* 0xB54 */ ECameraMode m_cameraMode;
    /* 0xB58 */ EBattleMode m_legacyBattleMode;
    /* 0xB5C */ ECPUMode m_cpuSetting;
    /* 0xB60 */ EItemMode m_itemSetting;
    /* 0xB64 */ u8 m_hudPlayerIds[4];
    /* 0xB68 */ u32 m_cupId;
    /* 0xB6C */ u8 m_raceNum;
    /* 0xB6D */ u8 m_lapCount;
    /* 0xB6E (ADDED) */ u16 m_battleMode;
    /* 0xB70 */ u32 m_modeFlags;
    // Must be fixed for a specific race to replay properly
    /* 0xB74 */ u32 m_seedFixed;
    // Can change between race and replay
    /* 0xB78 */ u32 m_seedRandom;
    /* 0xB7C */ RaceInfoMission m_mission;
    /* 0xBEC */ GhostData* m_ghost;
};

static_assert(sizeof(RaceInfo) == 0xBF0);

class RaceInfoManager : public ParamFile
{
public:
    static RaceInfoManager* s_instance;

    EXTERN_TEXT(
      0x8052FE58, //
      static RaceInfoManager* CreateInstance()
    );

    EXTERN_TEXT(
      0x80530038, //
      virtual ~RaceInfoManager()
    );

    virtual int UNDEF_80009DDC();
    virtual int UNDEF_80532078(); // just a blr
    virtual int UNDEF_80532074(); // just a blr
    virtual int UNDEF_80532070(); // just a blr

    void InitRace(); // Replaced

    /* 0x001C */ const u8* m_0x1C;

    /* 0x0020 */ RaceInfo m_info;
    /* 0x0C10 */ RaceInfo m_infoNext;
    /* 0x1800 */ RaceInfo m_infoAward;

    /* 0x23F0 */ RawGhostData m_ghosts[2];
};

static_assert(sizeof(RaceInfoManager) == 0x73F0);

} // namespace System
