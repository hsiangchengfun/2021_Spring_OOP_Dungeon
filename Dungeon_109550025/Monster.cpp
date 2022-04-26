#include "Monster.h"

Monster::Monster(){}

Monster::Monster(string name, int currentHealth, int maxHealth, int attack, int defense){
    this->name = name;
    this->tag = "Monster";
    this->maxHealth = maxHealth;
    this->currentHealth = currentHealth;
    this->attack = attack;
    this->defense = defense;
}

void Monster::setScript(string script){
    this->script = script;
}

string Monster::getScript(){
    return this->script;
}


bool Monster::triggerEvent(Object* player){
    char response;
    int i;
    Player *a = dynamic_cast<Player *>(player);
    while(currentHealth > 0 && a->getCurrentHealth() > 0){
        cout << name << "'s Status:" << endl
             << "Health:" << currentHealth << '/' << maxHealth << endl
             << "Attack:" << attack << endl
             << "Defense:" << defense << endl
             << endl
             << a->getName() << "'s Status:" << endl
             << "Health:" << a->getCurrentHealth() << '/' << a->getMaxHealth() << endl
             << "Attack:" << a->getAttack() << endl
             << "Defense:" << a->getDefense() << endl
             << endl;
        cout << "Choose action:" << endl
             << "A.Attack " << name << endl
             << "B.Retreat" << endl;
        cin >> response;
        if(response == 'a' || response == 'A'){
            cout << "You choose to attack!" << endl
                 << "Your attack does " << a->getAttack() << " damage." << endl;
            if(a->getAttack() > defense){
                currentHealth = currentHealth - a->getAttack() + defense;
            }
            if(currentHealth > 0){
                if(attack > a->getDefense()){
                    a->setCurrentHealth(a->getCurrentHealth() - attack + a->getDefense());
                    cout << name << "'s attack does " << attack << " damage." << endl;
                }
            }
        }
        else if(response == 'b' || response == 'B'){
            return true;
        }
    }
    if(currentHealth <= 0){
        cout << endl
             << endl
             << endl
             << name << ':' << script << endl
             << endl
             << endl
             << endl;
        cout << "You beat " << name << "!!!!" << endl
             << "You earned 1000 dollars" << endl;
        a->setMoney(a->getMoney() + 1000);
    }
        
    return false;
}



