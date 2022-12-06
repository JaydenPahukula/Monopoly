#ifndef PROPERTY_H
#define PROPERTY_H

#include "Player.h"

#include <string>
using namespace std;

class Player; // <- because Property and Player refer to each other

class Property {
    protected:
        string name;
    public:
        Property();
        virtual ~Property();
        virtual void act(Player* p) = 0;
        virtual string getType() const = 0;
        string getName();
};

#endif