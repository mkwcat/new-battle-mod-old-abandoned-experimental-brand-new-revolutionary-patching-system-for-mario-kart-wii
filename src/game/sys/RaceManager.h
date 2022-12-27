#pragma once

#include "GhostData.h"
#include "Timer.h"

namespace sys
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

    class RaceMode
    {
    public:
        RaceManager* m_raceManager;

        virtual bool CanRaceEnd() = 0; // vt + 0x8
        virtual void vt_0xC() = 0; // Related to timer?
        virtual void vt_0x10() = 0; // Related to online?
    };

    class BalloonBattle : public RaceMode
    {
    public:
        // Note: vtable at 0x808B36E4

        EXTERN_TEXT(0x80539770, virtual bool CanRaceEnd());
        EXTERN_TEXT(0x80535DE8, virtual void vt_0xC());
        EXTERN_TEXT(0x80539574, virtual void vt_0x10());

        // Actually a virtual function
        void PlayerHitByPlayer(u32 attackerId, u32 targetId);
        void PlayerFallOutOfBounds(u32 targetId);
        void PlayerHitByObject(u32 targetId);

        // At 0x80538E00, I don't know what else to call it
        void SidelinePlayer(u8 playerId);
    };

    class RaceTimer : public Timer
    {
    public:
        // vtable 0x808B34B0
        EXTERN_TEXT(0x805376E0, virtual ~RaceTimer());
        EXTERN_TEXT(0x80535864, virtual void Reset());
        EXTERN_TEXT(0x80535904, virtual void Update());
    };

    EXTERN_TEXT(0x805327A0, RaceManager());
    EXTERN_TEXT(0x80532E3C, virtual ~RaceManager());

    EXTERN_TEXT(0x805336A4, u32 GetLapCount() const);
    EXTERN_TEXT(0x80533C6C, void EndPlayerRace(u32 playerId));
    void UNDEF_80533d84(u32 playerId);

    EXTERN_TEXT(0x80536230, bool HasReachedStage(u32 stage));

public:
    /* 0x04 */ void* m_random1;
    /* 0x08 */ void* m_random2;
    /* 0x0C */ Player** m_players;
    /* 0x10 */ RaceMode* m_raceMode;
    /* 0x14 */ RaceTimer* m_timer;
    /* 0x18 */ u8* m_playerPolePositions;
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

} // namespace sys
