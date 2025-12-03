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

    enum EFadeDirection {
        FADE_DIRECTION_FORWARD = 0,
        FADE_DIRECTION_BACK = 1,
    };

private:
    EPageID m_id;
};

} // namespace UI
