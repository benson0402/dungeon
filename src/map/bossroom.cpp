#include "map/bossroom.hpp"

BossRoom::BossRoom() {
    boss = new Boss(); 
    SetRoomType(RoomType::BOSS);
    SetLeft(nullptr);
    SetRight(nullptr);
    SetLeft(nullptr);
    SetRight(nullptr);
}

BossRoom::~BossRoom() {
    delete this->GetLeft();
    delete this->GetUp();
    delete this->GetDown();
    delete this->GetRight();

    delete boss;
}

void BossRoom::Fight(int _atk, Element element) {
    boss->BeAttack(_atk, element);
    if(boss->IsDead()) {
        SetRoomType(RoomType::EMPTY);
        std::cout << ">>>> Boss is defeated" << std::endl;
    }
}

int BossRoom::FightBack() {
    return boss->FightBack();
}

bool BossRoom::IsDefeated() {
    return boss->IsDead();
}

void BossRoom::ShowRoom() {
    boss->ShowStatus();
}

Element BossRoom::FightBackElement() {
    return boss->GetElementType();
}