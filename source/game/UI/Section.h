#pragma once

#include "PageID.h"
#include "SectionID.h"

namespace UI
{

class Page;

class Section
{
    void AddPages(ESectionID sectionId);

    EXTERN_TEXT(
      0x80622D08, //
      void AddPage(EPageID pageId)
    );

public:
    /* 0x000 */ ESectionID m_id;
    /* 0x004 */ u32 m_unk_0x4;
    /* 0x008 */ Page* m_pages[PAGE_ID_COUNT];
};

} // namespace UI
