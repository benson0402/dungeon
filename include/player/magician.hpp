#pragma once

#include "player/player.hpp"

class Magician: public Player {
public:
    Magician() = default;
    Magician(std::string _name);
    ~Magician() = default;

    void ShowStatus() override;
    Action NormalAttack() override;
};