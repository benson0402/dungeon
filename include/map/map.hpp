#pragma once

#include <vector>

#include "base/stage.hpp"
#include "base/actionlist.hpp"
#include "map/room.hpp"

constexpr int kMapSize = 10;
constexpr int kMobRoomOdds = 40; // 0-100 %

struct Location {
    int x, y;
    Location(int _x, int _y):
        x(_x), y(_y) {}

    bool IsValid() {
        return 0 <= x && x < kMapSize && 0 <= y && y < kMapSize;
    }
};

class Map {
public:
    Map();
    ~Map();

    std::vector<Location> GenRoute();
    void BuildRoute();
    void LinkRoom();
    void BuildRoom();
    void BuildMap();
    void ShowMap();
    Room* GetNowRoom();
    ActionList BuildActionList(Stage stage);
    void Move(std::string str);
    Stage Interact();
    Stage Fight(int _atk, Element element);
    void ShowNowRoom();

private:
    Room *room[kMapSize][kMapSize];
    Room *now_room, *start_room, *end_room;
    
    static std::vector<Action> action;
};