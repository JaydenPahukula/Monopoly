#ifndef OWNABLEPROPERTY_H
#define OWNABLEPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
#include <vector>
using namespace std;

class OwnableProperty final : public Property {
    private:
        Player* owner;
        short int id;
        vector<int> priceTable;
        short int numHouses;
        unsigned short int getPrice() const;
    public:
        OwnableProperty(const string NAME, const int ID, const vector<int> TABLE);
        virtual string getType() const override;
        virtual void act(Player* player) override;
        virtual int getID() const override;
        virtual vector<int> getPriceTable() const override;
        virtual unsigned short int getNumHouses() const override;
        virtual void changeHouses(const int N) override;
};

#endif