#include "base/entity.hpp"

void Entity::SetHp(int x) {
    this->hp = x;
}

void Entity::SetAtk(int x) {
    this->atk = x;
}

void Entity::SetDef(int x) {
    this->def = x;
}

void Entity::SetDescription(std::string str) {
    this->description = str;
}

int Entity::GetHp() const {
    return this->hp;
}

int Entity::GetAtk() const {
    return this->atk;
}

int Entity::GetDef() const {
    return this->def;
}

std::string Entity::GetDescription() const {
    return this->description;
}

void Entity::BeAttack(int _damage, Element element) {
    int cmp = CompareCounter(element, this->GetElementType());
    int hurt = _damage;
    if(cmp == 1)
        hurt *= kCounterAttack;
    else if(cmp == -1)
        hurt /= kCounterAttack;
    this->SetHp(this->GetHp() - hurt);
}

bool Entity::IsDead() {
    return hp <= 0;
}