#pragma once

#include "map/room.hpp"
#include "npc/merchant.hpp"

class MerchantRoom: public Room {
public:
    MerchantRoom();
    ~MerchantRoom();
private:
    Merchant *merchant;
};