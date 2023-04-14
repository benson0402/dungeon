#pragma once

#include "base/action.hpp"
#include "game/command.hpp"
#include "inventory/inventory.hpp"
#include "map/map.hpp"


class GameManager {
public:
    GameManager();
    ~GameManager();

    void Start();
    
private:
    Command command;
    Map *map;
    Player *player;
    Inventory *inv;
};