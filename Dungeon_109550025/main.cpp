#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Item.h"
#include "GameCharacter.h"
#include "Room.h"
#include "Player.h"
#include "Monster.h"
#include "Dungeon.h"
using namespace std;

int main(){
    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();

    return 0;
}

