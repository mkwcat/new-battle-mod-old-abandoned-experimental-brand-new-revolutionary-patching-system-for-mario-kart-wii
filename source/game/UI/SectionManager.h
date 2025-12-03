#pragma once

#include "Page.h"
#include "RegisteredPadManager.h"
#include "Section.h"
#include "SectionID.h"

namespace UI
{

class GlobalContext;
class SaveManagerProxy;
class SystemMessageGroup;

class SectionManager
{
public:
    static SectionManager* s_instance;

    EXTERN_TEXT(
      0x80634C90, //
      static SectionManager* CreateInstance()
    );

    SectionManager();
    void Init(); // Replaced

    /* --- */
    bool SelectDebugLicense();

    /* --- */
    void DebugBootSetup();

    Section* m_currentSection;
    ESectionID m_errorSection;
    ESectionID m_argsSection;
    ESectionID m_nextSectionId;
    ESectionID m_lastSectionId;
    Page::EFadeDirection m_fadeDir;
    Page::EFadeDirection m_nextFadeDir;
    u8 _1C[0x20 - 0x1C];
    bool m_initialized;
    u8 _21[0x23 - 0x21];
    bool m_debugMode; // Added
    u8 _24[0x34 - 0x24];
    RegisteredPadManager m_registeredPadManager;
    SaveManagerProxy* m_saveManagerProxy;
    SystemMessageGroup* m_systemMessageGroup;
    GlobalContext* m_globalContext;
};

static_assert(sizeof(SectionManager) == 0x9C);

} // namespace UI
