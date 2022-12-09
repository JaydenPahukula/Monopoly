
#include "OtherProperty.h"
#include "Player.h"

#include <iostream>
#include <string>
using namespace std;


OtherProperty::OtherProperty(const string NAME, const short int LOCATION){
    name = NAME;
    location = LOCATION;
}

void OtherProperty::act(Player* player){
    switch (location) {
        //GO
        case 0:
            break;
        //Community Chest
        case 2:
        case 17:
        case 33:
            cout << "    Drawing Community Chest Card..." << endl;
            player->drawCCCard();
            break;
        //Income Tax
        case 4:
            player->changeBalance(-200);
            cout << "    Paid $200" << endl;
            break;
        //Chance
        case 7:
        case 22:
        case 36:
            cout << "    Drawing Chance Card..." << endl;
            player->drawChanceCard();
            break;
        case 10:
            cout << "    Just visiting!" << endl;
            break;
        //Free Parking
        case 20:
            break;
        //Go To Jail
        case 30:
            cout << "    Sent to jail" << endl;
            player->goToJail();
            break;
        //Luxury Tax
        case 38:
            player->changeBalance(-100);
            cout << "    Paid $100" << endl;
            break;
        //it should never get here
        default:
            cout << "ERROR in OtherProperty::act()" << endl;
            break;
    }
    return;
}

void OtherProperty::sell(){
    return;
}

string OtherProperty::getType() const {
    return "Other";
}

vector<int> OtherProperty::getPriceTable() const {
    vector<int> priceTable = {-1, -1, -1, -1, -1, -1, -1};
    return priceTable;
}

unsigned short int OtherProperty::getNumHouses() const {
    return -1;
}

