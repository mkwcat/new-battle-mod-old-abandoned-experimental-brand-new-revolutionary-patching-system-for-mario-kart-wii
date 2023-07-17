#pragma once

namespace Item
{

class ItemObjPowBlockDirector
{
private:
    /* 0x809C3660 */
    static ItemObjPowBlockDirector* s_instance;

public:
    static ItemObjPowBlockDirector* Instance()
    {
        return s_instance;
    }

    /* 0x807B1BC0 */
    static void CreateInstance();

    /* 0x807B1C70 */
    static void DestroyInstance();

    /* 0x807B1CA8 */
    static void Init();

    /* 0x807B22F8 */
    void Calc();
};

} // namespace Item
