
#include "Player.h"
#include "RailroadProperty.h"

#include <iostream>
#include <math.h>
#include <string>
using namespace std;


RailroadProperty::RailroadProperty(const string NAME){
    name = NAME;
    owner = nullptr;
}

unsigned short int RailroadProperty::getPrice() const {
    return 25 * pow(2, owner->getNumRRs()-1);
}

void RailroadProperty::act(Player* player){

    //if unowned
    if (owner == nullptr){
        char choice = '0';
        cout << "    This property is unowned,";
        if (player->getBalance() >= PURCHASE_PRICE){
            cout << " would you like to buy it for $" << PURCHASE_PRICE << "? (current balance is: $" << player->getBalance() << ") Y/N:\n";

            //bot player will always buy
            if(player->isBot()){ 
                cout << "    Y" << endl;
                choice = 'Y';
            //get user input
            } else { 
                do {
                    cout << "    ";
                    cin >> choice;
                    cin.ignore();
                } while (choice != 'Y' && choice != 'N');
            }
            
            //buy property
            if (choice == 'Y'){
                owner = player;
                player->buy(this, PURCHASE_PRICE);
                cout << "    Purchased! (new balance is $" << player->getBalance() << ")" << endl;
            }
        } else {
            cout << " but you cannot afford it" << endl;
        }

    //if already owned
    } else {
        if (owner == player){
            //if player is owner
            cout << "    You own this property" << endl;
        } else {
            //else pay the owner
            unsigned short int price = getPrice();
            owner->changeBalance(price);
            player->changeBalance(-price);
            cout << "    This property is owned by " << owner->getName() << "\n    Because they own " << owner->getNumRRs()
                << " railroad(s), you paid them $" << price << " (new balance is $" << player->getBalance() << ")" << endl;
        }
    }
    return;
}

void RailroadProperty::sell(){
    owner = nullptr;
    return;
}

string RailroadProperty::getType() const {
    return "Railroad";
}

vector<int> RailroadProperty::getPriceTable() const {
    vector<int> priceTable = {PURCHASE_PRICE, 0, 0, 25, 50, 100, 200, 0};
    return priceTable;
}

unsigned short int RailroadProperty::getNumHouses() const {
    return owner->getNumRRs();
}


