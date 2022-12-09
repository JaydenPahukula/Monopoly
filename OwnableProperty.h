#ifndef OWNABLEPROPERTY_H
#define OWNABLEPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
#include <vector>
using namespace std;


class OwnableProperty final : public Property {
    private:
        //attributes
        Player* owner;
        short int id;
        vector<int> priceTable;
        short int numHouses;
        //get the price of landing here
        unsigned short int getPrice() const;
    public:
        OwnableProperty(const string NAME, const int ID, const vector<int> TABLE);
        //perform action upon landing on this property
        virtual void act(Player* player) override;
        //sell this property
        virtual void sell() override;
        //add/remove houses
        virtual void changeHouses(const int N) override;

        //getters
        virtual string getType() const override;
        virtual int getID() const override;
        virtual vector<int> getPriceTable() const override;
        virtual unsigned short int getNumHouses() const override;
};


#endif