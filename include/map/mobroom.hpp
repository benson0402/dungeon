#pragma once

#include "map/room.hpp"
#include "mob/mob.hpp"

class MobRoom: public Room {
public:
    MobRoom() = default;
    virtual ~MobRoom();

    virtual void Fight(int _atk, Element element) {}
    virtual int FightBack() { return 0; }
    virtual bool IsDefeated() { return 0; }
    virtual void ShowRoom() {}
    virtual Element FightBackElement() { return Element::NONE; }
};