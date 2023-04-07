#pragma once

#include "player/player.hpp"

class Warrior: public Player {
public:
    Warrior() = default;
    Warrior(std::string _name);
    ~Warrior() = default;

    void ShowStatus() override;
    Action NormalAttack() override;
};