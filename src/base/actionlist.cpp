#include "base/actionlist.hpp"

#include <iostream>
#include <vector>

#include "player/player.hpp"
#include "map/map.hpp"
#include "inventory/inventory.hpp"

ActionList::ActionList(std::vector<Action> vec) {
    this->list = vec;
}

void ActionList::Clear() {
    this->list.clear();
}

void ActionList::Add(Action action) {
    this->list.emplace_back(action);
}

void ActionList::Add(ActionList actionlist) {
    for(auto& i : actionlist.list) {
        Add(i);
    }
}

void ActionList::Show() {
    std::cout << "[Availabe Actions]" << std::endl;
    for(auto& i : this->list) {
        std::cout << i << std::endl;
    }
}

bool ActionList::Check(std::string str) {
    for(auto& i : this->list) {
        if(i.Valid(str))
            return true;
    }
    return false;
}