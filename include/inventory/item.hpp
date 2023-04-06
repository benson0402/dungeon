#pragma once

#include "base/entity.hpp"

struct Item: public Entity {
public:
    Item() = default;
    Item(std::string _name, int _hp, int _atk, int _def);
    ~Item() = default;

    void SetPrice(int x);
    int GetPrice(int x);
    bool NeedRemove();
    // virtual void Interact(Entity &entity);
    
    bool operator==(Item &rhs);
    bool operator<(Item &rhs);

private:
    int price; 
    bool need_remove; 

};
