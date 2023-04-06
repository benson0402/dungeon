#pragma once

#include "base/entity.hpp"
#include "inventory/item.hpp"

class Mob: public Entity {
public:
    Mob() = default;
    ~Mob() = default;

    virtual void ShowStatus() {}
    int GetMoney();
    void SetMoney(int x);
    virtual void BeAttack(int _damage, Element element);

    int FightBack();

private:
    int money = 10;
};