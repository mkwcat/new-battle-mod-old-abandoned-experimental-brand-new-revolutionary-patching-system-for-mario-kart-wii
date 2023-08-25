#pragma once

#include "GhostData.h"
#include "Mii.h"
#include "PlayerRating.h"
#include <Boot/ParameterFile.h>

namespace System
{

struct RaceInfoMission {
    enum EMissionType {
        MODE_MINITURBO = 0x0,
        MODE_LAP_RUN_01 = 0x1,
        MODE_LAP_RUN_02 = 0x2,
        MODE_DRIFT = 0x3,
        MODE_ITEM_BOX = 0x4,
        MODE_ENEMY_DOWN_01 = 0x5,
        MODE_ENEMY_DOWN_02 = 0x6,
        MODE_ENEMY_DOWN_03 = 0x7,
        MODE_COIN_GET = 0x8,
        MODE_TO_GATE = 0x9,
        MODE_ROCKET_START = 0xA,
        MODE_ITEM_HIT = 0xB,
        MODE_WHEELIE = 0xC,
        MODE_SLIPSTREAM = 0xD,
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
    enum EPlayerType {
        PLAYER_MASTER = 0x0,
        PLAYER_CPU = 0x1,
        PLAYER_UNKNOWN2 = 0x2,
        PLAYER_GHOST = 0x3,
        PLAYER_REAL_ONLINE = 0x4,
        PLAYER_NONE = 0x5,
    };

    enum ETeam {
        TEAM_RED = 0x0,
        TEAM_BLUE = 0x1,
        TEAM_NONE = 0x2,
    };

    /* 0x8052D96C */
    RaceInfoPlayer();

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT(
      0x8052DC68, //
      virtual ~RaceInfoPlayer()
    );

    /* 0x8052E640 */
    void Reset();

    s32 GetCharacter()
    {
        return m_characterId;
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052E42C, //
      void SetCharacter(s32 characterId)
    )
    {
        m_characterId = characterId;
    }

    s32 GetVehicle()
    {
        return m_vehicleId;
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052E444, //
      void SetVehicle(s32 vehicleId)
    )
    {
        m_vehicleId = vehicleId;
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052E44C, //
      void SetType(EPlayerType type)
    )
    {
        m_type = type;
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052DD18, //
      ETeam GetTeam() const
    )
    {
        return m_team;
    }

    void SetTeam(ETeam team)
    {
        m_team = team;
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052E658, //
      void SetStartPosition(u8 pos)
    )
    {
        m_startPos = pos;
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052E660, //
      void SetGPRank(u8 rank)
    )
    {
        m_gpRank = rank;
    }

    /* 0x8052DA50 */
    void AppendParamFile(Boot::ParameterFile* file);

    /* 0x8052DAF0 */
    u32 ComputeGPRank();

    /* 0x04 */ u8 m_0x04;
    /* 0x05 */ u8 m_screenId;
    /* 0x06 */ u8 m_inputIndex;
    /* 0x08 */ s32 m_vehicleId;
    /* 0x0C */ s32 m_characterId;
    /* 0x10 */ EPlayerType m_type;
    /* 0x14 */ Mii m_mii;
    /* 0xCC */ ETeam m_team;
    /* 0xD0 */ s32 m_controllerId;
    /* 0xD4 */ u32 m_0xD4;
    /* 0xD8 */ u16 m_prevScore;
    /* 0xDA */ u16 m_score;
    /* 0xDC */ u16 m_0xDC;
    /* 0xDE */ u16 m_gpRankScore;
    /* 0xE0 */ u8 m_gpRank;
    /* 0xE1 */ u8 m_startPos;
    /* 0xE4 */ PlayerRating m_rating;
    /* 0xEC */ u8 m_0xEC;
};

static_assert(sizeof(RaceInfoPlayer) == 0xF0);

class RaceInfo
{
public:
    enum ECup {
        CUP_KINOKO = 0x0,
        CUP_FLOWER = 0x1,
        CUP_STAR = 0x2,
        CUP_SPECIAL = 0x3,
        CUP_KOURA = 0x4,
        CUP_BANANA = 0x5,
        CUP_KONOHA = 0x6,
        CUP_LIGHTNING = 0x7,

