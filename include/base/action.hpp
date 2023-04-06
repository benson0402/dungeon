#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "base/stage.hpp"


class Action {
public:
    Action() = default;
    Action(std::string _trigger, std::string _description);
    ~Action() = default;

    bool Valid(std::string str);
    
    friend std::ostream& operator<<(std::ostream &os, const Action &action);
private:
    std::string trigger, description;
};
