#include "game/command.hpp"

#include <iostream>
#include <fstream>

#include "player/player.hpp"
#include "player/archer.hpp"
#include "player/magician.hpp"
#include "player/warrior.hpp"

Command::Command() {
    actionlist = new ActionList();
    stagelog.push(Stage::MOVING);
}

Command::~Command() {
    actionlist = nullptr;
    delete actionlist;
}

std::string Command::Input() {
    std::string str;
    std::cout << "Please Input an action: ";
    std::cin >> str;
    return str;
}

void Command::Output(std::string path) {
    std::string str;
    std::ifstream file(path);
    if(file.is_open()) {
        while(getline(file, str)) {
            std::cout << str << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "FILE NOT FOUND" << std::endl;
    }
}

void Command::Start(Player *&player) {

    Output("text/welcome.txt");

    std::string name, str;
    std::cout << "Please Enter Your Name: ";
    std::cin >> name; 

    actionlist->Clear();
    actionlist->Add(Player::occupation);
    do {
        actionlist->Show();
        std::cout << "Please Choose Your Occupation: ";
        std::cin >> str;
    } while(!actionlist->Check(str));

    if(str == "1") {
        std::cout << "You are now an Archer!\n";
        player = new Archer(name);
    }
    else if(str == "2") {
        std::cout << "You are now a Magician!\n";
        player = new Magician(name);
    }
    else if(str == "3") {
        std::cout << "You are now a Warrior!\n";
        player = new Warrior(name);
    }
}

Stage Command::NowStage() {
    return stagelog.top();
}

void Command::ShowStatus(Entity *entity) {
    entity->ShowStatus();
}

void Command::ShowNowRoom(Map *map) {
    map->ShowNowRoom();
}

void Command::ShowMap(Map *&map) {
    map->ShowMap();
}

void Command::ShowActions(Player *player, Map *map, Inventory *inv) {
    BuildActionList(stagelog.top(), player, map, inv);
    actionlist->Show();
}

void Command::ShowNowStage() {
    Stage nowstage = stagelog.top();
    if(nowstage == Stage::BUYING) {
        Output("text/BUYING.txt");
    }
    else if(nowstage == Stage::FIGHTING) {
        Output("text/FIGHTING.txt");
    }
    else if(nowstage == Stage::INVENTORY) {
        Output("text/INVENTORY.txt");
    }
    else if(nowstage == Stage::MOVING) {
        Output("text/MOVING.txt");
    }
}

void Command::BuildActionList(Stage stage, Player *player, Map *map, Inventory *inv) {
    actionlist->Clear();
    actionlist->Add(player->BuildActionList(stage));
    actionlist->Add(map->BuildActionList(stage));
    actionlist->Add(inv->BuildActionList(stage));

    if(stage != Stage::MOVING)
        actionlist->Add(Action("b", "Back/Leave"));
}

bool Command::DoAction(std::string str, Player *&player, Map *&map, Inventory *&inv) {
    BuildActionList(stagelog.top(), player, map, inv);

    if(actionlist->Check(str) == false)
        return false;
    if(str == "w" || str == "a" || str == "s" || str == "d") {
        map->Move(str);
    }
    else if(str == "q") {
        Stage stage = Fight(player, map, player->GetAtk(), player->GetElementType());
        stagelog.emplace(stage);
    }
    else if(str == "e") {
        Stage stage = map->Interact();
        stagelog.emplace(stage); 
    }
    else if(str == "b") {
        stagelog.pop();
    }
    else if(str == "i") {
        stagelog.emplace(Stage::INVENTORY);
    }
    else if(str == "z" || str == "x" || str == "c") {
        Stage stage = Skill(str, player, map); 
        stagelog.emplace(stage);
    }
    else if(str == "1" || str == "2" || str == "3") {
        Use(str, player, inv);
    }
    else if(str == "buy1" || str == "buy2" || str == "buy3" ||
        str == "buy4" || str == "buy5" || str == "buy6") {
        Buy(str, player, inv);
    }
   
    return true;
} 

void Command::Buy(std::string str, Player *&player, Inventory *&inv) {
    if(player->GetMoney() < 1) {
        std::cout << ">>>> No Money QQQQ" << std::endl;
        return;
    }
    if(str == "buy1") {
        std::cout << ">>>> Buy Skill Book: Fire Exploooooosion" << std::endl;
        player->SetSkill(0);
    }
    if(str == "buy2") {
        std::cout << ">>>> Buy Skill Book: Water Booooomb" << std::endl;
        player->SetSkill(1);
    }
    if(str == "buy3") {
        std::cout << ">>>> Buy skill book: Grass Grooooooow" << std::endl;
        player->SetSkill(2);
    }
    if(str == "buy4") {
        std::cout << ">>>> Buy Potion: Health Potion" << std::endl;
        inv->AddItem(0, 1);
    }
    if(str == "buy5") {
        std::cout << ">>>> Buy Potion: Strength Potion" << std::endl;
        inv->AddItem(1, 1);
    }
    if(str == "buy6") {
        std::cout << ">>>> Buy Potion: Armor Potion" << std::endl;
        inv->AddItem(2, 1);
    }
    player->AddMoney(-1);
}

Stage Command::Fight(Player *&player, Map *&map, int _atk, Element element) {
    RoomType NowRoomType = map->GetNowRoom()->GetRoomType();
    Stage stage = map->Fight(_atk, element); 
    stagelog.emplace(stage);
    if(stage == Stage::FIGHTING) {
        player->BeAttack(map->GetNowRoom()->FightBack(), map->GetNowRoom()->FightBackElement());
        if(player->GetHp() <= 0)
            return Stage::LOSE;
    }
    else {
        if(NowRoomType == RoomType::BOSS)
            return Stage::WIN;
        player->AddMoney(10);
        std::cout << ">>>> " << player->GetName() << " gets 10 coins" << std::endl;
    }
    return stage;
}

Stage Command::Skill(std::string str, Player *&player, Map *map) {
    int atk = 0;
    Element element = Element::NONE;

    if(str == "z") {
        atk = Player::skill[0].GetAtk();
        element = Player::skill[0].GetElementType();
    }
    if(str == "x") {
        atk = Player::skill[1].GetAtk();
        element = Player::skill[1].GetElementType();
    }
    if(str == "c") {
        atk = Player::skill[2].GetAtk();
        element = Player::skill[2].GetElementType();
    }
    return Fight(player, map, atk, element);
}

void Command::Use(std::string str, Player *&player, Inventory *&inv) {
    int idx = StringToInt(str) - 1;
    Item item = inv->Use(idx);
    player->SetHp(player->GetHp() + item.GetHp());
    player->SetDef(player->GetDef() + item.GetDef());
    player->SetAtk(player->GetAtk() + item.GetAtk());
}