#include "mob/boss.hpp"

#include <iostream>

#include "base/element.hpp"

Boss::Boss() {
    SetElementType(RngElement());
    SetHp(1000);
    SetAtk(5);
    SetDef(0);
}

void Boss::ShowStatus() {
    std::cout << "[Boss]" << std::endl;
    std::cout << "> Element Type: " << this->GetElementType() << std::endl;
    std::cout << "> Health: " << this->GetHp() << std::endl;
    std::cout << "> Attack: " << this->GetAtk() << std::endl;
    std::cout << "> Defence: " << this->GetDef() << std:: endl;
}

void Boss::BeAttack(int _damage, Element element) {
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
    std::cout << ">>>> Boss gets " << hurt << " damage" << std::endl;
}