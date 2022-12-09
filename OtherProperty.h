#ifndef OTHERPROPERTY_H
#define OTHERPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
using namespace std;


class OtherProperty final : public Property {
    private:
        short int location;
    public:
        OtherProperty(const string NAME, const short int LOCATION);
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