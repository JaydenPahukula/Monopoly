
#include "Player.h"
#include "OwnableProperty.h"

#include <iostream>
#include <string>
using namespace std;

OwnableProperty::OwnableProperty(const string NAME, const int ID){
    name = NAME;
    id = ID;
    owner = nullptr;
    priceTable = vector<int>(4, 10);
    numHouses = 0;
}

string OwnableProperty::getType() const {
    return "Ownable";
}

void OwnableProperty::act(Player* p){
    cout << "OwnableProperty::act(" << p << "), " << id << endl;
    return;
}