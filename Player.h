#ifndef PLAYER_H
#define PLAYER_H

#include <array>
using namespace std;

class Player final {

    short location;
    bool inJail;
    int jailCount;
    int balance;

    array<int, 2> roll() const;
    void goToJail();
    void act(const short int L);

    public:
        Player();

        short int getLocation() const;
        void move();
        bool isInJail();

};

#endif