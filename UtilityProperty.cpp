
#include "Player.h"
#include "UtilityProperty.h"

#include <iostream>
#include <string>
using namespace std;

UtilityProperty::UtilityProperty(const string NAME){
    name = NAME;
    owner = nullptr;
}

void UtilityProperty::act(const Player* p){
    cout << "UtilityProperty::act(" << p << ")" << endl;
    return;
}