
#include "Player.h"
#include "UtilityProperty.h"
#include "gameFunctions.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

UtilityProperty::UtilityProperty(const string NAME){
    name = NAME;
    owner = nullptr;
}

string UtilityProperty::getType() const {
    return "Utility";
}

void UtilityProperty::sell(){
    owner = nullptr;
    return;
}

unsigned short int UtilityProperty::getNumHouses() const {
    return owner->getNumUtilities();
}

void UtilityProperty::act(Player* player){
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
                    cin.ignore();
                } while (choice != 'Y' && choice != 'N');
            }
            
            if (choice == 'Y'){ //buy
                owner = player;
                player->buy(this, PURCHASEPRICE);
                cout << "    Purchased! (new balance is $" << player->getBalance() << ")" << endl;
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
            unsigned short int numUtilities = owner->getNumUtilities();
            unsigned short int x;
            if (numUtilities == 1){ x = 4; }
            else if (numUtilities == 2){ x = 10; }
            cout << "    This property is owned by " << owner->getName() << "\n    Because they own " << numUtilities
                << " utilities, you owe them " << x << " * dice\n      Press ENTER to Roll:";
            cin.ignore();

            array<int, 2> r = roll();
            cout << "      Rolled " << r[0] << " and " << r[1] << endl;
            unsigned short int price = (r[0] + r[1]) * x;
            owner->changeBalance(price);
            player->changeBalance(-price);
            cout << "    You paid them $" << price << " (new balance is $" << player->getBalance() << ")" << endl;
        }
    }
    return;
}

vector<int> UtilityProperty::getPriceTable() const {
    vector<int> priceTable = {PURCHASEPRICE, 0, 0, 4, 10, 0, 0};
    return priceTable;
}