#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "Player.h"
#include "Property.h"

#include <string>
#include <vector>

std::array<int, 2> roll();

void setup(std::vector<Player*>* players, std::vector<Property*>* properties);

void printColor(std::string s, int color);

std::string center(std::string input, const unsigned int WIDTH);

std::vector<std::string> splitName(const std::string NAME);

void printGame(const std::vector<Player*> players, const std::vector<Property*> properties);


#endif