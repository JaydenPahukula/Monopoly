#ifndef UTILITYPROPERTY_H
#define UTILITYPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
using namespace std;

class UtilityProperty final : public Property {
    private:
        Player* owner;
        int numUtilities() const;
    public:
        UtilityProperty(const string NAME);
        virtual void act(const Player* p) override;
};

#endif