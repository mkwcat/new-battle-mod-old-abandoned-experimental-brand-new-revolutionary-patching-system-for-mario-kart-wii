#pragma once

namespace ui
{

class GlobalContext;
class SaveManagerProxy;

class SectionManager
{
public:
    void Init();

private:
    void* m_currentSection;
    int m_errorSection;
    int m_argsSection;
    int m_nextSectionId;
    int m_lastSectionId;
    int m_animDir;
    int m_nextAnimDir;
    u8 _1C[0x20 - 0x1C];
    bool m_unk_0x20;
    u8 _21[0x34 - 0x21];
    u8 _34[0x90 - 0x34];
    SaveManagerProxy* m_saveManagerProxy;
    u8* m_systemMessageGroup;
    GlobalContext* m_globalContext;
};

static_assert(sizeof(SectionManager) == 0x9C);

} // namespace ui
