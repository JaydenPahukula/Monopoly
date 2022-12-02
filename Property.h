#ifndef PROPERTY_H
#define PROPERTY_H

#include "Player.h"

#include <string>
using namespace std;

class Property {
    protected:
        string name;
    public:
        Property();
        virtual void act(const Player* p) = 0;
        string getName();
};

#endif