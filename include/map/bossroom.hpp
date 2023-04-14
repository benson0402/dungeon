#pragma once

#include "map/mobroom.hpp"
#include "mob/boss.hpp"

class BossRoom: public MobRoom {
public:
    BossRoom();
    ~BossRoom();

    void Fight(int _atk, Element element) override;
    int FightBack() override;
    bool IsDefeated() override; 
    void ShowRoom() override;
    virtual Element FightBackElement() override;

private:
    Boss *boss;

};
