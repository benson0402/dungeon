#include "map/slimeroom.hpp"

SlimeRoom::SlimeRoom() {
    slime = new Slime(); 
    SetRoomType(RoomType::MOB);
    SetLeft(nullptr);
    SetRight(nullptr);
    SetLeft(nullptr);
    SetRight(nullptr);
}

SlimeRoom::~SlimeRoom() {
    delete this->GetLeft();
    delete this->GetUp();
    delete this->GetDown();
    delete this->GetRight();

    delete slime;
}

void SlimeRoom::Fight(int _atk, Element element) {
    slime->BeAttack(_atk, element);
    if(slime->IsDead()) {
        SetRoomType(RoomType::EMPTY);
        std::cout << ">>>> Slime is defeated" << std::endl;
    }
}

int SlimeRoom::FightBack() {
    return slime->FightBack();
}

bool SlimeRoom::IsDefeated() {
    return slime->IsDead();
}

void SlimeRoom::ShowRoom() {
    slime->ShowStatus();
}

Element SlimeRoom::FightBackElement() {
    return slime->GetElementType();
}