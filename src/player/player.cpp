#include "player/player.hpp"

#include <iostream>

#include "base/entity.hpp"

Player::Player(): money(0) {
    can_use_skill[0] = 0;
    can_use_skill[1] = 0;
    can_use_skill[2] = 0;
}

ActionList Player::occupation = ActionList(std::vector<Action>{
    Action("1", "Archer"),
    Action("2", "Magician"),
    Action("3", "Warrior"),
});

std::vector<Skill> Player::skill = {
    // Skill(Name, atk, element);
    Skill("Fire Exploooooosion", 10000, Element::FIRE),
    Skill("Water Booooomb", 10000, Element::WATER),
    Skill("Grass grooooooow", 10000, Element::GRASS),
};

int Player::GetMoney() {
    return money;
}

void Player::AddMoney(int x) {
    money += x;
}

void Player::SetMoney(int x) {
    money = x;
}
Action Player::NormalAttack() {
    Action ret;
    return ret;
}

ActionList Player::BuildActionList(Stage stage) {
    ActionList ret;
    if(stage == Stage::FIGHTING) {
        ret.Add(this->NormalAttack());
        if(can_use_skill[0])
            ret.Add(Action("z", skill[0].GetName()));
        if(can_use_skill[1])
            ret.Add(Action("x", skill[1].GetName()));
        if(can_use_skill[2])
            ret.Add(Action("c", skill[2].GetName()));
    }
    return ret;
}

void Player::ShowStatus() {
    std::cout << "[" << this->GetName() << "]" << std::endl;
    std::cout << "> Occupation: None" << std::endl;
    std::cout << "> Health: " << this->GetHp() << std::endl;
    std::cout << "> Attack: " << this->GetAtk() << std::endl;
    std::cout << "> Defence: " << this->GetDef() << std:: endl;
}
    
void Player::SetSkill(int idx) {
    can_use_skill[idx] = 1;
}

void Player::BeAttack(int _damage, Element element) {
    int cmp = CompareCounter(element, this->GetElementType());
    int hurt = _damage;
    if(cmp == 1) {
        std::cout << ">>>> Get Counter Attack QQ!" << std::endl;
        hurt *= kCounterAttack;
    }
    else if(cmp == 0) {
        std::cout << ">>>> Get Normal Attack ~~" << std::endl;
    }
    else if(cmp == -1) {
        std::cout << ">>>> Get Bad Attack !" << std::endl;
        hurt /= kCounterAttack;
    }
    hurt -= this->GetDef();
    if(hurt < 0)
        hurt = 0;  
    this->SetHp(this->GetHp() - hurt);
    std::cout << ">>>> " << this->GetName() << " gets " << hurt << " damage" << std::endl;

}