        CUP_BATTLE_WII = 0x0,
        CUP_BATTLE_RETRO = 0x1,
    };

    enum ECourse {
        // Mushroom Cup
        COURSE_LUIGI_CIRCUIT = 0x08,
        COURSE_MOO_MOO_MEADOWS = 0x01,
        COURSE_MUSHROOM_GORGE = 0x02,
        COURSE_TOADS_FACTORY = 0x04,

        // Flower Cup
        COURSE_MARIO_CIRCUIT = 0x00,
        COURSE_COCONUT_MALL = 0x05,
        COURSE_DK_SUMMIT = 0x06,
        COURSE_WARIO_GOLD_MINE = 0x07,

        // Star Cup
        COURSE_DAISY_CIRCUIT = 0x09,
        COURSE_KOOPA_CAPE = 0x0F,
        COURSE_MAPLE_TREEWAY = 0x0B,
        COURSE_GRUMBLE_VOLCANO = 0x03,

        // Special Cup
        COURSE_DRY_DRY_RUINS = 0x0E,
        COURSE_MOONVIEW_HIGHWAY = 0x0A,
        COURSE_BOWSER_CASTLE = 0x0C,
        COURSE_RAINBOW_ROAD = 0x0D,

        // Shell Cup
        COURSE_GCN_PEACH_BEACH = 0x10,
        COURSE_DS_YOSHI_FALLS = 0x14,
        COURSE_SNES_GHOST_VALLEY_2 = 0x19,
        COURSE_N64_MARIO_RACEWAY = 0x1A,

        // Banana Cup
        COURSE_N64_SHERBET_LAND = 0x1B,
        COURSE_GBA_SHY_GUY_BEACH = 0x1F,
        COURSE_DS_DELFINO_SQUARE = 0x17,
        COURSE_GCN_WALUIGI_STADIUM = 0x12,

        // Leaf Cup
        COURSE_DS_DESERT_HILLS = 0x15,
        COURSE_GBA_BOWSER_CASTLE_3 = 0x1E,
        COURSE_N64_DK_JUNGLE_PARKWAY = 0x1D,
        COURSE_GCN_MARIO_CIRCUIT = 0x11,

        // Lightning Cup
        COURSE_SNES_MARIO_CIRCUIT_3 = 0x18,
        COURSE_DS_PEACH_GARDENS = 0x16,
        COURSE_GCN_DK_MOUNTAIN = 0x13,
        COURSE_N64_BOWSER_CASTLE = 0x1C,

        // Battle Wii Cup
        COURSE_BLOCK_PLAZA = 0x21,
        COURSE_DELFINO_PIER = 0x20,
        COURSE_FUNKY_STADIUM = 0x23,
        COURSE_CHAIN_CHOMP_ROULETTE = 0x22,
        COURSE_THWOMP_DESERT = 0x24,

        // Battle Retro Cup
        COURSE_SNES_BATTLE_COURSE_4 = 0x27,
        COURSE_GBA_BATTLE_COURSE_3 = 0x28,
        COURSE_N64_SKYSCRAPER = 0x29,
        COURSE_GCN_COOKIE_LAND = 0x25,
        COURSE_DS_TWILIGHT_HOUSE = 0x26,

        // Special
        COURSE_GALAXY_ARENA = 0x36,
        COURSE_SUNSET_LUIGI_CIRCUIT = 0x3A,

        // Demo
        COURSE_DEMO_WIN = 0x37,
        COURSE_DEMO_LOSE = 0x38,
        COURSE_DEMO_DRAW = 0x39,

        // Control IDs
        COURSE_CONTROL_VOTING_01 = 0x42,
        COURSE_CONTROL_VOTING_02 = 0x43,
        COURSE_CONTROL_VOTING_RANDOM = 0xFF,
    };

