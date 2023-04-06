#pragma once

#include "inventory/item.hpp"

class Consumable: public item {
public:
    void Interact(Entity &entity) override;
}