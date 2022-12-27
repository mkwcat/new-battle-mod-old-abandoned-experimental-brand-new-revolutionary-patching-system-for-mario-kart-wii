#pragma once

namespace util
{

class Random
{
public:
    EXTERN_TEXT(0x80555464, Random());
    EXTERN_TEXT(0x805554D0, void SeedAuto());
    EXTERN_TEXT(0x80555514, Random(u32 seed));
    EXTERN_TEXT(0x80555538, virtual ~Random());

    EXTERN_TEXT(0x80555578, u32 GetInt());
    EXTERN_TEXT(0x805555CC, u32 GetInt(u32 limit));

    EXTERN_TEXT(0x80555628, f32 GetFloat());
    EXTERN_TEXT(0x805556A8, f32 GetFloat(f32 limit));

private:
    FILL(0x4, 0x8); // Padding for the 8 byte boundary
    /* 0x08 */ u64 m_ctx1;
    /* 0x10 */ u64 m_ctx2;
};

static_assert(sizeof(Random) == 0x18);

} // namespace util
