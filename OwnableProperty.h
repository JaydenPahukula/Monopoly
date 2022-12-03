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
        bool isMonopoly() const;
    public:
        OwnableProperty(const string NAME, const int ID);
        virtual string getType() const override;
        virtual void act(Player* p) override;
};

#endif