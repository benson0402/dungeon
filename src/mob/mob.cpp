#include "mob/mob.hpp"

int Mob::GetMoney() {
    return money;
}

void Mob::SetMoney(int x) {
    money = x;
}

int Mob::FightBack() {
    return this->GetAtk();
}

void Mob::BeAttack(int _damage, Element element) {
    int cmp = CompareCounter(element, this->GetElementType());
    int hurt = _damage;
    if(cmp == 1)
        hurt *= kCounterAttack;
    else if(cmp == -1)
        hurt /= kCounterAttack;
    this->SetHp(this->GetHp() - hurt);
}