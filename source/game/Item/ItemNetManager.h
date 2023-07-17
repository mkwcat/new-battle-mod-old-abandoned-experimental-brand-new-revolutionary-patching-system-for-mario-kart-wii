#pragma once

namespace Item
{

class ItemNetManager
{
private:
    /* 0x809C3620 */
    static ItemNetManager* s_instance;

public:
    static ItemNetManager* Instance()
    {
        return s_instance;
    }

    static void CreateInstance();
    static void DestroyInstance();

    /* 0x8079BD94 */
    void CalcBefore();

    /* 0x8079BED0 */
    void CalcAfter();
};

} // namespace Item
