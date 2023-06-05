#pragma once

namespace ui
{

class MessageGroup
{
public:
    EXTERN_TEXT(
      0x805F8B34, //
      MessageGroup()
    );

    EXTERN_TEXT(
      0x805F8B50, //
      ~MessageGroup()
    );

    EXTERN_TEXT(
      0x805F8B90, //
      void Load(const char* bmgName)
    );

    EXTERN_TEXT(
      0x805F8C00, //
      void Load(u8* bmgData)
    );

private:
    u8 _00[0x14 - 0x00];
};

static_assert(sizeof(MessageGroup) == 0x14);

} // namespace ui
