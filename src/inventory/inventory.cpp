#include "inventory/inventory.hpp"

#include <string>

#include <base/utility.hpp>

Inventory::Inventory() {
    can_use_item[0] = 0;
    can_use_item[1] = 0;
    can_use_item[2] = 0;
}

std::vector<Item> Inventory::list {
    Item("Health Potion", 10000, 0, 0),
    Item("Strength Potion", 0, 10000, 0),
    Item("Armor Potion", 0, 0, 10000),
};

ActionList Inventory::BuildActionList(Stage stage) {
    ActionList ret;
    if(stage == Stage::INVENTORY) {
        if(can_use_item[0])
            ret.Add(Action("1", "Health Potion *" + IntToString(can_use_item[0])));
        if(can_use_item[1])
            ret.Add(Action("2", "Strength Potion *" + IntToString(can_use_item[1])));
        if(can_use_item[2])
            ret.Add(Action("3", "Armor Potion *" + IntToString(can_use_item[2])));
    }
    else {
        ret.Add(Action("i", "Open inventory"));
    }
    return ret;
}

void Inventory::AddItem(int idx, int cnt) {
    can_use_item[idx] += cnt;
}

Item Inventory::Use(int idx) {
    can_use_item[idx]--;
    return list[idx];
}