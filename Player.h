#ifndef PLAYER_H
#define PLAYER_H

#include "Property.h"

#include <array>
#include <string>
#include <vector>
using namespace std;

class Property; // <- because Property and Player refer to each other

class Player final {
    private:
        string name;
        bool bot;
        short int location;
        bool inJail;
        short int jailCount;
        short int getOutOfJailCards;
        int balance;
        vector<Property*> ownedProperties;
        bool moveInJail();
        vector<int> printOwnableProperties() const;
        void printPropertyInfo() const;
    public:
        Player(const string NAME, const bool BOT);
        void preTurn();
        bool move();
        void goToJail();
        void buy(Property* PROPERTY, const unsigned int PRICE);
        void changeBalance(const int AMOUNT);
        int getBalance() const;
        unsigned short int getLocation() const;
        string getName() const;
        unsigned short int getNumRRs() const;
        unsigned short int getNumUtilities() const;
        bool isInJail() const;
        bool isBot() const;

};

#endif