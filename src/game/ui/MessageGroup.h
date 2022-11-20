#pragma once

namespace ui
{

class MessageGroup
{
public:
    MessageGroup();
    ~MessageGroup();

private:
    u8 _00[0x14 - 0x00];
};

static_assert(sizeof(MessageGroup) == 0x14);

} // namespace ui
