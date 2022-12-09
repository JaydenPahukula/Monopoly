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
        //perform action upon landing on this property
        virtual void act(Player* player) = 0;
        //sell this property
        virtual void sell() = 0;
        //add/remove houses
        virtual void changeHouses(const int N);

        //getters
        string getName() const;
        virtual int getID() const;
        virtual string getType() const = 0;
        virtual vector<int> getPriceTable() const = 0;
        virtual unsigned short int getNumHouses() const = 0;
};


#endif