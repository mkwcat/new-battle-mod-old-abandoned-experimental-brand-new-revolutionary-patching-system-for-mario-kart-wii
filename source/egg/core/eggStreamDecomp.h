#pragma once

namespace EGG
{

class StreamDecomp
{
public:
    virtual bool init(void* dst, u32 maxCompressedSize) = 0;
    virtual bool decomp(const void* src, u32 len) = 0;
    virtual u32 getHeaderSize() = 0;
    virtual u32 getUncompressedSize(const void* src) = 0;
};

class StreamDecompLZ : public StreamDecomp
{
public:
    StreamDecompLZ() = default;
    ~StreamDecompLZ() = default;

    EXTERN_TEXT(
      0x80242498, bool init(void* dst, u32 maxCompressedSize) override
    );
    EXTERN_TEXT(0x802424C8, bool decomp(const void* src, u32 len) override);
    EXTERN_TEXT(0x802424F4, u32 getHeaderSize() override);
    EXTERN_TEXT(0x802424FC, u32 getUncompressedSize(const void* src) override);

private:
    FILL(0x4, 0x24);
};

static_assert(sizeof(StreamDecompLZ) == 0x24);

} // namespace EGG
