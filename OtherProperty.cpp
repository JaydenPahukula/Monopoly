
#include "Player.h"
#include "OtherProperty.h"

#include <iostream>
#include <string>
using namespace std;

OtherProperty::OtherProperty(const string NAME, const short int LOCATION){
    name = NAME;
    location = LOCATION;
}

string OtherProperty::getType() const {
    return "Other";
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
            cout << "    Drawing CC..." << endl;
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
            cout << "    Drawing Chance..." << endl;
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