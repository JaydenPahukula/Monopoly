
#include "gameFunctions.h"
#include "Player.h"
#include "Property.h"

#include <array>
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
    getOutOfJailCards = 0;
    balance = 1500;
}



// private functions --------------------------

bool Player::moveInJail(){

    //get user input
    char choice = ' ';
    if (!bot){
        cout << "  You are currently in jail...\n    1 - Roll to try to get out\n    2 - Pay $50" << endl;
        if (getOutOfJailCards > 0){
            cout << "    3 - Use 'Get Out of Jail Free' card (you have " << getOutOfJailCards << ")" << endl;
            do {
                cout << "    ";
                cin >> choice;
                cin.ignore();
            } while (choice != '1' && choice != '2' && choice != '3');
        } else {
            do {
                cout << "    ";
                cin >> choice;
                cin.ignore();
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
        cout << "  Paid $50 and got out!" << endl;
        balance -= 50;
        inJail = false;
        location = 10;
        return true;
    }

    //use get out of jail free card
    if (choice == '3'){
        cout << "  Used a 'Get Out of Jail Free' card! (you have " << getOutOfJailCards-1 << " remaining)" << endl;
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
            cout << "\n  You've been in jail for 3 turns, you must pay $50 to get out...\n  Paid $50" << endl;
            balance -= 50;
            inJail = false;
            location = 10;
            return true;
        } else {
            cout << "\n  Still stuck in jail" << endl;
            return false;
        }
    }
}

vector<int> Player::printOwnableProperties() const {
    cout << "            Name:                 Num Houses:" << endl;
    vector<int> options;
    for (unsigned int i = 0; i < ownedProperties.size(); i++){
        if (ownedProperties[i]->getType() == "Ownable"){
            options.push_back(i);
            cout << "    " << i+1 << " - ";
            print_color("   ", ownedProperties[i]->getID());
            cout << " " << setw(21) << left << ownedProperties[i]->getName() << " " << ownedProperties[i]->getNumHouses() << endl;
        }
    }
    if (options.size() == 0){
        cout << "You don't have any properties that you can put houses on" << endl;
    }
    return options;
}

void Player::printPropertyInfo() const {

    unsigned short int n = ownedProperties.size();
    cout << endl << name << "'s properties:";

    //if player doesn't have any properties
    if (n == 0){
        cout << "\nYou don't have any properties yet\n\nPress ENTER to continue:";
        cin.ignore();
        cout << endl;
        return;
    }

    //print all properties and price info
    vector<vector<string>> names;
    vector<vector<int>> priceTables;
    cout << "\n             +";
    for (unsigned int i = 0; i < n; i++){
        cout << "------------+";
        names.push_back(split_name(ownedProperties[i]->getName()));
        priceTables.push_back(ownedProperties[i]->getPriceTable());
    }
    cout << "\n             |";
    for (unsigned int i = 0; i < n; i++){
        print_color("            ", ownedProperties[i]->getID());
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
    cout << "\n\nPress ENTER to continue:";
    cin.ignore();
    cout << endl;
    return;
}



// public functions --------------------------

void Player::preTurn(){

    char choice = ' ';
    while (1){

        //get user input
        cout << "  What would you like to do? (you have $" << balance << ")\n  1 - Start your turn\n  2 - View owned properties\n  3 - Buy a house\n  4 - Sell a house\n";
        if (bot){
            cout << "  1" << endl;
            choice = '1';
        } else {
            do {
                cout << "  ";
                cin >> choice;
                cin.ignore();
            } while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
        }

        //begin turn
        if (choice == '1'){ return; }

        //view properties
        if (choice == '2'){ printPropertyInfo(); }

        //buy/sell house
        if (choice == '3' || choice == '4'){

            //determine which property to buy/sell from
            cout << "\n  Which property?" << endl;
            char propertyChoice = ' ';
            vector<int> options = printOwnableProperties();
            if (options.size() == 0){
                cout << "\nPress ENTER to continue:";
                cin.ignore();
                cout << endl;
                continue;
            }
            bool done = false;
            while (1){
                cout << "    ";
                cin >> propertyChoice;
                cin.ignore();
                for (unsigned int i = 0; i < options.size(); i++){
                    if (int(propertyChoice-'1') == options[i]){
                        done = true;
                        break;
                    }
                }
                if (done){ break; }
            }
            int property = int(propertyChoice-'1');

            //buy house
            if (choice == '3'){

                //check if property is already full
                if (ownedProperties[property]->getNumHouses() >= 5){
                    cout << "  You cannot buy anymore houses on this property" << endl << endl;
                    continue;
                }

                //check if player can afford it
                if(ownedProperties[property]->getPriceTable()[1] > balance){
                    cout << "  You cannot afford a house on this property\n\nPress ENTER to continue:";
                    cin.ignore();
                    cout << endl;
                    continue;
                }

                //purchase house
                cout << "\n  Purchase 1 house on " << ownedProperties[property]->getName() << " for $" << ownedProperties[property]->getPriceTable()[1] << "? Y/N:" << endl;
                char confirm = ' ';
                do {
                    cout << "  ";
                    cin >> confirm;
                    cin.ignore();
                } while (confirm != 'Y' && confirm != 'N');
                if (confirm == 'Y'){
                    balance -= ownedProperties[property]->getPriceTable()[1];
                    ownedProperties[property]->changeHouses(1);
                    cout << "  Purchased! (new balance is $" << balance << ")" << endl;
                }
                cout << endl;

            //sell house
            } else {

                //check if property has houses
                if (ownedProperties[property]->getNumHouses() <= 0){
                    cout << "  This property doesn't have any houses to sell" << endl << endl;
                    continue;
                }

                //sell house
                cout << "\n  Sell 1 house on " << ownedProperties[property]->getName() << " for $" << ownedProperties[property]->getPriceTable()[1] << "? Y/N:" << endl;
                char confirm = ' ';
                do {
                    cout << "  ";
                    cin >> confirm;
                    cin.ignore();
                } while (confirm != 'Y' && confirm != 'N');
                if (confirm == 'Y'){
                    balance += ownedProperties[property]->getPriceTable()[1];
                    ownedProperties[property]->changeHouses(-1);
                    cout << "  Sold! (new balance is $" << balance << ")" << endl;
                }
                cout << endl;
            }
        }

    }

    return;
}

bool Player::move(){

    //if in jail
    if (inJail){
        if (!moveInJail()){
            return false;
        }
    }

    if (!bot){
        cout << "  Press ENTER to roll:";
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

bool Player::resolveDebt(){

    //get user input
    char choice = ' ';
    cout << "    You are $" << -balance << " in debt. What would you like to do?\n      1 - Sell a house\n      2 - Go bankrupt" << endl;
    if (bot){
        //bots will always choose to go bankrupt
        cout << "      2" << endl;
        choice = '2';
    } else {
        do {
            cout << "      ";
            cin >> choice;
            cin.ignore();
        } while (choice != '1' && choice != '2');
    }

    //go bankrupt
    if (choice == '2'){
        for (unsigned int i = 0; i < ownedProperties.size(); i++){
            ownedProperties[i]->sell();
        }
        ownedProperties.clear();
        return false;
    }

    //sell a house
    if (choice == '1'){

        //determine which property to sell
        cout << "\n    Which property?" << endl;
        char propertyChoice = ' ';
        vector<int> options = printOwnableProperties();
        if (options.size() == 0){
            cout << endl;
            return true;
        }
        bool done = false;
        while (1){
            cout << "    ";
            cin >> propertyChoice;
            cin.ignore();
            for (unsigned int i = 0; i < options.size(); i++){
                if (int(propertyChoice-'1') == options[i]){
                    done = true;
                    break;
                }
            }
            if (done){ break; }
        }
        int property = int(propertyChoice-'1');

        //check if property has houses
        if (ownedProperties[property]->getNumHouses() <= 0){
            cout << "    This property doesn't have any houses to sell" << endl << endl;
            return true;
        }

        //sell house
        balance += ownedProperties[property]->getPriceTable()[1];
        ownedProperties[property]->changeHouses(-1);
        cout << "    Sold 1 house on " << ownedProperties[property]->getName() << " for $" << ownedProperties[property]->getPriceTable()[1] << endl << endl;
    }
    return true;
}

void Player::buy(Property* PROPERTY, const unsigned int PRICE){
    balance -= PRICE;
    ownedProperties.push_back(PROPERTY);
    return;
}

void Player::drawChanceCard(){
    unsigned short int r = rand() % 16;
    cout << "      ";
    switch (r){
        case 0: {
            cout << "Advance to Boardwalk" << endl;
            location = 39;
            break;
        } case 1: {
            cout << "Advance to Go (Collect $200)" << endl;
            location = 0;
            balance += 200;
            break;
        } case 2: {
            cout << "Advance to Illinois Avenue. If you pass Go, collect $200" << endl;
            if (location > 24){
                cout << "      Passed Go, Collected $200!" << endl;
            }
            location = 24;
            break;
        } case 3: {
            cout << "Advance to St. Charles Place. If you pass Go, collect $200" << endl;
            if (location > 11){
                cout << "      Passed Go, Collected $200!" << endl;
            }
            location = 11;
            break;
        } case 4:
          case 5: {
            cout << "Advance token to the nearest Railroad" << endl;
            if (location < 15){
                location = 15;
            } else if (location < 25){
                location = 25;
            } else {
                location = 5;
            }
            break;
        } case 6: {
            cout << "Advance token to the nearest Utility" << endl;
            if (location < 12 || location > 28){
                location = 12;
            } else {
                location = 28;
            }
            break;
        } case 7: {
            cout << "Bank pays you dividend of $50" << endl;
            balance += 50;
            break;
        } case 8: {
            getOutOfJailCards += 1;
            cout << "Get Out of Jail Free (you now have " << getOutOfJailCards << ")" << endl;
            break;
        } case 9: {
            cout << "Go back 3 spaces" << endl;
            location -= 3;
            break;
        } case 10: {
            cout << "Go to Jail. Go directly to jail, do not pass Go, do not collect $200" << endl;
            goToJail();
            break;
        } case 11: {
            cout << "Make general repairs on all your property. For each house pay $25. For each hotel pay $100" << endl;
            int total = 0;
            for (unsigned int i = 0; i < ownedProperties.size(); i++){
                if (ownedProperties[i]->getNumHouses() == 5){
                    total += 100;
                } else {
                    total += 25 * ownedProperties[i]->getNumHouses();
                }
            }
            balance -= total;
            cout << "        You paid $" << total << endl;
            break;
        } case 12: {
            cout << "Speeding fine $15" << endl;
            balance -= 15;
            break;
        } case 13: {
            cout << "Take a trip to Reading Railroad. If you pass Go, collect $200" << endl;
            if (location > 5){
                cout << "      Passed Go, Collected $200!" << endl;
            }
            location = 5;
            break;
        } case 14: {
            cout << "You have been elected Chairman of the Board. Pay $50" << endl;
            balance -= 50;
            break;
        } case 15: {
            cout << "Your building loan matures. Collect $150" << endl;
            balance += 150;
            break;
        }
    }
    return;
}

void Player::drawCCCard(){
    unsigned short int r = rand() % 16;
    cout << "      ";
    switch (r){
        case 0: {
            cout << "Advance to Go (Collect $200)" << endl;
            location = 0;
            balance += 200;
            break;
        } case 1: {
            cout << "Bank error in your favor. Collect $200" << endl;
            balance += 200;
            break;
        } case 2: {
            cout << "Doctor's fee. Pay $50" << endl;
            balance -= 50;
            break;
        } case 3: {
            cout << "From sale of stock you get $50" << endl;
            balance += 50;
            break;
        } case 4: {
            getOutOfJailCards += 1;
            cout << "Get Out of Jail Free (you now have " << getOutOfJailCards << ")" << endl;
            break;
        } case 5: {
            cout << "Go to Jail. Go directly to jail, do not pass Go, do not collect $200" << endl;
            goToJail();
            break;
        } case 6: {
            cout << "Holiday fund matures. Receive $100" << endl;
            balance += 100;
            break;
        } case 7: {
            cout << "Income tax refund. Collect $20" << endl;
            balance += 20;
            break;
        } case 8: {
            cout << "It is your birthday. Collect $10" << endl; //i cheated on this one
            balance += 10;
            break;
        } case 9: {
            cout << "Live insurance matures. Collect $100" << endl;
            balance += 100;
            break;
        } case 10: {
            cout << "Pay hospital fees of $100" << endl;
            balance -= 100;
            break;
        } case 11: {
            cout << "Pay school fees of $50" << endl;
            balance -= 50;
            break;
        } case 12: {
            cout << "Receive $25 consultancy fee" << endl;
            balance += 25;
            break;
        } case 13: {
            cout << "You are assessed for street repair. $40 per house. $115 per hotel" << endl;
            int total = 0;
            for (unsigned int i = 0; i < ownedProperties.size(); i++){
                if (ownedProperties[i]->getNumHouses() == 5){
                    total += 115;
                } else {
                    total += 40 * ownedProperties[i]->getNumHouses();
                }
            }
            balance -= total;
            cout << "        You paid $" << total << endl;
            break;
        } case 14: {
            cout << "You have won second prize in a beauty contest. Collect $10" << endl;
            balance += 10;
            break;
        } case 15: {
            cout << "You inherit $100" << endl;
            balance += 100;
            break;
        }
    }
    return;
}

void Player::changeBalance(const int AMOUNT){
    balance += AMOUNT;
    return;
}



// getters -----------------------------------

bool Player::isInJail() const {
    return inJail;
}

bool Player::isBot() const {
    return bot;
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

