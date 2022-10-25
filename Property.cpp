#include <string>

#include "Player.h"
#include "Property.h"

Property::Property(string n){
    name = n;
}

string Property::getName(){
    return name;
}
