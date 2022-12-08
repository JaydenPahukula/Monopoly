#ifndef RAILROADPROPERTY_H
#define RAILROADPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
using namespace std;

class RailroadProperty final : public Property {
    private:
        Player* owner;
        const short int PURCHASEPRICE = 200;
        unsigned short int getPrice() const;
    public:
        RailroadProperty(const string NAME);
        virtual string getType() const override;
        virtual void act(Player* player) override;
        virtual vector<int> getPriceTable() const override;
        virtual unsigned short int getNumHouses() const override;
};

#endif