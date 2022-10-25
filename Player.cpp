

#include "Player.h"
#include "Property.h"

Player::Player(short l){
    location = l;
}

short Player::where(){
    return location;
}

