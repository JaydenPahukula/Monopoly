
#include "Player.h"
#include "RailroadProperty.h"

#include <iostream>
#include <string>
using namespace std;

RailroadProperty::RailroadProperty(const string NAME){
    name = NAME;
    owner = nullptr;
}

void RailroadProperty::act(const Player* p){
    cout << "RailroadProperty::act(" << p << ")" << endl;
    return;
}