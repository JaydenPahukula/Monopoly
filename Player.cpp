
#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Player::Player(const string NAME, const bool BOT){
    name = NAME;
    bot = BOT;
    location = 0;
    inJail = false;
    jailCount = 0;
    getOutOfJailCards = 1;
    balance = 1500;
    srand(time(0));
}

bool Player::moveInJail(){

    //get user input
    char choice = ' ';
    if (!bot){
        cout << "  Currently in jail...\n  1 - Roll to try to get out\n  2 - Pay $50" << endl;
        if (getOutOfJailCards > 0){
            cout << "  3 - Use 'Get Out of Jail Free' card (you have " << getOutOfJailCards << ")" << endl << "  ";
            do {
                cin >> choice;
            } while (choice != '1' && choice != '2' && choice != '3');
        } else {
            do {
                cin >> choice;
            } while (choice != '1' && choice != '2');
        }
    } else {
        string choices;
        if (getOutOfJailCards > 0){
            choices = "123";
        } else {
            choices = "12";
        }
        choice = choices[rand()%choices.size()];
    }

    //pay to get out
    if (choice == '2'){
        cout << "Paid $50 and got out!" << endl;
        balance -= 50;
        inJail = false;
        location = 10;
        return true;
    }

    //use get out of jail free card
    if (choice == '3'){
        cout << "Used a 'Get Out of Jail Free' card! (you have " << getOutOfJailCards-1 << " remaining)" << endl;
        getOutOfJailCards--;
        inJail = false;
        location = 10;
        return true;
    }

    //roll
    array<int, 2> r = roll();
    cout << "  Rolled " << r[0] << " and " << r[1];

    if (r[0] == r[1]){
        cout << " - Doubles! You got out!" << endl;
        inJail = false;
        location = 10;
        return true;
    } else {
        jailCount += 1;
        if (jailCount >= 3){
            cout << "\nYou've been in jail for 3 turns, you must pay $50 to get out..." << endl;
            balance -= 50;
            inJail = false;
            location = 10;
            return true;
        } else {
            cout << "\nStill stuck in jail" << endl;
            return false;
        }
    }
}


void Player::preTurn(){
    char choice = ' ';
    while (1){
        cout << "  What would you like to do?\n  1 - Roll!\n  2 - View properties\n  3 - Buy houses\n  4 - Sell houses\n";
        if (bot){
            cout << "  1" << endl;
            choice = '1';
        } else {
            do {
                cout << "  ";
                cin >> choice;
            } while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
        }

        if (choice == '1'){
            return;
        }

        if (choice == '2'){
            printPropertyInfo();
        }

        if (choice == '3'){
            printOwnableProperties();
        }

        if (choice == '4'){
            cout << "\n  sell houses" << endl;
        }
    }

    return;
}


bool Player::move(){

    if (inJail){
        if (!moveInJail()){
            return false;
        }
    }

    if (!bot){
        cout << "  Press ENTER to roll:";
        cin.ignore();
        cin.ignore();
    }
    

    //roll
    array<int, 2> r = roll();
    cout << "  Rolled " << r[0] << " and " << r[1];

    //check for doubles
    bool doubles = false;
    if (r[0] == r[1]){
        cout << " - Doubles!";
        doubles = true;
    }
    cout << endl;

    //move
    location += r[0] + r[1];

    //check if passed go
    if (location >= 40){
        location -= 40;
        cout << "  Passed Go, Collected $200!" << endl;
        balance += 200;
    }

    return doubles;
}

void Player::goToJail(){
    inJail = true;
    location = 40;
    return;
}

void Player::buy(Property* PROPERTY, const unsigned int PRICE){
    balance -= PRICE;
    ownedProperties.push_back(PROPERTY);
}

void Player::changeBalance(const int AMOUNT){
    balance += AMOUNT;
    return;
}

int Player::getBalance() const {
    return balance;
}

unsigned short int Player::getLocation() const {
    return location;
}

string Player::getName() const {
    return name;
}

unsigned short int Player::getNumRRs() const {
    unsigned short int count = 0;
    for (unsigned int i = 0; i < ownedProperties.size(); i++){
        if (ownedProperties.at(i)->getType() == "Railroad"){
            count += 1;
        }
    }
    return count;
}

unsigned short int Player::getNumUtilities() const {
    unsigned short int count = 0;
    for (unsigned int i = 0; i < ownedProperties.size(); i++){
        if (ownedProperties.at(i)->getType() == "Utility"){
            count += 1;
        }
    }
    return count;
}

bool Player::isInJail() const {
    return inJail;
}

bool Player::isBot() const {
    return bot;
}

void Player::printOwnableProperties() const {
    cout << "            Name:                 Num Houses:" << endl;
    for (unsigned int i = 0; i < ownedProperties.size(); i++){
        if (ownedProperties[i]->getType() == "Ownable"){
            cout << "    " << i+1 << " - ";
            printColor("   ", ownedProperties[i]->getID());
            cout << " " << setw(21) << left << ownedProperties[i]->getName() << " " << ownedProperties[i]->getNumHouses() << endl;
        }
    }
    cout << endl;
    return;
}

void Player::printPropertyInfo() const {
    unsigned short int n = ownedProperties.size();
    cout << endl << name << "'s properties:";
    if (n == 0){
        cout << "\nYou have no properties yet" << endl << endl;
        return;
    }
    vector<vector<string>> names;
    vector<vector<int>> priceTables;
    cout << "\n             +";
    for (unsigned int i = 0; i < n; i++){
        cout << "------------+";
        names.push_back(splitName(ownedProperties[i]->getName()));
        priceTables.push_back(ownedProperties[i]->getPriceTable());
    }
    cout << "\n             |";
    for (unsigned int i = 0; i < n; i++){
        printColor("            ", ownedProperties[i]->getID());
        cout << "|";
    }
    cout << "\n             |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(names[i][0], 12) << "|";
    }
    cout << "\n             |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(names[i][1], 12) << "|";
    }
    cout << "\n+------------+";
    for (unsigned int i = 0; i < n; i++){
        cout << "------------+";
    }
    cout << "\n| num houses |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(ownedProperties[i]->getNumHouses()), 12) << "|";
    }
    cout << "\n+------------+";
    for (unsigned int i = 0; i < n; i++){
        cout << "------------+";
    }
    cout << "\n|       base |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(priceTables[i][2]), 12) << "|";
    }
    cout << "\n|    1 house |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(priceTables[i][3]), 12) << "|";
    }
    cout << "\n|   2 houses |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(priceTables[i][4]), 12) << "|";
    }
    cout << "\n|   3 houses |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(priceTables[i][5]), 12) << "|";
    }
    cout << "\n|   4 houses |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(priceTables[i][6]), 12) << "|";
    }
    cout << "\n|  hotel (5) |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(priceTables[i][7]), 12) << "|";
    }
    cout << "\n|house price |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(priceTables[i][1]), 12) << "|";
    }
    cout << "\n|   mortgage |";
    for (unsigned int i = 0; i < n; i++){
        cout << center(to_string(priceTables[i][0]/2), 12) << "|";
    }
    cout << "\n+------------+";
    for (unsigned int i = 0; i < n; i++){
        cout << "------------+";
    }
    cout << endl << endl;
}