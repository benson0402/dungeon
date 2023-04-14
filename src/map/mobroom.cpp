#include "map/mobroom.hpp"

MobRoom::~MobRoom() {
    delete this->GetLeft();
    delete this->GetUp();
    delete this->GetDown();
    delete this->GetRight();
}