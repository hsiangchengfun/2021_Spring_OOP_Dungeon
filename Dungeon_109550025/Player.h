#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
    int money;
    int currentRoomIndex;
    int previousRoomIndex;
public:
    Player();
    Player(string,string,int,int,int,int,int);
    void addItem(Item);
    void increaseStatus(int,int,int,int);
    void changeRoom(Room*);
    void useItem();
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);
    int getAttack();
    int getDefense();
    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setCurrentRoomIndex(int);
    void setPreviousRoomIndex(int);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    void setMoney(int);
    int getMoney();
    int getCurrentRoomIndex();
    int getPreviousRoomIndex();
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();
};

#endif // PLAYER_H_INCLUDED
