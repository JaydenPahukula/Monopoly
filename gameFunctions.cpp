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

string center(string input, const unsigned int WIDTH=10){
    if (input.size() > WIDTH){
        input = input.substr(0, WIDTH);
    }
    int space = WIDTH - input.size();
    string before(int(space/2), ' ');
    string after((space/2 + (space&1)), ' ');
    return before + input + after;
}

void printGame(vector<Player*> players){
    const vector<string> names(40, "Atlantic");
    const vector<string> names1(40, "Avenue");
    const vector<unsigned short> prices(40, 200);
    string pieces[4] = {"CPU1", "P1", "MOM", "jay"};
    vector<string> locations(40, "");
    for (unsigned int i = 0; i < players.size(); i++){
        locations[players[i]->where()] += "{" + pieces[i] + "}";
    }
 
    //row 1
    cout << "1  +--------------+----------+----------+----------+----------+----------+----------+----------+----------+----------+--------------+" << endl;
    //row 2
    cout << "2  |    Free      |" << center(names[21]) << "|  Chance  |" << center(names[23]) << "|" << center(names[24]) << "|" << center(names[25])
        << "|" << center(names[26]) << "|" << center(names[27]) << "|" << center(names[28]) << "|" << center(names[29]) << "|              |" << endl;
    //row 3
    cout << "3  |              |" << center(names1[21]) << "|          |" << center(names1[23]) << "|" << center(names1[24]) << "|" << center(names1[25])
        << "|" << center(names1[26]) << "|" << center(names1[27]) << "|" << center(names1[28]) << "|" << center(names1[29]) << "|     Go To    |" << endl;
    //row 4
    cout << "4  |" << center(locations[20],14) << "|" << center(locations[21]) << "|" << center(locations[22]) << "|" << center(locations[23]) << "|" << center(locations[24]) << "|" << center(locations[25])
        << "|" << center(locations[26]) << "|" << center(locations[27]) << "|" << center(locations[28]) << "|" << center(locations[29]) << "|" << center(locations[30], 14) << "|" << endl;
    //row 5
    cout << "5  |              |          |          |          |          |          |          |          |          |          |     Jail     |" << endl;
    //row 6
    cout << "6  |   Parking    |";
    printColor("          ", 64);
    cout << "|          |";
    printColor("          ", 64);
    cout << "|";
    printColor("          ", 64);
    cout << "|          |";
    printColor("          ", 96);
    cout << "|";
    printColor("          ", 96);
    cout << "|          |";
    printColor("          ", 96);
    cout << "|              |" << endl;
    //row 7
    cout << "7  |--------------+----------+----------+----------+----------+----------+----------+----------+----------+----------+--------------|" << endl;
    //row 8
    cout << "8  | " << center(names[19]);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << center(names[31]) << " |" << endl;
    //row 9
    cout << "9  | " << center(names1[19]);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << center(names1[31]) << " |" << endl;
    //row 10
    cout << "10 |           ";
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << "           |" << endl;
    //row 11
    cout << "11 |--------------|                                                                                                  |--------------|" << endl;

    cout << endl;

    return;
}

