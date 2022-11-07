#ifndef People_h
#define People_h
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class People
{
protected:
    string name;
    Date birth;
    string address;
    Date arrivalDay;
    int phoneNumber;
public:
    People();
    ~People();
};

#endif