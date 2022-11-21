#pragma once

#include "MessageGroup.h"

namespace ui
{

class SystemMessageGroup : public MessageGroup
{
public:
    EXTERN_TEXT(0x80637998, SystemMessageGroup());
    EXTERN_TEXT(0x806379C8, ~SystemMessageGroup());

    void Load(); // Replaced
    EXTERN_TEXT(0x80637A8C, wchar_t* GetMessage(int msgId));
};

static_assert(sizeof(SystemMessageGroup) == 0x14);

} // namespace ui
