#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "base/stage.hpp"
#include "base/action.hpp"
#include "player/player.hpp"
#include "mob/mob.hpp"
#include "npc/merchant.hpp"
#include "inventory/inventory.hpp"
#include "inventory/skill.hpp"
#include "map/map.hpp"

class Command {
public:
    Command();
    ~Command();

    std::string Input();
    void Output(std::string path);
    void Start(Player *&player);
    Stage NowStage();
    void ShowStatus(Entity *entity);
    void ShowNowRoom(Map *map); 
    void ShowMap(Map *&map);
    void ShowActions(Player *player, Map *map, Inventory *inv);
    void ShowNowStage();
    void BuildActionList(Stage stage, Player *player, Map *map, Inventory *inv);
    bool DoAction(std::string str, Player *&player, Map *&map, Inventory *&inv);
    void Buy(std::string str, Player *&player, Inventory *&inv);
    Stage Skill(std::string str, Player *&player, Map *map);
    Stage Fight(Player *&player, Map *&map, int _atk, Element element);
    void Use(std::string str, Player *&player, Inventory *&inv);

private:
    ActionList *actionlist;
    std::stack<Stage> stagelog;
};