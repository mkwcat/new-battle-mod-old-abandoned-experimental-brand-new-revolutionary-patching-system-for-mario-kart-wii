#pragma once

namespace Item
{

class ItemSlotTable
{
private:
    static ItemSlotTable* s_instance;

public:
    static ItemSlotTable* Instance()
    {
        return s_instance;
    }

    static void CreateInstance();
    static void DestroyInstance();

    /* 0x807BB9EC */
    void Calc();
};

} // namespace Item
