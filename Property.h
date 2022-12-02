#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
using namespace std;

class Property final {

    string name;

    public:
        Property(string n);

        string getName();

};

#endif