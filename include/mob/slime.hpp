#pragma once

#include "mob/mob.hpp"

class Slime: public Mob {
public:
    Slime();
    ~Slime() = default;

    void ShowStatus() override;
    void BeAttack(int _damage, Element element) override;
};