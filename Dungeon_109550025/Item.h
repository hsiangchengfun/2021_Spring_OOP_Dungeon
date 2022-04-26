#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"

using namespace std;

class Item: public Object
{
private:
    int currentHealth,maxHealth,attack,defense,cost;
public:
    Item();
    Item(string, int, int, int, int, int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    int getCurrentHealth();
    int getMaxHealth();
    int getAttack();
    int getDefense();
    int getCost();
    void setCurrentHealth(int);
    void setMaxHealth(int);
    void setAttack(int);
    void setDefense(int);
};

#endif // ITEM_H_INCLUDED
