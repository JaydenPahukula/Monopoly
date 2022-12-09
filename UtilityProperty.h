#ifndef UTILITYPROPERTY_H
#define UTILITYPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
using namespace std;

class UtilityProperty final : public Property {
    private:
        Player* owner;
        const unsigned short int PURCHASEPRICE = 150;
    public:
        UtilityProperty(const string NAME);
        virtual string getType() const override;
        virtual void act(Player* player) override;
        virtual vector<int> getPriceTable() const override;
        virtual unsigned short int getNumHouses() const override;
        virtual void sell() override;
};

#endif