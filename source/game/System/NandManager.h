#pragma once

namespace System
{

class NandManager
{
public:
    static NandManager* s_instance;

    EXTERN_TEXT(
      0x8052BDF4, //
      static NandManager* CreateInstance()
    );

    EXTERN_TEXT(
      0x8052BFF8, //
      void Init()
    );

    FILL(0x0, 0x28);
};

static_assert(sizeof(NandManager) == 0x28);

} // namespace System
