#include "Item.h"



Item::Item(){}

Item::Item(string name, int currentHealth,int maxHealth , int attack, int defense ,int cost):Object(name ,"Item"){
    this->currentHealth = currentHealth;
    this->maxHealth = maxHealth;
    this->attack = attack;
    this->defense = defense;
    this->cost = cost;
}
bool Item::triggerEvent(Object* player){
    Player *a = dynamic_cast<Player *>(player);
    a->increaseStatus(currentHealth, maxHealth, attack, defense);
    return true;
}
int Item::getCurrentHealth(){
    return currentHealth;
}
int Item:: getMaxHealth(){
    return maxHealth;
}
int Item::getAttack(){
    return attack;
}
int Item::getDefense(){
    return defense;
}
int Item::getCost(){
    return this->cost;
}
void Item::setCurrentHealth(int currentHealth){
    this->currentHealth = currentHealth;
}
void Item::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}
void Item::setAttack(int attack){
    this->attack = attack;
}
void Item::setDefense(int defense){
    this->defense = defense;
}
