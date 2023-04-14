#include "player/warrior.hpp"

Warrior::Warrior(std::string _name) {
    this->SetName(_name); 
    this->SetHp(80);
    this->SetAtk(20);
    this->SetDef(50);
}

void Warrior::ShowStatus() {
    std::cout << "[" << this->GetName() << "]" << std::endl;
    std::cout << "> Occupation: Warrior" << std::endl;
    std::cout << "> Health: " << this->GetHp() << std::endl;
    std::cout << "> Attack: " << this->GetAtk() << std::endl;
    std::cout << "> Defence: " << this->GetDef() << std::endl;
    std::cout << "> Money: " << this->GetMoney() << std::endl;
}

Action Warrior::NormalAttack() {
    Action ret("q", "Sword Attack");
    return ret;
}