#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

using namespace std;




int main() {

    Player* p1 = new Player(29);
    Player* p2 = new Player(21);
    Player* p3 = new Player(21);
    Player* p4 = new Player(30);
    vector<Player*> players = {p1, p2, p3, p4};


    printGame(players);


    return 0;
}