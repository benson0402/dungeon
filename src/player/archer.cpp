#include "player/archer.hpp"

Archer::Archer(std::string _name) {
    this->SetName(_name); 
    this->SetHp(20);
    this->SetAtk(80);
    this->SetDef(10);
}

void Archer::ShowStatus() {
    std::cout << "[" << this->GetName() << "]" << std::endl;
    std::cout << "> Occupation: Archer" << std::endl;
    std::cout << "> Health: " << this->GetHp() << std::endl;
    std::cout << "> Attack: " << this->GetAtk() << std::endl;
    std::cout << "> Defence: " << this->GetDef() << std:: endl;
    std::cout << "> Money: " << this->GetMoney() << std::endl;
}

Action Archer::NormalAttack() {
    Action ret("q", "Bow Attack");
    return ret;
}