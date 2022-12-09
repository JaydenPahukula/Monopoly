#ifndef PLAYER_H
#define PLAYER_H

#include "Property.h"

#include <string>
#include <vector>
using namespace std;


class Property; // <- because Property and Player refer to each other

class Player final {
    private:
        //attributes
        string name;
        bool bot;
        int balance;
        unsigned short int location;
        bool inJail;
        unsigned short int jailCount;
        unsigned short int getOutOfJailCards;
        vector<Property*> ownedProperties;
        //handles being in jail
        bool moveInJail();
        //print all ownable properties (to buy/sell houses)
        vector<int> printOwnableProperties() const;
        //print all owned properties
        void printPropertyInfo() const;
    public:
        Player(const string NAME, const bool BOT);
        //do pre-turn actions like buying/selling houses
        void preTurn();
        //move token
        bool move();
        //sends player to jail
        void goToJail();
        //sell houses to resolve debt
        bool resolveDebt();
        //buy property
        void buy(Property* PROPERTY, const unsigned int PRICE);
        //draw chance card
        void drawChanceCard();
        //draw community chest card
        void drawCCCard();
        //add or subtract money from player's balance
        void changeBalance(const int AMOUNT);

        //getters
        bool isInJail() const;
        bool isBot() const;
        int getBalance() const;
        unsigned short int getLocation() const;
        string getName() const;
        unsigned short int getNumRRs() const;
        unsigned short int getNumUtilities() const;
};


#endif