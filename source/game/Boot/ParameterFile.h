#pragma once

namespace Boot
{

class ParameterFile
{
public:
    virtual ~ParameterFile() = 0;

    FILL(0x04, 0x1C);
};

static_assert(sizeof(ParameterFile) == 0x1C);

} // namespace Boot
