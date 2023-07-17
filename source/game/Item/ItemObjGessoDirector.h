#pragma once

namespace Item
{

class ItemObjGessoDirector
{
private:
    /* 0x809C3648 */
    static ItemObjGessoDirector* s_instance;

public:
    static ItemObjGessoDirector* Instance()
    {
        return s_instance;
    }

    /* 0x807A8F04 */
    static void CreateInstance();

    /* 0x807A8FA0 */
    static void DestroyInstance();

    /* 0x807A8FD8 */
    static void Init();

    /* 0x807A92B0 */
    void Calc();
};

} // namespace Item
