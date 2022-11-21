#pragma once

namespace sys
{

class InputManager
{
    class Pad
    {
        friend class InputManager;

    protected:
        u8 _0[0x50 - 0x0];
        bool m_unk_0x50; // Enabled?
        u8 _51[0x90 - 0x51];
    };

    static_assert(sizeof(Pad) == 0x90);

    // Probably not located here, also inherits Input
    struct PlayerInput {
        u8 _0[0x4 - 0x0];
        Pad* m_controller;
        Pad* m_controller2;
        Pad* m_controller3;
        u8 _10[0xC8 - 0x10];
        u8 m_unk_0xC8[0xEC - 0xC8];
    };

    static_assert(sizeof(PlayerInput) == 0xEC);

    class WiiPad : public Pad
    {
        friend class InputManager;

    protected:
        u8 _90[0x920 - 0x90];
    };

    static_assert(sizeof(WiiPad) == 0x920);

    class GCPad : public Pad
    {
        friend class InputManager;

    protected:
        u8 _90[0xB0 - 0x90];
    };

    static_assert(sizeof(GCPad) == 0xB0);

public:
    static InputManager* s_instance;

    void Init(); // Replaced

private:
    u8 _0[0x4 - 0x0];
    PlayerInput m_playerInputs[4];
    u8 _3B4[0x1690 - 0x3B4];
    Pad m_dummyPad;
    WiiPad m_wiiPads[4];
    GCPad m_gcPads[4];
    u8 _3E60[0x415C - 0x3E60];
};

static_assert(sizeof(InputManager) == 0x415C);

} // namespace sys
