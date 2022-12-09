#ifndef UTILITYPROPERTY_H
#define UTILITYPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
using namespace std;


class UtilityProperty final : public Property {
    private:
        Player* owner;
        const unsigned short int PURCHASE_PRICE = 150;
    public:
        UtilityProperty(const string NAME); 
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