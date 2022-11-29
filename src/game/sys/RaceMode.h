#pragma once

namespace sys
{

class RaceManager;

class RaceMode
{
public:
    RaceManager* m_raceManager;

    virtual bool CanRaceEnd() = 0; // vt + 0x8
    virtual void vt_0xC() = 0; // Related to timer?
    virtual void vt_0x10() = 0; // Related to online?
};

} // namespace sys
