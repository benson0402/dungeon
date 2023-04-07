#pragma once

#include "inventory/item.hpp"

class Consumable: public Item {
public:
    void Interact(Entity &entity) override;
}