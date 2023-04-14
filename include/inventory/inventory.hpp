#pragma once

#include <vector>

#include "base/actionlist.hpp"
#include "inventory/item.hpp"

class Inventory {
public:
    Inventory();
    ~Inventory() = default;

    void AddItem(Item &item);
    void RemoveItem(Item &item);
    void ShowInventory();        
    void AddItem(int idx, int cnt);
    ActionList BuildActionList(Stage stage);
    Item Use(int idx);

private:
    static std::vector<Item> list;
    int can_use_item[3];
};