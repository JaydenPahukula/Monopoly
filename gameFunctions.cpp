#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "gameFunctions.h"
#include "Player.h"
#include "Property.h"
#include "OtherProperty.h"
#include "RailroadProperty.h"
#include "UtilityProperty.h"
#include "OwnableProperty.h"

using namespace std;

array<int, 2> roll(){
    array<int, 2> r = {(rand()%6)+1,(rand()%6)+1};
    return r;
}

void setup(vector<Property*>* properties){
    properties->at(0) = new OtherProperty("other", 0);
    properties->at(1) = new OwnableProperty("ownable", 0);
    properties->at(2) = new OtherProperty("other", 2);
    properties->at(3) = new OwnableProperty("ownable", 0);
    properties->at(4) = new OtherProperty("other", 4);
    properties->at(5) = new RailroadProperty("railroad");
    properties->at(6) = new OwnableProperty("ownable", 1);
    properties->at(7) = new OtherProperty("other", 7);
    properties->at(8) = new OwnableProperty("ownable", 1);
    properties->at(9) = new OwnableProperty("ownable", 1);
    properties->at(10) = new OtherProperty("other", 10);
    properties->at(11) = new OwnableProperty("ownable", 2);
    properties->at(12) = new UtilityProperty("electric company");
    properties->at(13) = new OwnableProperty("ownable", 2);
    properties->at(14) = new OwnableProperty("ownable", 2);
    properties->at(15) = new RailroadProperty("railroad");
    properties->at(16) = new OwnableProperty("ownable", 3);
    properties->at(17) = new OtherProperty("other", 17);
    properties->at(18) = new OwnableProperty("ownable", 3);
    properties->at(19) = new OwnableProperty("ownable", 3);
    properties->at(20) = new OtherProperty("other", 20);
    properties->at(21) = new OwnableProperty("ownable", 4);
    properties->at(22) = new OtherProperty("other", 22);
    properties->at(23) = new OwnableProperty("ownable", 4);
    properties->at(24) = new OwnableProperty("ownable", 4);
    properties->at(25) = new RailroadProperty("railroad");
    properties->at(26) = new OwnableProperty("ownable", 5);
    properties->at(27) = new OwnableProperty("ownable", 5);
    properties->at(28) = new UtilityProperty("water works");
    properties->at(29) = new OwnableProperty("ownable", 5);
    properties->at(30) = new OtherProperty("other", 30);
    properties->at(31) = new OwnableProperty("ownable", 6);
    properties->at(32) = new OwnableProperty("ownable", 6);
    properties->at(33) = new OtherProperty("other", 33);
    properties->at(34) = new OwnableProperty("ownable", 6);
    properties->at(35) = new RailroadProperty("railroad");
    properties->at(36) = new OtherProperty("other", 36);
    properties->at(37) = new OwnableProperty("ownable", 7);
    properties->at(38) = new OtherProperty("other", 38);
    properties->at(39) = new OwnableProperty("ownable", 7);
}

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
        unsigned int split = fullname.length();
        for (int j = fullname.length(); j >= 0; j--){
            if (fullname[j] == ' '){
                split = j;
                break;
            }
            if (isalpha(fullname[j])){
                names[i][1] = fullname[j] + names[i][1];
            }
        }
        if (split == fullname.length()){
            //one word
            names[i][0] = fullname;
            names[i][1] = "";
        } else {
            for (unsigned int j = 0; j < split; j++){
            names[i][0] += fullname[j];
        }
        }
        

    }

    string pieces[4] = {"CPU1", "P1", "P2", "ME"};
    vector<string> locations(41, "");
    for (unsigned int i = 0; i < players.size(); i++){
        int l = players[i]->getLocation();
        if (players[i]->isInJail() == true){
            l = 40;
        }
        locations[l] += "{" + pieces[i] + "}";
    }
    
    //row 1
    cout << "1  +--------------+----------+----------+----------+----------+----------+----------+----------+----------+----------+--------------+" << endl;
    //row 2
    cout << "2  |" << center(names[20][0],14) << "|" << center(names[21][0],10) << "|" << center(names[22][0],10) << "|" << center(names[23][0],10)
        << "|" << center(names[24][0],10) << "|" << center(names[25][0],10) << "|" << center(names[26][0],10) << "|" << center(names[27][0],10)
        << "|" << center(names[28][0],10) << "|" << center(names[29][0],10) << "|              |" << endl;
    //row 3
    cout << "3  |              |" << center(names[21][1],10) << "|    ?     |" << center(names[23][1],10) << "|" << center(names[24][1],10)
        << "|" << center(names[25][1],10) << "|" << center(names[26][1],10) << "|" << center(names[27][1],10) << "|" << center(names[28][1],10)
        << "|" << center(names[29][1],10) << "|" << center(names[30][0],14) << "|" << endl;
    //row 4
    cout << "4  |" << center(locations[20],14) << "|" << center(locations[21],10) << "|          |" << center(locations[23],10) << "|"
        << center(locations[24],10) << "|          |" << center(locations[26],10) << "|" << center(locations[27],10) << "|          |"
        << center(locations[29],10) << "|" << center(locations[30], 14) << "|" << endl;
    //row 5
    cout << "5  |              |          |" << center(locations[22],10) << "|          |          |" << center(locations[25],10)
        << "|          |          |" << center(locations[28],10) << "|          |" << center(names[30][1],14) << "|" << endl;
    //row 6
    cout << "6  |" << center(names[20][1],14) << "|"; printColor("          ", 64); cout << "|          |"; printColor("          ", 64);
    cout << "|"; printColor("          ", 64); cout << "|          |"; printColor("          ", 96); cout << "|"; printColor("          ", 96);
    cout << "|          |"; printColor("          ", 96); cout << "|              |" << endl;
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
    cout << "10 |" << center(locations[19],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << center(locations[31],11) << "|" << endl;
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
    cout << "14 |" << center(locations[18],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << center(locations[32],11) << "|" << endl;
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
    cout << "18 |" << center(locations[17],14)
        << "|                                                                                                  |"
        << center(locations[33],14) << "|" << endl;
    //row 19
    cout << "19 |--------------|                                                                                                  |--------------|" << endl;
    //row 20
    cout << "20 |" << center(names[16][0],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32); cout << center(names[34][0],11) << "|" << endl;
    //row 21
    cout << "21 |" << center(names[16][1],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << center(names[34][1],11) << "|" << endl;
    //row 22
    cout << "22 |" << center(locations[16],11);
    printColor("   ", 196);
    cout << "|                                                                                                  |";
    printColor("   ", 32);
    cout << center(locations[34],11) << "|" << endl;
    //row 23
    cout << "23 |--------------|                                                                                                  |--------------|" << endl;
    //row 24
    cout << "24 |" << center(names[15][0], 14);
    cout << "|                                                                                                  |";
    cout << center(names[35][0], 14) << "|" << endl;
    //row 25
    cout << "25 |" << center(names[15][1], 14);
    cout << "|                                                                                                  |";
    cout << center(names[35][1], 14) << "|" << endl;
    //row 26
    cout << "26 |" << center(locations[15],14)
        << "|                                                                                                  |"
        << center(locations[35],14) << "|" << endl;
    //row 27
    cout << "27 |--------------|                                                                                                  |--------------|" << endl;
    //row 28
    cout << "28 |" << center(names[14][0],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |" << center(names[36][0],14) << "|" << endl;
    //row 29
    cout << "29 |" << center(names[14][1],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |      ?       |" << endl;
    //row 30
    cout << "30 |" << center(locations[14],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |" << center(locations[36],14) << "|" << endl;
    //row 31
    cout << "31 |--------------|                                                                                                  |--------------|" << endl;
    //row 32
    cout << "32 |" << center(names[13][0],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |";
    printColor("   ", 16); cout << center(names[37][0],11) << "|" << endl;
    //row 33
    cout << "33 |" << center(names[13][1],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |";
    printColor("   ", 16);
    cout << center(names[37][1],11) << "|" << endl;
    //row 34
    cout << "34 |" << center(locations[13],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |";
    printColor("   ", 16);
    cout << center(locations[37],11) << "|" << endl;
    //row 35
    cout << "35 |--------------|                                                                                                  |--------------|" << endl;
    //row 36
    cout << "36 |" << center(names[12][0], 14);
    cout << "|                                                                                                  |";
    cout << center(names[38][0], 14) << "|" << endl;
    //row 37
    cout << "37 |" << center(names[12][1], 14);
    cout << "|                                                                                                  |";
    cout << center(names[38][1], 14) << "|" << endl;
    //row 38
    cout << "38 |" << center(locations[12],14)
        << "|                                                                                                  |"
        << center(locations[38],14) << "|" << endl;
    //row 39
    cout << "39 |--------------|                                                                                                  |--------------|" << endl;
    //row 40
    cout << "40 |" << center(names[11][0],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |";
    printColor("   ", 16); cout << center(names[39][0],11) << "|" << endl;
    //row 41
    cout << "41 |" << center(names[11][1],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |";
    printColor("   ", 16);
    cout << center(names[39][1],11) << "|" << endl;
    //row 42
    cout << "42 |" << center(locations[11],11);
    printColor("   ", 208);
    cout << "|                                                                                                  |";
    printColor("   ", 16);
    cout << center(locations[39],11) << "|" << endl;
    //row 43
    cout << "43 |---+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+--------------|" << endl;
    //row 44
    cout << "44 |   |   Jail   |"; printColor("          ", 176); cout << "|"; printColor("          ", 176); cout << "|" << center(names[7][0],10) << "|"; 
    printColor("          ", 176); cout << "|" << center(names[5][0],10) << "|" << center(names[4][0],10) << "|"; printColor("          ", 128);
    cout << "|" << center(names[2][0],10) << "|"; printColor("          ", 128); cout << "|" << center(names[0][0],14) << "|" << endl;
    //row 55
    cout << "55 |   |          |" << center(names[9][0],10) << "|"  << center(names[8][0],10) << "|    ?     |" << center(names[6][0],10) << "|"
        << center(names[5][1],10) << "|" << center(names[4][1],10) << "|" << center(names[3][0],10) << "|" << center(names[2][1],10) << "|"
        << center(names[1][0],10) << "|  <---------  |"<< endl;
    //row 56
    cout << "56 |   |" << center(locations[40],10) << "|" << center(names[9][1],10) << "|" << center(names[8][1],10) << "|          |" << center(names[6][1],10)
        << "|          |          |" << center(names[3][1],10) << "|          |" << center(names[1][1],10) << "|              |" << endl;
    //row 57
    cout << "57 |   |__________|" << center(locations[9],10) << "|" << center(locations[8],10) << "|" << center(locations[7],10) << "|"
        << center(locations[6],10) << "|" << center(locations[5],10) << "|" << center(locations[4],10) << "|" << center(locations[3],10)
        << "|" << center(locations[2],10) << "|" << center(locations[1],10) << "|" << center(locations[0],14) << "|" << endl;
    //row 58
    cout << "58 |" << center(locations[10],14) << "|          |          |          |          |          |          |          |          |          |              |" << endl;
    //row 59
    cout << "59 +--------------+----------+----------+----------+----------+----------+----------+----------+----------+----------+--------------+" << endl;

    return;
}

