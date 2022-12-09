/* CSCI 200: Final Project
 *
 * Author: Jayden Pahukula
 * Resources used:
 *
 * Description:
 * Play monopoly with up to 3 computer
 * opponents!
 * 
 */

#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {

    vector<Player*> players;
    vector<Property*> properties(41, nullptr);
    

    //set up the game
    setup(&players, &properties);


    //main gameplay loop
    bool doubles;
    unsigned short int doublesCount;
    short unsigned int currPlayerIndex = 0;
    Player* currPlayer = players[0];
    while (1){

        //win condition
        if (players.size() == 1){
            cout << "\n     --==##  " << players[0]->getName() << " wins!  ##==--" << endl << endl;
            break;
        }

        //print game board
        print_game(players, properties);

        cout << "\nIts " << currPlayer->getName() << "'s Turn! (press ENTER to continue)";
        cin.ignore();

        //do any pre-turn actions (bots cannot do this)
        if (!currPlayer->isBot()){
            currPlayer->preTurn();
        }
        
        //take turn
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
                cout << "    Landed on " << properties[currPlayer->getLocation()]->getName() << endl;
                properties[currPlayer->getLocation()]->act(currPlayer);
            }
        }

        //resolve any debt
        if (currPlayer->getBalance() < 0){
            cout << "\n  Uh oh! You are in debt!" << endl;
            while(currPlayer->getBalance() < 0){
                //if player goes bankrupt
                if (!currPlayer->resolveDebt()){
                    cout << "    You went bankrupt! Thanks for playing!" << endl;
                    delete currPlayer;
                    currPlayer = nullptr;
                    players.erase(players.begin() + currPlayerIndex);
                    currPlayerIndex -= 1;
                    break;
                }
            }
            if (currPlayer != nullptr){
                cout << "  Hooray! Your current balance is $" << currPlayer->getBalance() << endl;
            }
        }

        cout << "\nPress ENTER to continue:";
        cin.ignore();
        cout << endl;

        //increment current player
        currPlayerIndex = (currPlayerIndex + 1) % players.size();
        currPlayer = players[currPlayerIndex];
    }


    //cleanup
    for (int i = 0; i < 40; i++){
        delete properties[i];
    }
    for (unsigned int i = 0; i < players.size(); i++){
        delete players[i];
    }
    return 0;
}