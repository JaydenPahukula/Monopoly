#ifndef RAILROADPROPERTY_H
#define RAILROADPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
using namespace std;


class RailroadProperty final : public Property {
    private:
        Player* owner;
        const short int PURCHASE_PRICE = 200;
        //get the price of landing here
        unsigned short int getPrice() const;
    public:
        RailroadProperty(const string NAME);
        //perform action upon landing on this property
        virtual void act(Player* player) override;
        //sell this property
        virtual void sell() override;

        //getters
        virtual string getType() const override;
        virtual vector<int> getPriceTable() const override;
        virtual unsigned short int getNumHouses() const override;
};


#endif