
#include "OwnableProperty.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * price table guide:
 * 0 - purchase price
 * 1 - house price
 * 2 - base
 * 3 - 1 house
 * 4 - 2 houses
 * 5 - 3 houses
 * 6 - 4 houses
 * 7 - hotel
*/

OwnableProperty::OwnableProperty(const string NAME, const int ID, const vector<int> TABLE){
    name = NAME;
    id = ID;
    owner = nullptr;
    priceTable = vector<int>(8, 0);
    for (unsigned int i = 0; i < 8; i++){
        priceTable[i] = TABLE[i];
    }
    numHouses = 0;
}

unsigned short int OwnableProperty::getPrice() const {
    return priceTable[numHouses+2];
}

void OwnableProperty::act(Player* player){

    //if unowned
    if (owner == nullptr){
        char choice = '0';
        cout << "    This property is unowned,";
        if (player->getBalance() >= priceTable[0]){
            cout << " would you like to buy it for $" << priceTable[0] << "? (current balance is: $" << player->getBalance() << ") Y/N:\n";

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
                player->buy(this, priceTable[0]);
                cout << "    Purchased! (new balance is $" << player->getBalance() << ")" << endl;
            }
        } else {
            cout << " but you cannot afford it" << endl;
        }

    //if already owned
    } else {
        if (owner == player){
            //if player is the owner
            cout << "    You own this property" << endl;
        } else {
            //else pay the owner
            unsigned short int price = getPrice();
            owner->changeBalance(price);
            player->changeBalance(-price);
            cout << "    This property is owned by " << owner->getName() << "\n    You paid them $" << price;
            if (numHouses >= 5){
                cout << " (1 hotel)" << endl;
            } else if (numHouses > 0){
                cout << " (" << numHouses << " houses)" << endl;
            } else {
                cout << endl;
            }
        }
    }
    return;
}

void OwnableProperty::sell(){
    owner = nullptr;
    numHouses = 0;
    return;
}

void OwnableProperty::changeHouses(const int N){
    numHouses += N;
    return;
}

string OwnableProperty::getType() const {
    return "Ownable";
}

int OwnableProperty::getID() const {
    return id;
};

vector<int> OwnableProperty::getPriceTable() const {
    return priceTable;
}

unsigned short int OwnableProperty::getNumHouses() const {
    return numHouses;
}