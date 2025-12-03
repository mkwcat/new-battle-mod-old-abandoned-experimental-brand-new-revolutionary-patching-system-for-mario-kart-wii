#pragma once

#include "SectionID.h"

namespace UI
{

class SaveManagerProxy
{
public:
    /* 0x806209E8 */
    SaveManagerProxy();

    /* 0x80620B04 */
    void Init();

    /* 0x80620C5C */
    ESectionID GetErrorSection();

private:
    FILL(0x000, 0x128);
};

static_assert(sizeof(SaveManagerProxy) == 0x128);

} // namespace UI
