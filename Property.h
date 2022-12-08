#ifndef PROPERTY_H
#define PROPERTY_H

#include "Player.h"

#include <string>
#include <vector>
using namespace std;

class Player; // <- because Property and Player refer to each other

class Property {
    protected:
        string name;
    public:
        Property();
        virtual ~Property();
        virtual void act(Player* player) = 0;
        virtual string getType() const = 0;
        virtual int getID() const;
        virtual vector<int> getPriceTable() const = 0;
        virtual int getNumHouses() const;
        string getName() const;
};

#endif