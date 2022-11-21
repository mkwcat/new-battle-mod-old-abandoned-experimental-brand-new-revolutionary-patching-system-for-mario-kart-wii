#pragma once

namespace ui
{

class RegisteredPadManager
{
public:
    EXTERN_TEXT(0x8061AE6C, RegisteredPadManager());
    EXTERN_TEXT(0x8061AE7C, ~RegisteredPadManager());

    EXTERN_TEXT(0x8061AEBC, void Init());
    EXTERN_TEXT(0x8061AF20, void Calc());
    EXTERN_TEXT(0x8061B358, u32 GetFlags(s32 localPlayerId));

    void UNDEF_8061B4A8();
    void UNDEF_8061B5A4();

    void ForceRegisterGCN()
    {
        m_entry[0].m_flags = 0x124;
        m_entry[0].m_unk_0x4 = 0x124;
    }

private:
    u8 _0[0x4 - 0x0];

    struct Entry {
        u32 m_flags;
        u32 m_unk_0x4;
        u32 m_unk_0x8;
        void* m_input;
    };

    Entry m_entry[5];

    u8 _54[0x5C - 0x54];
};

static_assert(sizeof(RegisteredPadManager) == 0x5C);

} // namespace ui
