#include "inventory/item.hpp"

// void SetPrice(int x);
// int GetPrice(int x);
// bool NeedRemove();
// virtual void Interact(Entity &entity);

Item::Item(std::string _name, int _hp, int _atk, int _def) {
    this->SetName(_name);
    this->SetHp(_hp);
    this->SetAtk(_atk);
    this->SetDef(_def);
}

bool Item::operator==(Item &rhs) {
    return this->price == rhs.price;
}

bool Item::operator<(Item &rhs) {
    return this->price < rhs.price;
}
