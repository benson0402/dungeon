#include "player/magician.hpp"

Magician::Magician(std::string _name) {
    this->SetName(_name); 
    this->SetHp(40);
    this->SetAtk(40);
    this->SetDef(10);
}

void Magician::ShowStatus() {
    std::cout << "[" << this->GetName() << "]" << std::endl;
    std::cout << "> Occupation: Magician" << std::endl;
    std::cout << "> Health: " << this->GetHp() << std::endl;
    std::cout << "> Attack: " << this->GetAtk() << std::endl;
    std::cout << "> Defence: " << this->GetDef() << std:: endl;
    std::cout << "> Money: " << this->GetMoney() << std::endl;
}

Action Magician::NormalAttack() {
    Action ret("q", "Magic Attack");
    return ret;
}