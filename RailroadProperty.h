#ifndef RAILROADPROPERTY_H
#define RAILROADPROPERTY_H

#include "Player.h"
#include "Property.h"

#include <string>
using namespace std;

class RailroadProperty final : public Property {
    private:
        Player* owner;
        int numRRs() const;
    public:
        RailroadProperty(const string NAME);
        virtual void act(const Player* p) override;
};

#endif