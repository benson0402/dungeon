#pragma once

#include "base/element.hpp"
#include "base/stage.hpp"
#include "base/action.hpp"
#include "base/actionlist.hpp"

enum class RoomType {
    // NOW @
    BLOCKED, // *
    EMPTY, // _
    MOB, // M
    BOSS, // B
    NPC, // N
};

class Room {
public:
    Room();
    virtual ~Room();

    void SetRoomType(RoomType roomtype);
    void SetLeft(Room *ptr);
    void SetRight(Room *ptr);
    void SetUp(Room *ptr);
    void SetDown(Room *ptr);
    RoomType GetRoomType() const;
    Room* GetLeft();
    Room* GetRight();
    Room* GetUp();
    Room* GetDown();
    char SymbolOfRoom() const;
    ActionList BuildActionList(Stage stage);
    static void ShowRoomIcon();

    virtual void Fight(int _atk, Element element) {}
    virtual int FightBack() { return 0; }
    virtual Element FightBackElement() { return Element::NONE; }
    virtual bool IsDefeated() { return 0; }
    virtual void ShowRoom() {}

private:
    RoomType roomtype;
    Room *left, *right, *up, *down;
};