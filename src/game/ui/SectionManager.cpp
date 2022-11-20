#include "SectionManager.h"
#include "GlobalContext.h"
#include "SaveManagerProxy.h"
#include <egg/core/eggHeap.h>
#include <nw4r/lyt/lyt_init.h>

u8* ext_80637998(u8*); // SystemMessageGroup::__ct

REPLACE(0x80634E44, void ui::SectionManager::Init())
{
    extern u32* UNDEF_809bd740;
    EGG::Heap* heap = (EGG::Heap*) UNDEF_809bd740[0x34];

    m_currentSection = nullptr;

    // This is just replicating some general C++ stuff
    u8* obj = new (heap, 4) u8[0x14];
    if (obj != nullptr) {
        obj = ext_80637998(obj);
    }
    m_systemMessageGroup = obj;

    extern void UNDEF_80637a20(u8*); // MessageGroup::Load
    UNDEF_80637a20(obj);

    extern void UNDEF_8052bff8(u8*); // NandManager::Init
    extern u8* UNDEF_809bd720; // NandManager::s_instance
    UNDEF_8052bff8(UNDEF_809bd720);

    m_saveManagerProxy = new (heap, 4) ui::SaveManagerProxy();
    m_saveManagerProxy->Init();
    m_errorSection = m_saveManagerProxy->GetErrorSection();

    m_globalContext = new GlobalContext();

    nw4r::lyt::LytInit();

    extern void UNDEF_8061aebc(u8*);
    UNDEF_8061aebc(_34);

    // Mii related function
    extern int UNDEF_805276e0();
    if (UNDEF_805276e0() != 0 && m_errorSection != 0x14) {
        m_errorSection = 0x15;
    }

    // Let's ignore command line arguments
    // m_errorSection = m_errorSection == -1 ? ret : m_errorSection;
    // m_errorSection = m_errorSection == -1 ? 0x3F : m_errorSection;
    // m_nextSectionId = m_argsSection == -1 ? m_errorSection : m_argsSection;
    m_nextSectionId = m_errorSection == -1 ? 0x3F : m_errorSection;

    m_nextAnimDir = 0;
    m_unk_0x20 = true;

    extern u8* UNDEF_80385fc0;
    UNDEF_80385fc0[0x50] = 1;
}
