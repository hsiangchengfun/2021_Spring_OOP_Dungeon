#include "NPC.h"

NPC::NPC(){}

NPC::NPC(string name, vector<Item> commodity){
    this->name = name;
    this->tag = "NPC";
    this->commodity = commodity;
}

void NPC::listCommodity(){
    int i;
    for (i = 0; i < commodity.size();i++){
        cout << char('A' + i) << '.' << commodity[i].getName() << endl;
    }
    cout << char('A' + i) << '.' << "No thanks" << endl;
}

bool NPC::triggerEvent(Object* player){
    char response;
    int i;
    Player *a = dynamic_cast<Player *>(player);
    if(commodity.size() > 0){
    cout << getScript() << endl;
    listCommodity();
    cin >> response;
    for (i = 0; i < commodity.size();i++){
        if (response == char('a' + i) || response == char('A' + i)){
            if(commodity[i].getCost() > a->getMoney()){
                cout << "Not enough money :(" << endl;
            }
            else{
                cout << "You got " << commodity[i].getName() << '!' << endl;
                a->setMoney(a->getMoney() - commodity[i].getCost());
                a->addItem(commodity[i]);
                commodity.erase(commodity.begin() + i);
            }
        }
    }
    }
    else{
        cout << "I got nothing left for you QQ" << endl;
    }
    return true;
}

void NPC::setScript(string script){
    this->script = script;
}
void NPC::setCommodity(vector<Item> commodity){
    this->commodity = commodity;
}
string NPC::getScript(){
    return script;
}
vector<Item> NPC::getCommodity(){
    return commodity;
}



