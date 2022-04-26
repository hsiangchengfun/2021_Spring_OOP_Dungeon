#include "Dungeon.h"


Dungeon::Dungeon(){}

void Dungeon::createPlayer(){
    string name;
    cout << "Please enter player's name:";
    cin >> name;
    Dungeon::player = Player(name, "player", 100, 100, 20, 10, 0);
    player.setCurrentRoom(&rooms[0]);
    player.setPreviousRoom(&rooms[0]);
}

void Dungeon::createMap(){
    int i;
    rooms.resize(8);
    rooms[0].setUpRoom(&rooms[1]);rooms[1].setDownRoom(&rooms[0]);
    rooms[1].setUpRoom(&rooms[3]);rooms[3].setDownRoom(&rooms[1]);
    rooms[1].setRightRoom(&rooms[2]);rooms[2].setLeftRoom(&rooms[1]);
    rooms[3].setUpRoom(&rooms[4]);rooms[4].setDownRoom(&rooms[3]);
    rooms[4].setLeftRoom(&rooms[5]);rooms[5].setRightRoom(&rooms[4]);
    rooms[5].setDownRoom(&rooms[6]);rooms[6].setUpRoom(&rooms[5]);
    rooms[6].setLeftRoom(&rooms[7]);rooms[7].setRightRoom(&rooms[6]);
    
    
    
    for (i = 0; i < 8;i++){
        rooms[i].setIndex(i + 1);
    }

    
    
    static Item K7Defeater = Item("K7-Defeater", 50, 50, 50, 10, 0);
	vector<Object*> s2;
	s2.push_back(&K7Defeater);
	rooms[2].setObjects(s2);


	static Monster ZK7 = Monster("ZK7", 2000, 2000, 50, 30);
	ZK7.setScript("Ediot ! Ediot !");
	vector<Object*> s7;
	s7.push_back(&ZK7);
	rooms[7].setObjects(s7);

	static Monster willie = Monster("willie", 70, 70, 15, 10);
	willie.setScript("Your mama Your mama");
	vector<Object*> s4;
	s4.push_back(&willie);
	rooms[4].setObjects(s4);


	static Monster sram = Monster("Sram", 350, 350, 35, 20);
	sram.setScript("I have a girlfriend haha you loser");
	vector<Object*> s5;
	s5.push_back(&sram);
	rooms[5].setObjects(s5);



	static Item marsPotion = Item("Mars Potion", 100, 100, 0, 0, 400);
	static Item dingdingPotion = Item("DingDing Potion", 0, 0, 60, 0, 600);
	static Item mysteriousPotion = Item("Mysterious Potion", 200, 200, 999, 100, 1000);
	static Item goldenarmor = Item("Golden Armor", 0, 0, 0, 50, 0);
	vector<Item> commodity;
	commodity.push_back(marsPotion);
	commodity.push_back(dingdingPotion);
	commodity.push_back(mysteriousPotion);
	commodity.push_back(goldenarmor);
	static NPC Danzel = NPC("Danzel", commodity);
	Danzel.setScript("\nDanzel : Hello , I am DanzelFun , I am a merchant.\nYou will face the final boss ZK7 in the final room.\nHere are some useful weapon and potion .\nWhat would you like to buy ?");
	vector<Object*> s6;
	s6.push_back(&Danzel);
	rooms[6].setObjects(s6);
}
void Dungeon::showmap() {

	cout << endl << "The Map :" << endl;

	cout << "         ----- " << " " << " ----- " << endl;
	cout << "         | 5 | " << "-" << " | 4 | " << endl;
	cout << "         ----- " << " " << " ----- " << endl;
	cout << "            |   " << "   |   " << endl;
    cout << " ----- " << " " << " ----- " << " " << " ----- " << endl;
	cout << " | 7 | " << "-" << " | 6 | " << " " << " | 3 | " << endl;
	cout << " ----- " << " " << " ----- " << " " << " ----- " << endl;
	cout << "                   |   " <<  endl;
    cout << "                 ----- " <<" "<<" ----- " << endl;
	cout << "                 | 1 | " <<"-"<< " | 2 | " << endl;
	cout << "                 ----- " <<" "<<" ----- " << endl;
    cout << "                   |   " << endl;
	cout << "                 ----- " << endl;
	cout << "                 | 0 | " << endl;
	cout << "                 ----- " << endl;
	cout << endl;

}


