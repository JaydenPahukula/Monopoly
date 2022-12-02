#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

using namespace std;




int main() {

    Player* p1 = new Player();
    vector<Player*> players = {p1};
    vector<Property*> properties;
    ifstream propertiesFile("settings/properties.txt");
    string name;
    for (int i = 0; i < 40; i++){
        if(getline(propertiesFile, name).fail()){
            cerr << "Error reading properties.txt";
            return -1;
        }
        properties.push_back(new Property(name));
    }
    propertiesFile.close();

    while (true){
        printGame(players, properties);
        p1->move();
        cout << "Press ENTER to continue...";
        cin.ignore();
    }


    return 0;
}