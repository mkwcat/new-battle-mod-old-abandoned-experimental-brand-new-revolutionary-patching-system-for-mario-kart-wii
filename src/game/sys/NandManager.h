#pragma once

namespace sys
{

class NandManager
{
public:
    static NandManager* s_instance;

    EXTERN_TEXT(0x8052BFF8, void Init());
};

} // namespace sys
