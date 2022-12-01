#pragma once

#include "Mii.h"
#include "MiiManager.h"

namespace sys
{

class SaveManager
{
public:
    static SaveManager* s_instance;

    EXTERN_TEXT(0x80543DB0, static SaveManager* CreateInstance());

    class License
    {
        friend class SaveManager;

    public:
        void UNDEF_80549878();

    private:
        wchar_t m_miiName[11];
        MiiId m_miiId;
        u8 _001E[0x93E6 - 0x001E];

    public:
        u8 m_unk_0x93E6[4];

    private:
        u8 _93EA[0x93F0 - 0x93EA];
    };

    static_assert(sizeof(License) == 0x93F0);

public:
    License* GetSelectedLicense()
    {
        if (m_selectedLicense >= 0)
            return &m_licenses[u8(m_selectedLicense)];
        return nullptr;
    }

    static bool IsInvalidMii(License* license, EGG::Heap* heap)
    {
        Mii* mii =
          MiiManager::s_instance->ConstructMii(&license->m_miiId, heap);

        if (mii != nullptr && mii->m_unk_0xA4)
            return true;

        return false;
    }

    EXTERN_TEXT(0x80544CD8, void SelectLicense(int licenseId));

private:
    u32 _0[0x36 - 0x0];
    s16 m_selectedLicense;
    License m_licenses[4];
};

} // namespace sys
