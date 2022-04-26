#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter
{
private:
    string script;
public:
    Monster();
    Monster(string ,int,int,int,int);

    void setScript(string);
    string getScript();

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);
};


#endif // ENEMY_H_INCLUDED
