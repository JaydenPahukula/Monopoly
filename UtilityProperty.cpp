
#include "Player.h"
#include "UtilityProperty.h"

#include <iostream>
#include <string>
using namespace std;

UtilityProperty::UtilityProperty(const string NAME){
    name = NAME;
    owner = nullptr;
}

string UtilityProperty::getType() const {
    return "Utility";
}


void UtilityProperty::act(Player* player){
    cout << "UtilityProperty::act(" << player << ")" << endl;
    return;
}