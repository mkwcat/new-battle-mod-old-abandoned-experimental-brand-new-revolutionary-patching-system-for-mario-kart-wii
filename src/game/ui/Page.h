#pragma once

#include "PageID.h"

namespace ui
{

class Page
{
public:
    EXTERN_TEXT(0x8060197C, Page());
    EXTERN_TEXT(0x80601A04, virtual ~Page());

private:
    PageID m_id;
};

} // namespace ui
