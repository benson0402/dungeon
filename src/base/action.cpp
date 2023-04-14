#include "base/action.hpp"

#include <iostream>
#include <vector>

Action::Action(std::string _trigger, std::string _description):
    trigger(_trigger), description(_description) {}

bool Action::Valid(std::string str) {
    if(this->trigger == str)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream &os, const Action &action) {
    os << action.trigger << ": " << action.description;
    return os;
}