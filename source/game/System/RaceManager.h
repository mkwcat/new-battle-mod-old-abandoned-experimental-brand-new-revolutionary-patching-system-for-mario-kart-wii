#pragma once

#include "GhostData.h"
#include "RaceMode.h"
#include "Timer.h"

namespace System
{

class RaceManager
{
public:
    static RaceManager* s_instance;

    class Player
    {
    public:
        FILL(0x0, 0x38);
        u32 m_flags;
    };

    class RaceTimer : public Timer
    {
    public:
        // vtable 0x808B34B0
        EXTERN_TEXT(
          0x805376E0, //
          virtual ~RaceTimer()
        );

        EXTERN_TEXT(
          0x80535864, //
          virtual void Reset()
        );

        EXTERN_TEXT(
          0x80535904, //
          virtual void Update()
        );
    };

    EXTERN_TEXT(
      0x805327A0, //
      RaceManager()
    );

    EXTERN_TEXT(
      0x80532E3C, //
      virtual ~RaceManager()
    );

    EXTERN_TEXT(
      0x805336A4, //
      u32 GetLapCount() const
    );

    EXTERN_TEXT(
      0x80533C6C, //
      void EndPlayerRace(u32 playerId)
    );

    void UNDEF_80533d84(u32 playerId);

    EXTERN_TEXT(
      0x80536230, //
      bool HasReachedStage(u32 stage)
    );

    // 3 parameters undocumented
    void GetKartStartPosition();

    void* GetKartPoint(s32 playerId);

public:
    /* 0x04 */ void* m_random1;
    /* 0x08 */ void* m_random2;
    /* 0x0C */ Player** m_players;
    /* 0x10 */ RaceMode* m_raceMode;
    /* 0x14 */ RaceTimer* m_timer;
    /* 0x18 */ u8* m_playerRanks;
    /* 0x1C */ u8 m_finishedPlayerCount;
    /* 0x1E */ u16 m_introTimer;
    /* 0x20 */ u32 m_frame;
    /* 0x24 */ u8 m_battleKtptStart;
    /* 0x28 */ u32 m_stage;
    /* 0x2C */ bool m_introSkipped;
    /* 0x2D */ bool m_spectatorMode;
    /* 0x2E */ bool m_canCountdownStart;
    /* 0x2F */ bool m_cutSceneMode;
    /* 0x30 */ bool m_lapCountingEnabled;
    FILL(0x31, 0x3C);
    /* 0x3C */ void* m_kmgFile;
    /* 0x40 */ void* m_elineControlManager;
    /* 0x44 */ f32 m_waterHeightCheck;
    /* 0x48 */ bool m_disableLowerRespawns;
    FILL(0x49, 0x50);
};

static_assert(sizeof(RaceManager) == 0x50);

} // namespace System
