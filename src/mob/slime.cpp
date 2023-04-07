#include "mob/slime.hpp"

#include <iostream>

Slime::Slime() {
    SetHp(5);
    SetAtk(5);
    SetDef(0);
}

void Slime::ShowStatus() {
    std::cout << "[Slime]" << std::endl;
    std::cout << "> Element Type: " << this->GetElementType() << std::endl;
    std::cout << "> Health: " << this->GetHp() << std::endl;
    std::cout << "> Attack: " << this->GetAtk() << std::endl;
    std::cout << "> Defence: " << this->GetDef() << std:: endl;
}

void Slime::BeAttack(int _damage, Element element) {
    int cmp = CompareCounter(element, this->GetElementType());
    int hurt = _damage;
    if(cmp == 1) {
        std::cout << ">>>> Counter Attack !" << std::endl;
        hurt *= kCounterAttack;
    }
    else if(cmp == 0) {
        std::cout << ">>>> Normal Attack ~~" << std::endl;
    }
    else if(cmp == -1) {
        std::cout << ">>>> Bad Attack QQ" << std::endl;
        hurt /= kCounterAttack;
    }
    hurt -= this->GetDef();
    if(hurt < 0)
        hurt = 0;  
    this->SetHp(this->GetHp() - hurt);
    std::cout << ">>>> Slime gets " << hurt << " damage" << std::endl;
}