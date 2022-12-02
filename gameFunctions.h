#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "Player.h"
#include "Property.h"

#include <string>
#include <vector>

using namespace std;

array<int, 2> roll();
void setup(vector<Property*>* properties);
void printColor(string s, int color);
string center(string input, const unsigned int WIDTH);
void printGame(const vector<Player*> players, const vector<Property*> properties);




#endif