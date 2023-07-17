#pragma once

namespace EGG
{

class Disposer
{
public:
    Disposer(const Disposer&) = delete;
    Disposer(Disposer&&) noexcept = delete;

    Disposer();

    virtual ~Disposer();

private:
    FILL(0x04, 0x10);
};

static_assert(sizeof(Disposer) == 0x10);

} // namespace EGG