void Dungeon::handleMovement(){
    int i = 0;
    char response;
    vector<char> direction;
    cout << "\nWhere do you want to go" << endl;
    if(player.getCurrentRoom()->getUpRoom() != NULL){
        cout << char('A' + i) << ".Go Up" << endl;
        direction.push_back('u');
        i++;
    }
    if(player.getCurrentRoom()->getDownRoom() != NULL){
        cout << char('A' + i) << ".Go Down" << endl;
        direction.push_back('d');
        i++;
    }
    if(player.getCurrentRoom()->getLeftRoom() != NULL){
        cout << char('A' + i) << ".Go Left" << endl;
        direction.push_back('l');
        i++;
    }
    if(player.getCurrentRoom()->getRightRoom() != NULL){
        cout << char('A' + i) << ".Go Right" << endl;
        direction.push_back('r');
        i++;
    }
    cin >> response;
    if(response == 'a' || response == 'A'){
        if(direction[0] == 'u'){
            player.setCurrentRoom(player.getCurrentRoom()->getUpRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getDownRoom());
        }
        if(direction[0] == 'd'){
            player.setCurrentRoom(player.getCurrentRoom()->getDownRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getUpRoom());
        }
        if(direction[0] == 'l'){
            player.setCurrentRoom(player.getCurrentRoom()->getLeftRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getRightRoom());
        }
        if(direction[0] == 'r'){
            player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getLeftRoom());
        }
    }
    else if(response == 'b' || response == 'B'){
        if(direction[1] == 'd'){
            player.setCurrentRoom(player.getCurrentRoom()->getDownRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getUpRoom());
        }
        if(direction[1] == 'l'){
            player.setCurrentRoom(player.getCurrentRoom()->getLeftRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getRightRoom());
        }
        if(direction[1] == 'r'){
            player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getLeftRoom());
        }
    }
    else if(response == 'c' || response == 'C'){
        if(direction[2] == 'l'){
            player.setCurrentRoom(player.getCurrentRoom()->getLeftRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getRightRoom());
        }
        if(direction[2] == 'r'){
            player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getLeftRoom());
        }
    }
    else if(response == 'd' || response == 'D'){
        if(direction[3] == 'r'){
            player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
            player.setPreviousRoom(player.getCurrentRoom()->getLeftRoom());
        }
    }
    cout<<"After the movement,you are now in room["<<player.getCurrentRoom()->getIndex()-1<<"]"<<endl;
}

void Dungeon::handleRetreat(){
    static Room *temp;
    temp = player.getCurrentRoom();
    player.setCurrentRoom(player.getPreviousRoom());
    player.setPreviousRoom(temp);
}

void Dungeon::handleEvent(Object*){

}

void Dungeon::startGame(){
    char response;
    Record record;
    cout << "Do you want to load previous data?" << endl
         << "A.Yes" << endl
         << "B.No" << endl;
    cin >> response;
    if(response == 'a' || response == 'A'){
        createMap();
		record.loadFromFile(&player ,rooms);

    }
    else{
        createMap();
        createPlayer();
    }
}

bool Dungeon::checkMonsterRoom(vector<Object*> objects){
    int i;
    for (i = 0; i < objects.size();i++){
        if (objects[i]->getTag() == "Monster"){
            return true;
        }
    }
    return false;
}



