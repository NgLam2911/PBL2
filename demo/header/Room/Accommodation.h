#ifndef Accommodation_h
#define Accommodation_h
#include <iostream>
#include "Room.h"
#include "People\ListStudent.h"

using namespace std;

class Accommodation : public Room
{
private:
    int numberOfBeg;
    int numberOfPeople;
    int costBedPerMonth;
    ListStudent listStu;
    Accommodation *next;
public:
    Accommodation();
    ~Accommodation();
    friend istream &operator>>(istream &in, Accommodation &x);
    friend ostream &operator<<(ostream &out, Accommodation &x);
};

#endif