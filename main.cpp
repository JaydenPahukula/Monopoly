#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

using namespace std;




int main() {

    Player* p1 = new Player(29);
    Player* p2 = new Player(21);
    Player* p3 = new Player(19);
    Player* p4 = new Player(30);
    vector<Player*> players = {p1, p2, p3, p4};
    
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

    printGame(players, properties);


    return 0;
}