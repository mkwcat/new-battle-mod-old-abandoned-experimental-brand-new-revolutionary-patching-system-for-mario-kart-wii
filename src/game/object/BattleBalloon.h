#pragma once

namespace object
{

class BattleBalloon;

class BattleBalloonMgr
{
public:
    static BattleBalloonMgr* s_instance;

    EXTERN_TEXT(0x808697BC, static void InitStatic());

    BattleBalloonMgr();

    // Replaced 0x80869DF4
    void AddToPlayer(
      u32 playerId, u8 team, int param_4, int param_5, u8 count, int param_7
    );

    EXTERN_TEXT(
      0x80869FD0, void PopBalloons(
                    u32 playerId, int param_3, int param_4, int param_5,
                    u8 count, int param_7
                  )
    );

    u8 m_playerCount;
    u8 m_numOfEachType;
    u8 m_balloonCount;

    struct Balloon {
        BattleBalloon* m_object;
        u8 m_color;
        FILL(0x5, 0x8);
    };

    struct PlayerData {
        u8 m_count;
        u32 m_balloons[5];
    };

    static constexpr u32 MaxBalloonCount = 120;

    Balloon m_balloons[MaxBalloonCount];
    PlayerData m_playerData[12];
    FILL(0x4E4, 0x4F8);
};

static_assert(sizeof(BattleBalloonMgr) == 0x4F8);

class BattleBalloon
{
public:
    enum class Color {
        Red,
        Blue,
        Yellow,
        Green,
        Purple,
        Brown,
        Orange,
        Pink,
        Black,
        BlueLight,
        GreenDark,
        BlueDark,
    };

    BattleBalloon(u32 index, Color color);

    u32* m_vtable;
    FILL(0x4, 0x1E4);
};

static_assert(sizeof(BattleBalloon) == 0x1E4);

} // namespace object
