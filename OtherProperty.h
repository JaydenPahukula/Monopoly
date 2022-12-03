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
        virtual string getType() const override;
        virtual void act(Player* p) override;
};

#endif