#include "map/map.hpp"

#include <vector>
#include <iostream>
#include <cassert>

#include "base/utility.hpp"
#include "map/slimeroom.hpp"
#include "map/bossroom.hpp"
#include "map/npcroom.hpp"
#include "map/merchantroom.hpp"

Map::Map() {
    for(int i = 0; i < kMapSize; ++i) {
        for(int j = 0; j < kMapSize; ++j) {
            room[i][j] = new Room();
        }
    }
    
    BuildRoute();
    BuildRoom();
    LinkRoom();
    start_room = room[0][0];
    end_room = room[kMapSize - 1][kMapSize - 1];
    now_room = start_room;
}

Map::~Map() {
    for(int i = 0; i < kMapSize; ++i) {
        for(int j = 0; j < kMapSize; ++j) {
            room[i][j] = nullptr;
            delete room[i][j];
        }
    }
    now_room = nullptr;
    delete now_room;
    start_room = nullptr;
    delete start_room;
    end_room = nullptr;
    delete end_room;
}

std::vector<Location> Map::GenRoute() {
    std::vector<Location> ret;
    Location now(0, 0), end(kMapSize - 1, kMapSize - 1);
    do {
        ret.emplace_back(now);
        int rng = RngNum(0, 1);
        if(rng == 0) {
            if(now.x + 1 <= end.x) {
                now.x++;
            }
            else {
                now.y++;
            }
        }
        else {
            if(now.y + 1 <= end.y) {
                now.y++;
            }
            else {
                now.x++;
            }
        }
    } while(now.x <= end.x && now.y <= end.y);
    return ret;
}

void Map::BuildRoute() {
    int routecount = kMapSize / 2 + 1;
    for(int i = 0; i < routecount; ++i) {
        auto route = GenRoute();
        for(auto& loc : route)
            room[loc.x][loc.y]->SetRoomType(RoomType::EMPTY);
    }
}

void Map::LinkRoom() {
    // link the room
    for(int i = 0; i < kMapSize; ++i) {
        for(int j = 0; j < kMapSize; ++j) {
            Location now(i, j); 
            Location left(i, j - 1);
            Location right(i, j + 1);
            Location up(i - 1, j);
            Location down(i + 1, j);
            if(left.IsValid() && room[left.x][left.y]->GetRoomType() != RoomType::BLOCKED) {
                room[now.x][now.y]->SetLeft(room[left.x][left.y]);
            }
            if(right.IsValid() && room[right.x][right.y]->GetRoomType() != RoomType::BLOCKED) {
                room[now.x][now.y]->SetRight(room[right.x][right.y]);
            }
            if(up.IsValid() && room[up.x][up.y]->GetRoomType() != RoomType::BLOCKED) {
                room[now.x][now.y]->SetUp(room[up.x][up.y]);
            }
            if(down.IsValid() && room[down.x][down.y]->GetRoomType() != RoomType::BLOCKED) {
                room[now.x][now.y]->SetDown(room[down.x][down.y]);
            }
        }
    }
}
void Map::BuildRoom() {
    // Assign RoomType

    //// Asssign Boss Room
    {
        int i = kMapSize - 1;
        int j = kMapSize - 1;
        room[i][j] = new BossRoom();
    }

    //// Assign Mob Room
    for(int i = 0; i < kMapSize; ++i) {
        for(int j = 0; j < kMapSize; ++j) {
            if(!(i == 0 && j == 0) && room[i][j]->GetRoomType() == RoomType::EMPTY) {
                int rng = RngNum(0, 100);
                if(rng <= kMobRoomOdds)
                    room[i][j] = new SlimeRoom();
            }
        }
    }

    //// Assign NPC Room 
    {
        int i = RngNum(0, kMapSize - 1);
        int j = RngNum(0, kMapSize - 1);
        while((i == 0 && j == 0) || room[i][j]->GetRoomType() != RoomType::EMPTY) {
            i = RngNum(0, kMapSize - 1);
            j = RngNum(0, kMapSize - 1);
        }
        room[i][j] = new MerchantRoom();
    }

    
} 

void Map::ShowMap() {

    std::cout << "[MiniMap]" << std::endl;

    for(int i = 0; i < kMapSize; ++i) {
        for(int j = 0; j < kMapSize; ++j) {
            if(now_room == room[i][j]) 
                std::cout << '@';
            else
                std::cout << room[i][j]->SymbolOfRoom();
        }
        std::cout << std::endl;
    }

    Room::ShowRoomIcon();
}

Room* Map::GetNowRoom() {
    return this->now_room;
}

ActionList Map::BuildActionList(Stage stage) {
    ActionList ret;
    if(stage == Stage::MOVING) {
        if(now_room->GetUp() != nullptr)
            ret.Add(action[0]);
        if(now_room->GetLeft() != nullptr)
            ret.Add(action[1]);
        if(now_room->GetDown() != nullptr)
            ret.Add(action[2]);
        if(now_room->GetRight() != nullptr)
            ret.Add(action[3]);

        if(now_room->GetRoomType() == RoomType::MOB)
            ret.Add(Action("e", "Enter Mob's Room"));
        if(now_room->GetRoomType() == RoomType::NPC)
            ret.Add(Action("e", "Enter NPC's Room"));
        if(now_room->GetRoomType() == RoomType::BOSS)
            ret.Add(Action("e", "Enter Boss's Room"));
    }
    ret.Add(now_room->BuildActionList(stage));
    return ret;
}

std::vector<Action> Map::action = std::vector<Action>{
    Action("w", "Move Up"),
    Action("a", "Move Left"),
    Action("s", "Move Down"),
    Action("d", "Move Right"),
    // Action("e", "Enter Room"),
};

void Map::Move(std::string str) {
    if(str == "w")
        now_room = now_room->GetUp();
    else if(str == "a")
        now_room = now_room->GetLeft();
    else if(str == "s")
        now_room = now_room->GetDown();
    else if(str == "d")
        now_room = now_room->GetRight();
}

Stage Map::Interact() {
    if(now_room->GetRoomType() == RoomType::MOB) {
        return Stage::FIGHTING;
    }
    else if(now_room->GetRoomType() == RoomType::BOSS) {
        return Stage::FIGHTING;
    }
    else if(now_room->GetRoomType() == RoomType::NPC) {
        return Stage::BUYING;
    }
}

Stage Map::Fight(int _atk, Element element) {
    now_room->Fight(_atk, element);
    if(now_room->IsDefeated()) {
        if(now_room->GetRoomType() == RoomType::BOSS)
            return Stage::WIN;
        else
            return Stage::MOVING;
    }
    else {
        return Stage::FIGHTING;
    }
}

void Map::ShowNowRoom() {
    now_room->ShowRoom();
}