#pragma once

#include <string>

#include "base/object.hpp"

class Entity: public Object {
public:
    Entity() = default;
    Entity(int _hp, int _atk, int _def);
    ~Entity() = default;
    
    void SetHp(int x);
    void SetAtk(int x);
    void SetDef(int x);
    void SetDescription(std::string str);
    int GetHp() const;
    int GetAtk() const;
    int GetDef() const;
    std::string GetDescription() const;
    virtual void ShowStatus() {}

    virtual void BeAttack(int _damage, Element element);
    bool IsDead();

private:
    int hp, atk, def;
    std::string description;

};