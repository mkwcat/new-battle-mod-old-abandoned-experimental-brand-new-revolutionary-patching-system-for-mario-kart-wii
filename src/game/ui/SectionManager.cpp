#include "SectionManager.h"
#include <egg/core/eggHeap.h>

REPLACE(0x80634E44, void ui::SectionManager::Init())
{
    extern u32* UNDEF_809bd740;
    EGG::Heap* heap = (EGG::Heap*) UNDEF_809bd740[0x34];

    m_currentSection = nullptr;

    // This is just replicating some general C++ stuff
    u8* obj = new (heap, 4) u8[0x14];
    if (obj != nullptr) {
        extern u8* UNDEF_80637998(u8*); // SystemMessageGroup::__ct
        obj = UNDEF_80637998(obj);
    }
    m_systemMessageGroup = obj;

    extern void UNDEF_80637a20(u8*); // MessageGroup::Load
    UNDEF_80637a20(obj);

    extern void UNDEF_8052bff8(u8*); // NandManager::Init
    extern u8* UNDEF_809bd720; // NandManager::s_instance
    UNDEF_8052bff8(UNDEF_809bd720);

    obj = new (heap, 4) u8[0x128];
    if (obj != nullptr) {
        extern u8* UNDEF_806209e8(u8*); // SaveGhostManager::__ct
        obj = UNDEF_806209e8(obj);
    }
    m_saveGhostManager = obj;

    extern void UNDEF_80620b04(u8*);
    extern int UNDEF_80620c5c(u8*);
    UNDEF_80620b04(obj);
    m_errorSection = UNDEF_80620c5c(m_saveGhostManager);

    // GlobalContext... we do actually need to make this at some point
    obj = new u8[0x510];
    if (obj != nullptr) {
        extern u8* UNDEF_805e2f60(u8*); // GlobalContext::__ct
        obj = UNDEF_805e2f60(obj);
    }
    m_globalContext = obj;

    extern void UNDEF_80078920(); // nw4r::lyt::LytInit
    UNDEF_80078920();

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
