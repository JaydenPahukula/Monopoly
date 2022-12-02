

#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Player::Player(){
    location = 0;
    inJail = false;
    jailCount = 0;
    balance = 1500;
    srand(time(0));
}

short int Player::getLocation() const {
    return location;
}

// int Player::move(){


//     if (inJail){
//         cout << "Currently in jail...\nPress ENTER to roll";
//         cin.ignore();
//         //roll
//         array<int, 2> r = roll();
//         cout << "  Rolled " << r[0] << " and " << r[1];

//         if (r[0] == r[1]){
//             cout << " - Doubles! You got out!" << endl;
//             inJail = false;
//             location = 10;
//         } else {
            
//             jailCount += 1;
//             if (jailCount >= 3){
//                 cout << "\nYou've been in jail for 3 turns, you must pay $50 to get out..." << endl;
//                 balance -= 50;
//                 inJail = false;
//                 location = 10;
//             } else {
//                 cout << "\nStill stuck in jail" << endl;
//                 return 0;
//             }
//         }
//     }

//     cout << "Press ENTER to roll";
//     cin.ignore();

//     bool doubles;
//     short unsigned int numDoubles = 0;
//     do {

//         //roll
//         doubles = false;
//         array<int, 2> r = roll();
//         cout << "  Rolled " << r[0] << " and " << r[1];

//         //check for doubles
//         if (r[0] == r[1]){

//             cout << " - Doubles!";
//             doubles = true;
//             numDoubles += 1;

//             //check for speeding
//             if (numDoubles == 3){
//                 cout << "Caught Speeding! (rolled 3 doubles)" << endl;
//                 goToJail();
//                 return;
//             }
//         }
//         cout << endl;
//         location += r[0] + r[1];
//         //pass go
//         if (location >= 40){
//             location -= 40;
//             cout << "Passed Go, Collect $200!" << endl;
//             balance += 200;
//         }
//         act(location);
//     } while (doubles);
//     return 0;
// }

bool Player::isInJail(){
    return inJail;
}

