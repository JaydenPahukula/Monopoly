#ifndef PLAYER_H
#define PLAYER_H

#include <array>
using namespace std;

class Player final {

    short location;
    bool inJail;
    int jailCount;
    int balance;

    public:
        Player();

        short int getLocation() const;
        int move();
        bool isInJail();

};

#endif