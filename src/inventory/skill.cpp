#include "inventory/skill.hpp"


Skill::Skill(std::string _name, int _atk, Element element) {
    this->SetName(_name);
    this->SetAtk(_atk);
    this->SetElementType(element);
}