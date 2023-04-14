#pragma once

#include "player/player.hpp"

class Archer: public Player {
public:
    Archer() = default;
    Archer(std::string _name);
    ~Archer() = default;

    void ShowStatus() override;
    Action NormalAttack() override;

};