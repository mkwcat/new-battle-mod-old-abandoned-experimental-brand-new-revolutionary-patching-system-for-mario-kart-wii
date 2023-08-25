#pragma once

#include "GhostData.h"
#include "Mii.h"
#include "PlayerRating.h"
#include <Boot/ParameterFile.h>

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
    /* 0xD8 */ u16 m_lastScore;
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
    enum EEngineClass {
        CC_50 = 0,
        CC_100 = 1,
        CC_150 = 2,
        // Note: Battle mode actually sets it to 50cc (which is ignored by
        // code), but setting it to this in other modes results in Battle CC
        CC_BATTLE = 3,
    };

    enum EGameMode {
        MODE_GRAND_PRIX = 0,
        MODE_VS_RACE = 1,
        MODE_TIME_ATTACK = 2,
        MODE_BATTLE = 3,
        MODE_MISSION = 4,
        MODE_GHOST_RACE = 5,
        MODE_6 = 6,
        MODE_WIFI_FRIEND_VS = 7,
        MODE_WIFI_PUBLIC_VS = 8,
        MODE_WIFI_PUBLIC_BATTLE = 9,
        MODE_WIFI_FRIEND_BATTLE = 10,
        MODE_AWARD = 11,
        MODE_CREDITS = 12,
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
        CPU_NONE = 3,
    };

    enum EItemMode {
        ITEM_BALANCED = 0,
        ITEM_FRANTIC = 1,
        ITEM_STRATEGIC = 2,
        ITEM_NONE = 3,
    };

    enum ModeFlags {
        FLAG_MIRROR = 1 << 0,
        FLAG_TEAMS = 1 << 1,
        FLAG_COMPETITION = 1 << 2,
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
    void PostInitInputs();

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

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT_INLINE(
      0x8052ED18, //
      ECameraMode GetCameraMode()
    )
    {
        return m_cameraMode;
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

    u8 GetPlayerCount() const
    {
        return m_playerCount;
    }

    bool IsBattle() const
    {
        return m_gameMode == MODE_BATTLE ||
               m_gameMode == MODE_WIFI_PUBLIC_BATTLE ||
               m_gameMode == MODE_WIFI_FRIEND_BATTLE;
    }

    bool IsBalloonBattle() const
    {
        return IsBattle() && m_battleMode == BATTLE_BALLOON;
    }

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

class RaceInfoManager : public Boot::ParameterFile
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
      static u8 GetRacePlayerCount()
    )
    {
        return s_instance->m_info.GetPlayerCount();
    }

    /* 0x001C */ const u8* m_0x1C;

    /* 0x0020 */ RaceInfo m_info;
    /* 0x0C10 */ RaceInfo m_infoNext;
    /* 0x1800 */ RaceInfo m_infoAward;

    /* 0x23F0 */ RawGhostData m_ghosts[2];
};

static_assert(sizeof(RaceInfoManager) == 0x73F0);

} // namespace System
