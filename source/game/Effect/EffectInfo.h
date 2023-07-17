#pragma once

namespace Effect
{

class EffectInfo
{
public:
    EXTERN_TEXT(
      0x8067B4C8, //
      static EffectInfo* CreateInstance()
    );

    FILL(0, 0x9F4);
};

static_assert(sizeof(EffectInfo) == 0x9F4);

} // namespace Effect
