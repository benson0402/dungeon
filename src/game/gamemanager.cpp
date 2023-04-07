#include "game/gamemanager.hpp"

#include "base/stage.hpp"
#include "game/command.hpp"
#include "map/map.hpp"

GameManager::GameManager() {
    map = new Map();
    player = new Player();
    inv = new Inventory();
}

GameManager::~GameManager() {
    delete map;
    delete player;
    delete inv;
}

void GameManager::Start() {

    system("clear");
    command.Start(player);
    system("sleep 1");

    Stage nowstage = command.NowStage();
    bool valid = 1;
    std::string str;
    do {
        system("clear");

        if(str != "") {
            valid = command.DoAction(str, player, map, inv);
            nowstage = command.NowStage();
            if(!valid)
                std::cout << ">>>> Please Input Valid Action" << std::endl;
            else if(nowstage == Stage::WIN || nowstage == Stage::LOSE)
                break;
        }

        command.ShowNowStage();

        command.ShowMap(map);
        std::cout << std::string(20, '#') << std::endl;

        command.ShowStatus(player);
        std::cout << std::string(20, '#') << std::endl;

        if(nowstage == Stage::FIGHTING) {
            command.ShowNowRoom(map);
            std::cout << std::string(20, '#') << std::endl;
        }
        command.ShowActions(player, map, inv);
        str = command.Input();

    } while(nowstage != Stage::WIN || nowstage != Stage::LOSE);

    if(nowstage == Stage::WIN) {
        command.Output("text/win.txt");
    }
    else if(nowstage == Stage::LOSE) {
        command.Output("text/lose.txt");
    }

}

