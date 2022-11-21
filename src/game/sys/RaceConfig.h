#pragma once

#include "GhostData.h"

// A class for loading a prm file from the disc, an unused file type
class ParamFile
{
public:
    virtual ~ParamFile();
    u8 _0[0x18 - 0x0];
};

namespace sys
{

struct MissionSetting {
    enum GameMode {
        MODE_Miniturbo = 0,
        MODE_LapRun01 = 1,
        MODE_LapRun02 = 2,
        MODE_Drift = 3,
        MODE_ItemBox = 4,
        MODE_EnemyDown01 = 5,
        MODE_EnemyDown02 = 6,
        MODE_EnemyDown03 = 7,
        MODE_CoinGet01 = 8,
        MODE_ToGate01 = 9,
        MODE_RocketStart = 10,
        MODE_ItemHit = 11,
        MODE_Wheelie = 12,
        MODE_Slipstream = 13
    };

    /* 0x00 */ u16 m_mrFile;
    /* 0x02 */ u16 m_gameMode;
    /* 0x04 */ u8 m_courseId;
    /* 0x05 */ u8 m_characterId;
    /* 0x06 */ u8 m_vehicleId;
    /* 0x07 */ u8 m_engineClass;
    /* 0x08 - 0x2C */ u8 _0x08[0x2C - 0x08];
    // Time limit in seconds
    /* 0x2C */ u16 m_timeLimit;
    /* 0x2E */ u8 m_unk_0x2E;
    /* 0x2F */ bool m_forceWiiWheel;
    /* 0x30 */ u32 m_scoreRequired;
    // Unused duplicates of scoreRequired???
    /* 0x34 - 0x48 */ u8 _0x34[0x48 - 0x34];
    /* 0x48 */ u16 m_cameraAngle;
    /* 0x4A */ u16 m_minimapObject;
    /* 0x4C */ u16 m_unk_0x4C;
    /* 0x4E */ u16 m_unk_0x4E;
    /* 0x50 */ u16 m_cannonFlag;
    /* 0x52 */ u16 m_unk_0x52;
    /* 0x54 */ u32 m_unk_0x54;
    /* 0x58 */ u16 m_cpuCount;
    /* 0x5A */ u8 m_cpu[22];
};

static_assert(sizeof(MissionSetting) == 0x70);

class RaceConfig : public ParamFile
{
public:
    static RaceConfig* s_instance;

    EXTERN_TEXT(0x80530038, virtual ~RaceConfig());
    virtual int UNDEF_80009DDC();
    virtual int UNDEF_80532078(); // just a blr
    virtual int UNDEF_80532074(); // just a blr
    virtual int UNDEF_80532070(); // just a blr

    class Player
    {
    public:
        EXTERN_TEXT(0x8052D96C, Player());
        EXTERN_TEXT(0x8052DC68, virtual ~Player());

        EXTERN_TEXT(0x8052DAF0, u32 ComputeGPRank());

        enum PlayerType {
            PLAYER_REAL_LOCAL,
            PLAYER_CPU,
            PLAYER_UNKNOWN2,
            PLAYER_GHOST,
            PLAYER_REAL_ONLINE,
            PLAYER_NONE
        };

        enum Team {
            TEAM_RED,
            TEAM_BLUE
        };

        /* 0x04 */ u8 m_unk_0x4;
        /* 0x05 */ u8 m_localPlayerId;
        /* 0x06 */ u8 m_controllerId;
        /* 0x08 */ u32 m_vehicleId;
        /* 0x0C */ u32 m_characterId;
        /* 0x10 */ u32 m_playerType;
        /* 0x14 - 0xCC */ u8 _0x14[0xCC - 0x14];
        /* 0xCC */ u32 m_team;
        /* 0xD0 - 0xD8 */ u8 _0xD0[0xD8 - 0xD0];
        /* 0xD8 */ u16 m_lastScore;
        /* 0xDA */ u16 m_score;
        /* 0xDC */ u16 m_unk_0xDC;
        /* 0xDE */ u16 m_gpRankScore;
        /* 0xE0 */ u8 m_unk_0xE0;
        /* 0xE1 */ u8 m_lastFinishPos;
        /* 0xE2 - 0xE8 */ u8 _0xE2[0xE8 - 0xE2];
        /* 0xE8 */ u16 m_rating; // online VR/BR
        /* 0xEA - 0xF0 */ u8 _0xEA[0xF0 - 0xEA];
    };

    static_assert(sizeof(Player) == 0xF0);

    class RaceSetting
    {
    public:
        EXTERN_TEXT(0x8052DBC8, RaceSetting());
        virtual ~RaceSetting();

        EXTERN_TEXT(
          0x8052ED28, void SetupNextRaceInput(const RaceSetting* lastRace)
        );

        enum EngineClass {
            CC_50 = 0,
            CC_100 = 1,
            CC_150 = 2,
            // Note: Battle mode actually sets it to 50cc (which is ignored by
            // code), but setting it to this in other modes results in Battle CC
            CC_BATTLE = 3
        };

        enum GameMode {
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

        enum CameraMode {
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

        enum BattleMode {
            BATTLE_BALLOON = 0,
            BATTLE_COIN = 1
        };

        enum CpuSetting {
            CPU_EASY = 0,
            CPU_NORMAL = 1,
            CPU_HARD = 2,
            CPU_NONE = 3
        };

        enum ItemSetting {
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
        /* 0x008 */ Player m_players[12];
        /* 0xB48 */ u32 m_courseId;
        /* 0xB4C */ u32 m_engineClass;
        /* 0xB50 */ u32 m_gameMode;
        /* 0xB54 */ u32 m_cameraMode;
        /* 0xB58 */ u32 m_battleMode;
        /* 0xB5C */ u32 m_cpuSetting;
        /* 0xB60 */ u32 m_itemSetting;
        /* 0xB64 */ u8 m_hudPlayerIds[4];
        /* 0xB68 */ u32 m_cupId;
        /* 0xB6C */ u8 m_raceNum;
        /* 0xB6D */ u8 m_lapCount;
        /* 0xB70 */ u32 m_modeFlags;
        // Must be fixed for a specific race to replay properly
        /* 0xB74 */ u32 m_seedFixed;
        // Can change between race and replay
        /* 0xB78 */ u32 m_seedRandom;
        /* 0xB7C */ MissionSetting m_mission;
        /* 0xBEC */ GhostData* m_ghost;
    };

    static_assert(sizeof(RaceSetting) == 0xBF0);

    /* 0x001C */ const u8* m_unk_0x1C;

    /* 0x0020 */ RaceSetting m_currentRace;
    /* 0x0C10 */ RaceSetting m_nextRace;
    /* 0x1800 */ RaceSetting m_awardsRace;

    /* 0x23F0 */ RawGhostData m_ghosts[2];
};

static_assert(sizeof(RaceConfig) == 0x73F0);

} // namespace sys
