#pragma once

namespace System
{

class PlayerRating
{
public:
    PlayerRating()
    {
        m_points = 5000;
    }

    // Emitted in System/RaceInfo.cpp
    EXTERN_TEXT(
      0x8052DA10, //
      virtual ~PlayerRating()
    );

    u16 GetPoints() const
    {
        return m_points;
    }

    void SetPoints(u16 points)
    {
        m_points = points;
    }

    /* 0x8052CEF8 */
    static f32 Calc(f32 x, s32 param_2);

    /* 0x8052D00C */
    static f32 CalcSpline(f32 x, s32 index);

    /* 0x8052D068 */
    static f32 CalcPoints(s16 difference, bool isPos);

    /* 0x8052D118 */
    s16 CalcPosPoints(const PlayerRating* opponent) const;

    /* 0x8052D1C0 */
    s16 CalcNegPoints(const PlayerRating* opponent) const;

    /* 0x8052D270 */
    void UpdatePoints(s32 points);

private:
    u16 m_points;
};

static_assert(sizeof(PlayerRating) == 0x8);

} // namespace System
