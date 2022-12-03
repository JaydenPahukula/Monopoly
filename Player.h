#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include <string>
#include <vector>
using namespace std;

class Property;

class Player final {
    private:
        string name;
        short location;
        bool inJail;
        int jailCount;
        int balance;
        vector<Property*> ownedProperties;
    public:
        Player(const string NAME);
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

};

#endif