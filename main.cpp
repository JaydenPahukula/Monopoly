
#include "Player.h"
#include "Property.h"
#include "gameFunctions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;




int main() {

    vector<Property*> properties(41, nullptr);

    setup(&properties);

    for (unsigned int i = 0; i < 40; i++){
        cout << properties[i]->getName() << endl;
    }

    for (unsigned int i = 0; i < 40; i++){
        delete properties[i];
    }


    return 0;
}