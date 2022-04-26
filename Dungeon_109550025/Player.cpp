#include "Player.h"

Player::Player(){}

Player::Player(string name ,string tag, int currentHealth, int maxHealth, int attack ,int defense ,int money):GameCharacter(name,tag,currentHealth,maxHealth,attack,defense){
    this->money = money;
}

void Player::addItem(Item item){
    this->inventory.push_back(item);
}
void Player::increaseStatus(int currentHealth,int maxHealth ,int attack,int defense){
    Player::maxHealth = Player::maxHealth + maxHealth;
    if(Player::currentHealth + currentHealth > Player::maxHealth){
        Player::currentHealth = Player::maxHealth;
    }
    else{
        Player::currentHealth = Player::currentHealth + currentHealth;
    }
    Player::attack = Player::attack + attack;
    Player::defense = Player::defense + defense;
}
void Player::changeRoom(Room* direction){
    previousRoom = currentRoom;
    currentRoom = direction;
}

void Player::useItem(){
    int i;
    char response;
    if(inventory.size() > 0){
        cout << "Which item do you want to use?" << endl;
        cout << "Inventory:" << endl;
        for (i = 0; i < inventory.size();i++){
            cout << char('A' + i) << '.' << inventory[i].getName() << endl;
        }
        cin >> response;
        for (i = 0; i < inventory.size();i++){
            if(response == char('a' + i) || response == char('A' + i)){
                cout << "You used " << inventory[i].getName() << "!!!" << endl;
                inventory[i].triggerEvent(this);
                inventory.erase(inventory.begin() + i);
            }
        }
    }
    else{
        cout << "You have no items to use :(" << endl;
    }
}

bool Player::triggerEvent(Object* player){
    int i;
    Player *a = dynamic_cast<Player *>(player);
    cout << "Status:" << endl
         << '[' << name << ']' << endl
         << "> Health: " << currentHealth << '/' << maxHealth << endl
         << "> Attack: " << attack << endl
         << "> Defense: " << defense << endl;
    if(inventory.size() > 0){
        cout << "Inventory:" << endl;
        for (i = 0; i < inventory.size();i++){
            cout << "> " << inventory[i].getName() << endl;
        }
    }
    cout << "Money:" << a->getMoney() << endl;
    return true;
}

int Player::getAttack(){
    return attack;
}

int Player::getDefense(){
    return defense;
}

void Player::setCurrentRoomIndex(int index){
    this->currentRoomIndex = index;
}
void Player::setPreviousRoomIndex(int index){
    this->previousRoomIndex = index;
}

int Player::getCurrentRoomIndex(){
    return currentRoomIndex;
}
int Player::getPreviousRoomIndex(){
    return previousRoomIndex;
}

void Player::setCurrentRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}
void Player::setPreviousRoom(Room* previousRoom){
    this->previousRoom = previousRoom;
}
void Player::setInventory(vector<Item> inventory){
    this->inventory = inventory;
}
void Player::setMoney(int money){
    this->money = money;
}
int Player::getMoney(){
    return this->money;
}

Room* Player::getCurrentRoom(){
    return currentRoom;
}
Room* Player::getPreviousRoom(){
    return previousRoom;
}
vector<Item> Player::getInventory(){
    return inventory;
}

















