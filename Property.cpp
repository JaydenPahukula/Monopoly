#include <string>

#include "Player.h"
#include "Property.h"

Property::Property(){}

Property::~Property(){}

string Property::getName() const {
    return name;
}

int Property::getID() const {
    return 0;
}

int Property::getNumHouses() const {
    return -1;
}