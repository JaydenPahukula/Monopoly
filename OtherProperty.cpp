
#include "Player.h"
#include "OtherProperty.h"

#include <iostream>
#include <string>
using namespace std;

OtherProperty::OtherProperty(const string NAME, const short int LOCATION){
    name = NAME;
    location = LOCATION;
}

void OtherProperty::act(const Player* p){
    cout << "OtherProperty::act(" << p << "), " << location << endl;
    return;
}