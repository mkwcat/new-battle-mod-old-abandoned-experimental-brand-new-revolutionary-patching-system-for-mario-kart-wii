#pragma once

#include "PageID.h"

namespace UI
{

class Page
{
public:
    EXTERN_TEXT(
      0x8060197C, //
      Page()
    );

    EXTERN_TEXT(
      0x80601A04, //
      virtual ~Page()
    );

    enum class SlideDir {
        SLIDE_FORWARD = 0,
        SLIDE_BACK = 1,
    };

private:
    PageID m_id;
};

} // namespace UI
