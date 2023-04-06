#pragma once

#include <vector>

#include "base/actionlist.hpp"
#include "base/entity.hpp"
#include "inventory/skill.hpp"

class Player: public Entity {
public:
    Player();
    virtual ~Player() = default;

    int GetMoney();
    void AddMoney(int x);
    void SetMoney(int x);
    virtual void ShowStatus();
    virtual Action NormalAttack();
    ActionList BuildActionList(Stage stage);
    void SetSkill(int idx);
    void BeAttack(int _damage, Element element) override;

    static ActionList occupation;
    static std::vector<Skill> skill;

private:
    int money; 
    bool can_use_skill[3];
};