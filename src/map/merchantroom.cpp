#include "map/merchantroom.hpp"

MerchantRoom::MerchantRoom() {
    merchant = new Merchant();
    SetRoomType(RoomType::NPC);
    SetLeft(nullptr);
    SetRight(nullptr);
    SetLeft(nullptr);
    SetRight(nullptr);
}

MerchantRoom::~MerchantRoom() {
    delete this->GetLeft();
    delete this->GetUp();
    delete this->GetDown();
    delete this->GetRight();
    delete merchant;
}