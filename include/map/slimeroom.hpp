#pragma once

#include "map/mobroom.hpp"
#include "mob/slime.hpp"

class SlimeRoom: public MobRoom {
public:
    SlimeRoom();
    ~SlimeRoom();

    void Fight(int _atk, Element element) override;
    int FightBack() override;
    bool IsDefeated() override; 
    void ShowRoom() override;
    virtual Element FightBackElement() override;

private:
    Slime *slime;

};
