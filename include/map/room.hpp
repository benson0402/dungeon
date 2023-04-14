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

<<<<<<< HEAD
    virtual void Fight(int _atk, Element element);
    virtual int FightBack();
    virtual Element FightBackElement();
    virtual bool IsDefeated();
    virtual void ShowRoom();
=======
    virtual void Fight(int _atk, Element element) {}
    virtual int FightBack() { return 0; }
    virtual Element FightBackElement() { return Element::NONE; }
    virtual bool IsDefeated() { return 0; }
    virtual void ShowRoom() {}
>>>>>>> de721f871223e6c8f4dd50564e9b3c8d24812375

private:
    RoomType roomtype;
    Room *left, *right, *up, *down;
};