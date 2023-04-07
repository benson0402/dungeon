#include "map/room.hpp"

#include <iostream>

Room::Room(): roomtype(RoomType::BLOCKED), left(nullptr), right(nullptr),
    up(nullptr), down(nullptr) {}    

Room::~Room() {
    delete left;
    delete right;
    delete up;
    delete down;
}

void Room::SetRoomType(RoomType roomtype) {
    this->roomtype = roomtype;
}

void Room::SetLeft(Room *ptr) {
    this->left = ptr;
}

void Room::SetRight(Room *ptr) {
    this->right = ptr;
}

void Room::SetUp(Room *ptr) {
    this->up = ptr;
}

void Room::SetDown(Room *ptr) {
    this->down = ptr;
}

RoomType Room::GetRoomType() const {
    return this->roomtype;
}

Room* Room::GetLeft() {
    return this->left;
}

Room* Room::GetRight() {
    return this->right;
}

Room* Room::GetUp() {
    return this->up;
}

Room* Room::GetDown() {
    return this->down;
}

char Room::SymbolOfRoom() const {
    if(this->roomtype == RoomType::BLOCKED)
        return '*';
    else if(this->roomtype == RoomType::EMPTY)
        return '_';
    else if(this->roomtype == RoomType::MOB)
        return 'M';
    else if(this->roomtype == RoomType::BOSS)
        return 'B';
    else if(this->roomtype == RoomType::NPC)
        return 'N';
    return 'X';
}

ActionList Room::BuildActionList(Stage stage) {
    ActionList ret;
    if(stage == Stage::BUYING) {
        ret.Add(Action("buy1", "Buy Skill Book: Fire Exploooooosion $1"));
        ret.Add(Action("buy2", "Buy Skill Book: Water Booooomb $1"));
        ret.Add(Action("buy3", "Buy Skill Book: Grass grooooooow $1"));
        ret.Add(Action("buy4", "Potion: Health Potion $1"));
        ret.Add(Action("buy5", "Potion: Strength Potion $1"));
        ret.Add(Action("buy6", "Potion: Armor Potion $1"));

    }
    return ret;
}

void Room::ShowRoomIcon() {
    std::cout << "[Minimap Icon]" << std::endl;
    std::cout << "* -> Room is blocked" << std::endl;
    std::cout << "_ -> Room is empty" << std::endl;
    std::cout << "M -> Room has mob" << std::endl;
    std::cout << "B -> Room has boss" << std::endl;
    std::cout << "N -> Room has NPC" << std::endl;
}