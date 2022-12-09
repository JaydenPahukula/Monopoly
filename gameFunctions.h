#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "Player.h"
#include "Property.h"

#include <array>
#include <string>
#include <vector>
using namespace std;

//sets up the game
void setup(vector<Player*>* players, vector<Property*>* properties);

//rolls two die
array<int, 2> roll();

//prints string in color
void print_color(string s, int color);

//returns a string centered with given width
string center(string input, const unsigned int WIDTH);

//splits a location name into two parts
vector<string> split_name(const string NAME);

//prints the current game state
void print_game(const vector<Player*> players, const vector<Property*> properties);


#endif