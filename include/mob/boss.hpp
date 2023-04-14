#pragma once

#include "mob/mob.hpp"

class Boss: public Mob {
public:
    Boss();
    ~Boss() = default;

    void ShowStatus() override;
    void BeAttack(int _damage, Element element) override;
};