    enum EEngineClass {
        ENGINE_CLASS_50 = 0x0,
        ENGINE_CLASS_100 = 0x1,
        ENGINE_CLASS_150 = 0x2,
        // Note: Battle mode actually sets it to 50cc (which is ignored by
        // code), but setting it to this in other modes results in Battle CC
        ENGINE_CLASS_BATTLE = 0x3,
    };

    enum EGameMode {
        GAME_MODE_GRAND_PRIX = 0x0,
        GAME_MODE_VS_RACE = 0x1,
        GAME_MODE_TIME_ATTACK = 0x2,
        GAME_MODE_BATTLE = 0x3,
        GAME_MODE_MISSION = 0x4,
        GAME_MODE_GHOST_RACE = 0x5,
        GAME_MODE_UNUSED = 0x6,
        GAME_MODE_WIFI_FRIEND_VS = 0x7,
        GAME_MODE_WIFI_PUBLIC_VS = 0x8,
        GAME_MODE_WIFI_PUBLIC_BATTLE = 0x9,
        GAME_MODE_WIFI_FRIEND_BATTLE = 0xA,
        GAME_MODE_AWARD = 0xB,
        GAME_MODE_CREDITS = 0xC,
    };

    enum ECameraMode {
        CAMERA_MODE_GAMEPLAY_NO_INTRO = 0x0,
        CAMERA_MODE_REPLAY = 0x1,
        CAMERA_MODE_TITLE_ONE_PLAYER = 0x2,
        CAMERA_MODE_TITLE_TWO_PLAYER = 0x3,
        CAMERA_MODE_TITLE_FOUR_PLAYER = 0x4,
        CAMERA_MODE_GAMEPLAY_INTRO = 0x5,
        CAMERA_MODE_LIVE_VIEW = 0x6,
        CAMERA_MODE_GRAND_PRIX_WIN = 0x7,
        CAMERA_MODE_SOLO_VS_WIN = 0x8,
        CAMERA_MODE_TEAM_VS_WIN = 0x9,
        CAMERA_MODE_BATTLE_WIN = 0xA,
        CAMERA_MODE_UNK_11 = 0xB,
        CAMERA_MODE_LOSS = 0xC,
    };

    enum EBattleMode {
        BATTLE_MODE_BALLOON = 0x0,
        BATTLE_MODE_COIN = 0x1,

        BATTLE_MODE_SHINE_THIEF = 0x2, // Added
    };

    enum ECPUMode {
        CPU_EASY = 0x0,
        CPU_NORMAL = 0x1,
        CPU_HARD = 0x2,
        CPU_NONE = 0x3,
    };

    enum EItemMode {
        ITEM_BALANCED = 0x0,
        ITEM_FRANTIC = 0x1,
        ITEM_STRATEGIC = 0x2,
        ITEM_NONE = 0x3,
    };

    enum ModeFlags {
        MODE_FLAGS_MIRROR = 1 << 0,
        MODE_FLAGS_TEAMS = 1 << 1,
        MODE_FLAGS_COMPETITION = 1 << 2,
    };

    /* 0x8052DBC8 */
    RaceInfo();

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT(
      0x805300F4, //
      virtual ~RaceInfo()
    );

    /* 0x8052E668 */
    void Reset();

    /* 0x8052E770 */
    u8 NextRace();

    /* 0x8052DCA8 */
    void ComputeWinningTeam();

    /* 0x8052E950 */
    void UpdatePoints();

    /* 0x8052ED28 */
    void PostPlayersSetupInputs(RaceInfo* prev);

    /* 0x8052EEF0 */
    void SetupGhost(u8 playerId, u8 inputIndex);

    /* 0x8052EFD4 */
    void PlayersReset();

    /* 0x8052EFD4 */
    void PlayersSetup();

    /* 0x8052F1E0 */
    void PlayersSetupStartOrder();

