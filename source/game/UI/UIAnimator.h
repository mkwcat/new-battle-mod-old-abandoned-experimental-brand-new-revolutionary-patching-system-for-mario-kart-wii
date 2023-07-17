#pragma once

namespace UI
{

class Group
{
public:
    void SetAnimation(u32 animationId, f32 frame);
    void SetAnimationInactive(u32 animationId, f32 frame);

    u8 _00[0x35 - 0x00];
    bool m_isActive;
    u8 _36[0x38 - 0x36];
    u32 m_currentAnimation;
    u8 _3C[0x44 - 0x3C];
};

static_assert(sizeof(Group) == 0x44);

class UIAnimator
{
public:
    UIAnimator();
    ~UIAnimator();

    Group* GetGroup(u32 groupId);
    bool IsActive(u32 groupId);
    u32 GetAnimation(u32 groupId);
    void SetAnimation(u32 groupId, u32 animationId, f32 frame);
    void SetAnimationInactive(u32 groupId, u32 animationId, f32 frame);

private:
    u8 _00[0x10 - 0x00];
};

static_assert(sizeof(UIAnimator) == 0x10);

} // namespace UI
