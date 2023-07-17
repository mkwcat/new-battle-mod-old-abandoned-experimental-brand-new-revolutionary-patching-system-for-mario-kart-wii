#pragma once

namespace Item
{

class ItemObj
{
public:
    /* 0x8079D8BC */
    ItemObj();

    ~ItemObj() = default;

    /* 0x8079E300 */
    virtual void VT_0x08();

    /* 0x8079D804 */
    virtual void CreateModel();

    /* 0x807A05D0 */
    virtual void VT_0x10();

    /* 0x807A05F4 */
    virtual void VT_0x14();

    /* 0x8079D9FC */
    virtual void DisplayModel();

    /* 0x8079DA9C */
    virtual void VT_0x1C();

    /* 0x8079DCB4 */
    virtual void VT_0x20();

    /* 0x8079DCBC */
    virtual void VT_0x24();

    /* 0x8079DD6C */
    virtual void VT_0x28();

    /* 0x8079DD70 */
    virtual void VT_0x2C();

    /* 0x8079DEE4 */
    virtual void VT_0x30();

    /* 0x8079E1F0 */
    virtual void VT_0x34();

    static void UNDEF_8079F8B4();

    /* 0x8079FF5C */
    void CreateModelInner(
      const char* brresName, const char* param_2, u32 param_3, u32 param_4,
      u32 param_5
    );

    void UNDEF_807A3618();

private:
    FILL(0x004, 0x188);
};

static_assert(sizeof(ItemObj) == 0x188);

} // namespace Item
