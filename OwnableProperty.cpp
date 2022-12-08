
#include "Player.h"
#include "OwnableProperty.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
price table guide:
0 - purchase price
1 - house price
2 - base
3 - 1 house
4 - 2 houses
5 - 3 houses
6 - 4 houses
7 - hotel
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

string OwnableProperty::getType() const {
    return "Ownable";
}

int OwnableProperty::getNumHouses() const {
    return numHouses;
}

void OwnableProperty::changeHouses(const int N){
    numHouses += N;
    return;
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
            
            if (choice == 'Y'){ //buy
                owner = player;
                player->buy(this, priceTable[0]);
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

unsigned short int OwnableProperty::getPrice() const {
    return 1;
}

int OwnableProperty::getID() const {
    return id;
};

vector<int> OwnableProperty::getPriceTable() const {
    return priceTable;
}