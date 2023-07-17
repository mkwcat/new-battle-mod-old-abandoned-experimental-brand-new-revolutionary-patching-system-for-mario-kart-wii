#pragma once

namespace UI
{

class FontManager
{
public:
    EXTERN_TEXT(
      0x805D13C4, //
      static FontManager* CreateInstance()
    );

    FILL(0x0, 0x18);
};

static_assert(sizeof(FontManager) == 0x18);

} // namespace UI
