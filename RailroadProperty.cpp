
#include "Player.h"
#include "RailroadProperty.h"

#include <math.h>
#include <iostream>
#include <string>
using namespace std;

RailroadProperty::RailroadProperty(const string NAME){
    name = NAME;
    owner = nullptr;
}

string RailroadProperty::getType() const {
    return "Railroad";
}

unsigned short int RailroadProperty::getPrice() const {
    return 25 * pow(2, owner->getNumRRs()-1);
}

void RailroadProperty::act(Player* player){

    //if unowned
    if (owner == nullptr){
        char choice = '0';
        cout << "    This property is unowned,";
        if (player->getBalance() >= PURCHASEPRICE){
            cout << " would you like to buy it for $" << PURCHASEPRICE << "? (current balance is: $" << player->getBalance() << ") Y/N:\n";

            //bot player will always buy
            if(player->isBot()){ 
                cout << "    Y" << endl;
                choice = 'Y';
            //get user input
            } else { 
                do {
                    cout << "    ";
                    cin >> choice;
                } while (choice != 'Y' && choice != 'N');
            }
            
            if (choice == 'Y'){ //buy
                owner = player;
                player->buy(this, PURCHASEPRICE);
                cout << "    Purchased!" << endl;
            } else {
                cout << "    Didn't purchase" << endl;
            }
        } else {
            cout << " but you cannot afford it" << endl;
        }

    //if already owned
    } else {
        //if player is owner
        if (owner == player){
            cout << "    You own this property" << endl;
        } else {
            unsigned short int price = getPrice();
            owner->changeBalance(price);
            player->changeBalance(-price);
            cout << "    This property is owned by " << owner->getName() << "\n    Because they own " << owner->getNumRRs() << " railroad(s), you paid them $" << getPrice() << endl;
        }
    }
    return;
}