    /* 0x8052F4E8 */
    void PlayersSetupInputs(u8 screenCount);

    /* 0x8052F788 */
    void PlayersComputeCount( //
      u8* playerCount, u8* screenCount, u8* localPlayerCount
    );

    /* 0x8052F924 */
    void SetupRNGSeed();

    /* 0x8052FA0C */
    void SetupCompetitionInfo();

    /* 0x8052FB90 */
    void SetupRace(RaceInfo* prev);

    u8 GetPlayerCount() const
    {
        return m_playerCount;
    }

    void SetPlayerCount(u8 playerCount)
    {
        m_playerCount = playerCount;
    }

    u8 GetScreenCount() const
    {
        return m_screenCount;
    }

    void SetScreenCount(u8 screenCount)
    {
        m_screenCount = screenCount;
    }

    u8 GetLocalPlayerCount() const
    {
        return m_localPlayerCount;
    }

    void SetLocalPlayerCount(u8 localPlayerCount)
    {
        m_localPlayerCount = localPlayerCount;
    }

    u8 GetRaceScreenCount() const
    {
        return m_screenCountRace;
    }

    void SetRaceScreenCount(u8 screenCountRace)
    {
        m_screenCountRace = screenCountRace;
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052E434, //
      RaceInfoPlayer* GetPlayer(u8 playerIndex)
    )
    {
        return &m_players[playerIndex];
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052DD20, //
      const RaceInfoPlayer* GetPlayer(u8 playerIndex) const
    )
    {
        return &m_players[playerIndex];
    }

    ECourse GetCourse() const
    {
        return m_course;
    }

    void SetCourse(ECourse course)
    {
        m_course = course;
    }

    EEngineClass GetEngineClass() const
    {
        if (IsBattle()) {
            return ENGINE_CLASS_BATTLE;
        }

        return m_engineClass;
    }

    void SetEngineClass(EEngineClass engineClass)
    {
        m_engineClass = engineClass;
    }

    EGameMode GetGameMode() const
    {
        return m_gameMode;
    }

    void SetGameMode(EGameMode gameMode)
    {
        m_gameMode = gameMode;
    }

    bool IsBattle() const
    {
        switch (m_gameMode) {
        case GAME_MODE_BATTLE:
        case GAME_MODE_WIFI_PUBLIC_BATTLE:
        case GAME_MODE_WIFI_FRIEND_BATTLE:
            return true;

        default:
            return false;
        }
    }

    EBattleMode GetBattleMode() const
    {
        return (EBattleMode) m_battleMode;
    }

    void SetBattleMode(EBattleMode battleMode)
    {
        m_battleMode = (u16) battleMode;
    }

    EBattleMode GetBattleBaseMode() const
    {
        return m_legacyBattleMode;
    }

    bool IsBalloonBattle() const
    {
        return IsBattle() && m_battleMode == BATTLE_MODE_BALLOON;
    }

    bool IsCoinBattle() const
    {
        return IsBattle() && m_battleMode == BATTLE_MODE_COIN;
    }

    bool IsShineThief() const
    {
        return IsBattle() && m_battleMode == BATTLE_MODE_SHINE_THIEF;
    }

    bool IsWiFiMode() const
    {
        switch (m_gameMode) {
        case GAME_MODE_WIFI_FRIEND_VS:
        case GAME_MODE_WIFI_PUBLIC_VS:
        case GAME_MODE_WIFI_PUBLIC_BATTLE:
        case GAME_MODE_WIFI_FRIEND_BATTLE:
            return true;

        default:
            return false;
        }
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052ED18, //
      ECameraMode GetCameraMode() const
    )
    {
        return m_cameraMode;
    }

    void SetCameraMode(ECameraMode cameraMode)
    {
        m_cameraMode = cameraMode;
    }

    u8 GetScreenPlayerID(u8 screenId) const
    {
        if (screenId > 4) {
            return -1;
        }

        return m_screenPlayerIds[screenId];
    }

    ECup GetCup() const
    {
        return m_cup;
    }

