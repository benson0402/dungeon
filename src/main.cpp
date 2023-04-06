#include <iostream>
#include <cstdlib>

#include "game/gamemanager.hpp"

int main() {
    system("clear");
    std::cout << "Success" << std::endl;

    GameManager gamemanager;
    gamemanager.Start();
}