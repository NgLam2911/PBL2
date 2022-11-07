#ifndef Acquaintance_h
#define Acquaintance_h
#include <iostream>
#include "People.h"

using namespace std;

class Acquaintance : public People
{
private:
    string visitRoom;
    string relationship;
    Acquaintance *next;
public:
    Acquaintance();
    ~Acquaintance();
    friend istream &operator>>(istream &in, Acquaintance &x);
    friend ostream &operator<<(ostream &out, Acquaintance &x);
};

#endif