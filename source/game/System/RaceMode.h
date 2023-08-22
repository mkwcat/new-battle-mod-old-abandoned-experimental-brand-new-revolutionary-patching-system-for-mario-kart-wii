#pragma once

namespace System
{

class RaceManager;

class RaceMode
{
public:
    // Functions defined in RaceManager.cpp

    /* VT + 0x08 */ virtual bool IsFinishReady();
    /* VT + 0x0C */ virtual void ForceFinish();
    /* VT + 0x10 */ virtual void Calc();
    /* VT + 0x14 */ virtual void CalcPosition();
    /* VT + 0x18 */ virtual void* GetJugemPoint();
    /* VT + 0x1C */ virtual void Init();
    /* VT + 0x20 */ virtual void VT_0x20();
    /* VT + 0x24 */ virtual void FinishIfNeeded(s32 finishedCount, s32 playerCount);
    /* VT + 0x28 */ virtual void VT_0x28();

protected:
    /* 0x4 */ RaceManager* m_raceManager;
};

static_assert(sizeof(RaceMode) == 0x8);

} // namespace System