void Dungeon::chooseAction(vector<Object*> objects) {
	int j = 0, flag = 0;
	char response;
	Record record;
	cout << "\nWhat do you want to do?" << endl;
	if (checkMonsterRoom(objects)) {

		Monster* monster = dynamic_cast<Monster*>(objects[0]);
		if (monster->getCurrentHealth() > 0) {
			flag = 1;
		}
		else {
			flag = 2;
		}
	}
	if (!objects.empty()) {
		if (checkMonsterRoom(objects) && flag == 1) {
			cout << "A.Retreat" << endl
				<< "B.Check Status" << endl
				<< "C.Fight with " << objects[j]->getName() << endl
				<< "D.Use items" << endl
				<< "E.Save to file" << endl
				<< "F.Show Map" << endl;
			cin >> response;
			if (response == 'a' || response == 'A') {
				handleRetreat();
			}
			else if (response == 'b' || response == 'B') {
				
				player.triggerEvent(&player);
			}
			else if (response == 'c' || response == 'C') {
				if (objects[j]->triggerEvent(&player)) {
					handleRetreat();
				}
			}
			else if (response == 'd' || response == 'D') {
				player.useItem();
			}
			else if (response == 'e' || response == 'E') {
				record.saveToFile(&player, rooms);
			}
			else if (response == 'f' || response == 'F') {
				showmap();
			}
		}

		else if (objects[j]->getTag() == "NPC") {
			cout << "A.Move" << endl
				<< "B.Check Status" << endl
				<< "C.Talk to " << objects[j]->getName() << endl
				<< "D.Use items" << endl
				<< "E.Save to file" << endl
				<< "F.Show Map" << endl;
			cin >> response;
			if (response == 'a' || response == 'A') {
				handleMovement();
			}
			else if (response == 'b' || response == 'B') {
			
				player.triggerEvent(&player);
			}
			else if (response == 'c' || response == 'C') {
				objects[j]->triggerEvent(&player);
			}
			else if (response == 'd' || response == 'D') {
				player.useItem();
			}
			else if (response == 'e' || response == 'E') {
				record.saveToFile(&player, rooms);
			}
			else if (response == 'f' || response == 'F') {
				showmap();
			}
		}
		else if (objects[j]->getTag() == "Item") {
			cout << "A.Move" << endl
				<< "B.Check Status" << endl
				<< "C.Pull the sword out of the stone" << endl
				<< "D.Use items" << endl
				<< "E.Save to file" << endl
				<< "F.Show Map" << endl;
			cin >> response;
			if (response == 'a' || response == 'A') {
				handleMovement();
			}
			else if (response == 'b' || response == 'B') {
				
				player.triggerEvent(&player);
			}
			else if (response == 'c' || response == 'C') {
				cout << "\nYou got " << objects[j]->getName() << "!!!!" << endl;
				Item* a = dynamic_cast<Item*>(objects[j]);
				player.addItem(*a);
				player.getCurrentRoom()->getObjects().pop_back();
			}
			else if (response == 'd' || response == 'D') {
				player.useItem();
			}
			else if (response == 'e' || response == 'E') {
				record.saveToFile(&player, rooms);
			}
			else if (response == 'f' || response == 'F') {
				showmap();
			}
		}
	}
	if (objects.empty() || flag == 2) {
		cout << "A.Move" << endl
			<< "B.Check Status" << endl
			<< "C.Use items" << endl
			<< "D.Save to file" << endl
			<< "E.Show Map" << endl;
		cin >> response;
		if (response == 'a' || response == 'A') {
			handleMovement();
		}
		else if (response == 'b' || response == 'B') {
			
			player.triggerEvent(&player);
		}
		else if (response == 'c' || response == 'C') {
			player.useItem();
		}
		else if (response == 'd' || response == 'D') {
			record.saveToFile(&player, rooms);
		}
		else if (response == 'e' || response == 'E') {
			showmap();
		}
	}
}

        

bool Dungeon::checkGameLogic(){
    if(player.checkIsDead()){
        cout << "You are dead QQ" << endl;
        return true;
    }
    else if(player.getCurrentRoom()->getIndex() == 8){ 
        Monster *a = dynamic_cast<Monster *>(player.getCurrentRoom()->getObjects()[0]);
        if(a->getCurrentHealth() <= 0){
            cout << "You defeat ZK7 and win the game !!" << endl;
            return true;
        }
        return false;
    }
    else{
        return false;
    }
}

void Dungeon::runDungeon(){
    startGame();
    while(!checkGameLogic()){
        chooseAction(player.getCurrentRoom()->getObjects());
    }
}
