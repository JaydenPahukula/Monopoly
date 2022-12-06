
#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;




int main() {

    vector<Player*> players(3, nullptr);
    vector<Property*> properties(41, nullptr);
    
    
    setup(&players, &properties);

    bool doubles;
    unsigned short int doublesCount;
    short unsigned int currPlayerIndex = 0;
    Player* currPlayer = players[0];
    while (1){

        cout << "\nIt's " << currPlayer->getName() << "'s Turn" << endl;
        
        doubles = true;
        doublesCount = 0;
        while (doubles){
            //move
            doubles = currPlayer->move();
            doublesCount += int(doubles);
            //check for speeding
            if (doublesCount >= 3){
                cout << "  Caught Speeding! Sent to Jail" << endl;
                currPlayer->goToJail();
                break;
            }
            //perform action at new location
            if (!currPlayer->isInJail()){
                cout << "  Landed on " << properties[currPlayer->getLocation()]->getName() << endl;
                properties[currPlayer->getLocation()]->act(currPlayer);
            }
        }

        //increment currPlayer
        currPlayerIndex = (currPlayerIndex + 1) % players.size();
        currPlayer = players[currPlayerIndex];
    }

    //cleanup
    cout << "cleanup cleanup everybody everywhere" << endl;
    for (unsigned int i = 0; i < 40; i++){
        delete properties[i];
    }
    return 0;
}