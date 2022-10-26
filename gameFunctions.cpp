#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "gameFunctions.h"
#include "Player.h"
#include "Property.h"

using namespace std;

void printColor(string s="", int color=7){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout << s;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return;
}

string center(string input, const unsigned int WIDTH){
    if (input.size() > WIDTH){
        input = input.substr(0, WIDTH);
    }
    int space = WIDTH - input.size();
    string before(int(space/2), ' ');
    string after((space/2 + (space&1)), ' ');
    return before + input + after;
}

void printGame(const vector<Player*> players, const vector<Property*> properties){
    // split up property names
    vector<vector<string>> names(40, {"",""});
    for (int i = 0; i < 40; i++){
        string fullname = properties[i]->getName();
        int split = fullname.length();
        for (int j = fullname.length(); j >= 0; j--){
            if (fullname[j] == ' '){
                split = j;
                break;
            }
            if (isalpha(fullname[j])){
                names[i][1] = fullname[j] + names[i][1];
            }
        }
        for (int j = 0; j < split; j++){
            names[i][0] += fullname[j];
        }
    }



    string pieces[4] = {"CPU1", "P1", "MOM", "jay"};
    vector<string> locations(40, "");
    for (unsigned int i = 0; i < players.size(); i++){
        locations[players[i]->where()] += "{" + pieces[i] + "}";
    }
    
    //row 1
    cout << "1  +--------------+----------+----------+----------+----------+----------+----------+----------+----------+----------+--------------+" << endl;
    //row 2
    cout << "2  |    Free      |" << center(names[21][0],10) << "|  Chance  |" << center(names[23][0],10) << "|" << center(names[24][0],10) << "|" << center(names[25][0],10)
        << "|" << center(names[26][0],10) << "|" << center(names[27][0],10) << "|" << center(names[28][0],10) << "|" << center(names[29][0],10) << "|              |" << endl;
    //row 3
    cout << "3  |              |" << center(names[21][1],10) << "|          |" << center(names[23][1],10) << "|" << center(names[24][1],10) << "|" << center(names[25][1],10)
        << "|" << center(names[26][1],10) << "|" << center(names[27][1],10) << "|" << center(names[28][1],10) << "|" << center(names[29][1],10) << "|     Go To    |" << endl;
    //row 4
    cout << "4  |" << center(locations[20],14) << "|" << center(locations[21],10) << "|" << center(locations[22],10) << "|" << center(locations[23],10) << "|" << center(locations[24],10) << "|" << center(locations[25],10)
        << "|" << center(locations[26],10) << "|" << center(locations[27],10) << "|" << center(locations[28],10) << "|" << center(locations[29],10) << "|" << center(locations[30], 14) << "|" << endl;
    //row 5
    cout << "5  |              |          |          |          |          |          |          |          |          |          |     Jail     |" << endl;
    //row 6
    cout << "6  |   Parking    |"; printColor("          ", 64); cout << "|          |"; printColor("          ", 64); cout << "|"; printColor("          ", 64); cout << "|          |";
    printColor("          ", 96); cout << "|"; printColor("          ", 96); cout << "|          |"; printColor("          ", 96); cout << "|              |" << endl;
    //row 7
    cout << "7  |--------------+----------+----------+----------+----------+----------+----------+----------+----------+----------+--------------|" << endl;
    //row 8
    cout << "8  |" << center(names[19][0],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32); cout << center(names[31][0],11) << "|" << endl;
    //row 9
    cout << "9  |" << center(names[19][1],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << center(names[31][1],11) << "|" << endl;
    //row 10
    cout << "10 |           ";
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << "           |" << endl;
    //row 11
    cout << "11 |--------------|                                                                                                  |--------------|" << endl;
    //row 12
    cout << "12 |" << center(names[18][0],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32); cout << center(names[32][0],11) << "|" << endl;
    //row 13
    cout << "13 |" << center(names[18][1],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << center(names[32][1],11) << "|" << endl;
    //row 14
    cout << "14 |           ";
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << "           |" << endl;
    //row 15
    cout << "15 |--------------|                                                                                                  |--------------|" << endl;
    //row 16
    cout << "16 |" << center(names[17][0], 14);
    cout << "|                                                                                                  |";
    cout << center(names[33][0], 14) << "|" << endl;
    //row 17
    cout << "17 |" << center(names[17][1], 14);
    cout << "|                                                                                                  |";
    cout << center(names[33][1], 14) << "|" << endl;
    //row 18
    cout << "18 |           ";
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << "           |" << endl;
    //row 19
    cout << "19 |--------------|                                                                                                  |--------------|" << endl;

    cout << endl;

    return;
}

