#include "Record.h"




void Record::savePlayer(Player* player, ofstream& outStream){
    int i;
    outStream << player->getName() << ' '
              << player->getCurrentHealth() << ' '
              << player->getMaxHealth() << ' '
              << player->getAttack() << ' '
              << player->getDefense() << ' '
              << player->getMoney() << ' '
              << player->getCurrentRoom()->getIndex() << ' '
              << player->getPreviousRoom()->getIndex() << ' '
              << player->getInventory().size() << endl;
    for (i = 0; i < player->getInventory().size();i++){
        outStream << player->getInventory()[i].getName() << ' '
                  << player->getInventory()[i].getTag() << ' '
                  << player->getInventory()[i].getCurrentHealth() << ' '
                  << player->getInventory()[i].getMaxHealth() << ' '
                  << player->getInventory()[i].getAttack() << ' '
                  << player->getInventory()[i].getDefense() << ' ' 
                  << player->getInventory()[i].getCost() << endl;
    }
}
void Record::saveRooms(vector<Room>& rooms, ofstream& outStream){
    int i ,j ,k;
    for (i = 0; i < rooms.size();i++){
        for (j = 0; j < rooms[i].getObjects().size();j++){
            if(Monster *monster = dynamic_cast<Monster *>(rooms[i].getObjects()[j])){
                outStream << monster->getTag() << ' '
                          << monster->getName() << ' '
                          << monster->getCurrentHealth() << ' '
                          << monster->getMaxHealth() << ' '
                          << monster->getAttack() << ' '
                          << monster->getDefense() << ' ';
            }
            else if(NPC *npc = dynamic_cast<NPC *>(rooms[i].getObjects()[j])){
                outStream << npc->getTag() << ' '
                          << npc->getName() << ' ';
                for (k = 0; k < npc->getCommodity().size();k++){
                    outStream << npc->getCommodity()[k].getName() << ' '
                              << npc->getCommodity()[k].getTag() << ' '
                              << npc->getCommodity()[k].getCurrentHealth() << ' '
                              << npc->getCommodity()[k].getMaxHealth() << ' '
                              << npc->getCommodity()[k].getAttack() << ' '
                              << npc->getCommodity()[k].getDefense() << ' '
                              << npc->getCommodity()[k].getCost();
                    if(k != npc->getCommodity().size() - 1){
                        outStream << ' ';
                    }
                }
            }
            else if(Item *item = dynamic_cast<Item *>(rooms[i].getObjects()[j])){
                outStream << item->getTag() << ' '
                          << item->getName() << ' '
                          << item->getCurrentHealth() << ' '
                          << item->getMaxHealth() << ' '
                          << item->getAttack() << ' '
                          << item->getDefense() << ' '
                          << item->getCost() << ' ';
            }
        }
        if(rooms[i].getObjects().size() == 0){
            outStream << "No" << ' ';
        }
        outStream << endl;
    }
}
void Record::loadPlayer(Player* player, ifstream& inStream){
    string s ,name ,tag;
    stringstream ss;
    vector<string> Names(3);
    int j = 0 ,i;
    int currentHealth, maxHealth, attack, defense ,money ,cost ,currentRoomIndex ,previousRoomIndex ,inventorySize;
    getline(inStream, s);
    ss << s;
    ss >> name >> currentHealth >> maxHealth >> attack >> defense >> money >> currentRoomIndex >> previousRoomIndex >> inventorySize;
    *player = Player(name, "Player", currentHealth, maxHealth, attack, defense, money);
    player->setCurrentRoomIndex(currentRoomIndex);
    player->setPreviousRoomIndex(previousRoomIndex);
    while(getline(inStream ,s)){
        ss.str("");
        ss.clear();
        j = 0;
        ss << s;
        while(1){
            ss >> Names[j];
            if(Names[j] == "Item"){
                break;
            }
            j++;
        }
        for (i = 0; i < j;i++){
            if (i == 0){
                name = Names[i];
            }
            else{
                name = name + " " + Names[i];
            }
        }
        ss >> currentHealth >> maxHealth >> attack >> defense >> cost;
        Item item = Item(name, currentHealth, maxHealth, attack, defense, cost);
        player->addItem(item);
    }
}
void Record::loadRooms(vector<Room>& rooms, ifstream& inStream){
    string s;
    stringstream ss;
    int up, down, left, right, currentHealth, maxHealth, attack, defense, cost, i = 0, j = 0, k = 0;
    string tag, name;
    vector<string> Names(3);
   
    for (i = 0; i < 8;i++){
        rooms[i].setIndex(i + 1);
    }
    while(getline(inStream, s)){
        ss.str("");
        ss.clear();
        ss << s;
        ss >> tag;
        if(tag == "No"){}
        else if(tag == "Monster"){
            ss >> name;
            if(name == "ZK7"){
                ss >> currentHealth >> maxHealth >> attack >> defense;
                static Monster ZK7 = Monster("ZK7", currentHealth, maxHealth, attack, defense);
                ZK7.setScript("Ediot ! Ediot !");
                vector<Object *> stuff_of_7;
                stuff_of_7.push_back(&ZK7);
                rooms[7].setObjects(stuff_of_7);
            }
            else if(name == "willie"){
                ss >> currentHealth >> maxHealth >> attack >> defense;
                static Monster willie = Monster("willie", currentHealth, maxHealth, attack, defense);
                willie.setScript("You mama Your mama");
                vector<Object *> stuff_of_4;
                stuff_of_4.push_back(&willie);
                rooms[4].setObjects(stuff_of_4);
            }
            else if(name == "Sram"){
                ss >> currentHealth >> maxHealth >> attack >> defense;
                static Monster Sram = Monster("Sram", currentHealth, maxHealth, attack, defense);
                Sram.setScript("I have a girlfriend haha you loser");
                vector<Object *> stuff_of_5;
                stuff_of_5.push_back(&Sram);
                rooms[5].setObjects(stuff_of_5);
            }
        }
        else if(tag == "NPC"){
            ss >> name;
            
            vector<Item> commodity;
            while(!ss.eof()){
                
                j = 0;
                while(1){ 
                    ss >> Names[j];
                    if(Names[j] == "Item"){
                        break;
                    }
                    j++;
                }
                
                ss >> currentHealth >> maxHealth >> attack >> defense >> cost;
                if(Names[0] == "Health"){
                    static Item marsPotion = Item("Mars Potion", currentHealth, maxHealth, attack, defense, cost);
                    commodity.push_back(marsPotion);
                }
                else if(Names[0] == "Strength"){
                    static Item strengthPotion = Item("Strength Potion", currentHealth, maxHealth, attack, defense, cost);
                    commodity.push_back(strengthPotion);
                }
                else if(Names[0] == "Mysterious"){
                    static Item mysteriousPotion = Item("Mysterious Potion", currentHealth, maxHealth, attack, defense, cost);
                    commodity.push_back(mysteriousPotion);
                }
            }
            static NPC Danzel = NPC("Danzel", commodity);
            Danzel.setScript("\nDanzel : Hello , I am DanzelFun , I am a merchant.\nYou will face the final boss ZK7 in the final room.\nHere are some useful weapon and potion .\nWhat would you like to buy ?");
            vector<Object *> stuff_of_6;
            stuff_of_6.push_back(&Danzel);
            rooms[6].setObjects(stuff_of_6);
        }
        else if(tag == "Item"){
            ss >> name;
            ss >> currentHealth >> maxHealth >> attack >> defense >> cost;
            static Item K7Defeater = Item("K7-Defeater",currentHealth, maxHealth, attack, defense ,cost);
            vector<Object *> stuff_of_2;
            stuff_of_2.push_back(&K7Defeater);
            rooms[2].setObjects(stuff_of_2);
        }
    }
}

Record::Record(){}

void Record::saveToFile(Player* player, vector<Room>& rooms){
    ofstream outStream1 ,outStream2;
    outStream1.open("playerinfo.txt");    
    savePlayer(player ,outStream1);
    outStream2.open("mapinfo.txt");
    saveRooms(rooms, outStream2);
    cout << "\nFile saved!" << endl;
}
void Record::loadFromFile(Player* player, vector<Room>& rooms){
    ifstream inStream1 ,inStream2;
    inStream1.open("playerinfo.txt");
    loadPlayer(player, inStream1);
    inStream2.open("mapinfo.txt");
    loadRooms(rooms, inStream2);
    //player->setCurrentRoom(&rooms[player->getCurrentRoomIndex() - 1]);
    //player->setPreviousRoom(&rooms[player->getPreviousRoomIndex() - 1]);
    
    player->setCurrentRoom(&rooms[player->getCurrentRoomIndex() ]);
    player->setPreviousRoom(&rooms[player->getPreviousRoomIndex() ]);
    cout<<"Now you begin the previous game and is in room["<<player->getCurrentRoomIndex()<<"]"<<endl;
}
