#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "base/stage.hpp"
#include "base/action.hpp"

class ActionList {
public:
    ActionList() = default;
    ActionList(std::vector<Action> vec);
    ~ActionList() = default;

    void Clear();
    void Add(Action action);
    void Add(ActionList actionlist);
    void Show();
    bool Check(std::string str); 

    std::vector<Action> list;
};