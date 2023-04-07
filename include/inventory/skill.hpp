#pragma once

#include <string>

#include "inventory/item.hpp"

class Skill: public Item {
public:
    // void Interact(Entity &entity) override;
    Skill() = default;
    Skill(std::string _name, int _atk, Element element);
    ~Skill() = default;
};