#pragma once

// 0x94 in "AIHolder". This name is really just a complete guess.

class AIBattleManager
{
public:
    EXTERN_TEXT(0x80727788, AIBattleManager());

    class Team
    {
    public:
        void* m_playerSub20[6];
        u32 m_playerCount;
    };

    class Class_0xBC
    {
    public:
        // I don't know what this actually does, but I do know that it crashes
        // if a team has no players on it. (0x80728CC8)

        void __TeamPositionUpdate(int param_2, Team* team); // Original
        void TeamPositionUpdate(int param_2, Team* team); // Replaced
    };

private:
    FILL(0x0, 0xBC);
    Class_0xBC* m_unk_0xBC;
    Team* m_teamRed;
    Team* m_teamBlue;
    FILL(0xC8, 0xD0);
};

static_assert(sizeof(AIBattleManager) == 0xD0);
