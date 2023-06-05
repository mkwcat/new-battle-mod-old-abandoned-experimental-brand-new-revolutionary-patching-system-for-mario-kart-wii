#pragma once

#include "PageID.h"
#include "SectionID.h"

namespace UI
{

class Page;

class Section
{
    void AddPages(SectionID sectionId);
    EXTERN_TEXT(0x80622D08, void AddPage(PageID pageId));

public:
    /* 0x000 */ SectionID m_id;
    /* 0x004 */ u32 m_unk_0x4;
    /* 0x008 */ Page* m_pages[static_cast<u32>(PageID::Count)];
};

} // namespace UI
