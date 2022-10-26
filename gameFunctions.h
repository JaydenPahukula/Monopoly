#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include <string>
#include <vector>

#include "Player.h"
#include "Property.h"

using namespace std;

void printColor(string s, int color);

string center(string input, const unsigned int WIDTH);

void printGame(const vector<Player*> players, const vector<Property*> properties);

#endif