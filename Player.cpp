

#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Player::Player(const string NAME){
    name = NAME;
    location = 0;
    inJail = false;
    jailCount = 0;
    balance = 1500;
    srand(time(0));
}


bool Player::move(){

    if (inJail){
        cin.ignore();
        //roll
        array<int, 2> r = roll();
        cout << "  Rolled " << r[0] << " and " << r[1];

        if (r[0] == r[1]){
            cout << " - Doubles! You got out!" << endl;
            inJail = false;
            location = 10;
        } else {
            
            jailCount += 1;
            if (jailCount >= 3){
                cout << "\nYou've been in jail for 3 turns, you must pay $50 to get out..." << endl;
                balance -= 50;
                inJail = false;
                location = 10;
            } else {
                cout << "\nStill stuck in jail" << endl;
                return 0;
            }
        }
    }

    cout << "  Press ENTER to roll:";
    cin.ignore();

    //roll
    array<int, 2> r = roll();
    cout << "  Rolled " << r[0] << " and " << r[1];

    //check for doubles
    bool doubles = false;
    if (r[0] == r[1]){
        cout << " - Doubles!";
        doubles = true;
    }
    cout << endl;

    //move
    location += r[0] + r[1];

    //check if passed go
    if (location >= 40){
        location -= 40;
        cout << "  Passed Go, Collected $200!" << endl;
        balance += 200;
    }

    return doubles;
}

void Player::goToJail(){
    cout << "  Sent to jail :(" << endl;
    return;
}

void Player::buy(Property* PROPERTY, const unsigned int PRICE){
    balance -= PRICE;
    ownedProperties.push_back(PROPERTY);
}

void Player::changeBalance(const int AMOUNT){
    balance += AMOUNT;
    return;
}

int Player::getBalance() const {
    return balance;
}

unsigned short int Player::getLocation() const {
    return location;
}

string Player::getName() const {
    return name;
}

unsigned short int Player::getNumRRs() const {
    unsigned short int count = 0;
    for (unsigned int i = 0; i < ownedProperties.size(); i++){
        if (ownedProperties.at(i)->getType() == "Railroad"){
            count += 1;
        }
    }
    return count;
}

unsigned short int Player::getNumUtilities() const {
    unsigned short int count = 0;
    for (unsigned int i = 0; i < ownedProperties.size(); i++){
        if (ownedProperties.at(i)->getType() == "Utility"){
            count += 1;
        }
    }
    return count;
}

bool Player::isInJail() const {
    return inJail;
}