    void SetCup(ECup cup)
    {
        m_cup = cup;
    }

    u8 GetRaceNumber() const
    {
        return m_raceNum;
    }

    u8 GetLapCount() const
    {
        if (!GetIsCompetition()) {
            return 3;
        }

        if (m_lapCount < 1 || m_lapCount > 8) {
            return 3;
        }

        return m_lapCount;
    }

    /**
     * Only used in competition mode.
     */
    void SetLapCount(u8 lapCount)
    {
        m_lapCount = lapCount;
    }

    void ClearModeFlags()
    {
        m_modeFlags = 0;
    }

    bool GetIsMirror() const
    {
        return m_modeFlags & MODE_FLAGS_MIRROR;
    }

    void SetIsMirror(bool mirror)
    {
        m_modeFlags |= MODE_FLAGS_MIRROR;
    }

    bool GetIsTeams() const
    {
        return m_modeFlags & MODE_FLAGS_TEAMS;
    }

    void SetIsTeams(bool teams)
    {
        m_modeFlags |= MODE_FLAGS_TEAMS;
    }

    bool GetIsCompetition() const
    {
        return m_modeFlags & MODE_FLAGS_COMPETITION;
    }

    void SetIsCompetition(bool competition)
    {
        m_modeFlags |= MODE_FLAGS_COMPETITION;
    }

private:
    /* 0x004 */ u8 m_playerCount;
    /* 0x005 */ u8 m_screenCount;
    /* 0x006 */ u8 m_localPlayerCount;
    /* 0x007 */ u8 m_screenCountRace;
    /* 0x008 */ RaceInfoPlayer m_players[12];
    /* 0xB48 */ ECourse m_course;
    /* 0xB4C */ EEngineClass m_engineClass;
    /* 0xB50 */ EGameMode m_gameMode;
    /* 0xB54 */ ECameraMode m_cameraMode;
    /* 0xB58 */ EBattleMode m_legacyBattleMode;
    /* 0xB5C */ ECPUMode m_cpuSetting;
    /* 0xB60 */ EItemMode m_itemSetting;
    /* 0xB64 */ u8 m_screenPlayerIds[4];
    /* 0xB68 */ ECup m_cup;
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

class RaceInfoManager : public Boot::ParameterFile
{
public:
    static RaceInfoManager* s_instance;

    EXTERN_TEXT(
      0x8052FE58, //
      static RaceInfoManager* CreateInstance()
    );

    // Emitted in UI/Control/CtrlRaceTime.cpp
    EXTERN_TEXT_INLINE(
      0x807F7EB4, //
      static RaceInfoManager* GetInstance()
    )
    {
        return s_instance;
    }

    EXTERN_TEXT(
      0x80530038, //
      virtual ~RaceInfoManager()
    );

    /* 0x8052DD40 */
    void Init();

    /* 0x8052E454 */
    void Reset();

    /* 0x8052E870 */
    s32 GetUpdatedRating(u8 playerId);

    /* 0x805302C4 */
    void SetupRace();

    virtual int UNDEF_80009DDC();
    virtual int UNDEF_80532078(); // just a blr
    virtual int UNDEF_80532074(); // just a blr
    virtual int UNDEF_80532070(); // just a blr

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052DD30, //
      static u8 GetPlayerCount()
    )
    {
        return s_instance->m_info.GetPlayerCount();
    }

    static RaceInfo* GetInfo()
    {
        return &s_instance->m_info;
    }

    static RaceInfo* GetInfoNext()
    {
        return &s_instance->m_infoNext;
    }

    /* 0x001C */ const u8* m_0x1C;

    /* 0x0020 */ RaceInfo m_info;
    /* 0x0C10 */ RaceInfo m_infoNext;
    /* 0x1800 */ RaceInfo m_infoAward;

    /* 0x23F0 */ RawGhostData m_ghosts[2];
};

static_assert(sizeof(RaceInfoManager) == 0x73F0);

} // namespace System
