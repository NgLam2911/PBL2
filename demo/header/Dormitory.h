#ifndef Dormitory_h
#define Dormitory_h
#include "Room\ListStudyRoom.h"
#include "Room\ListAccommodation.h"

class Dormitory
{
private:
    string name;
    string address;
    ListStudyRoom listStuRoom;
    ListAccommodation listAccom;
public:
    Dormitory();
    ~Dormitory();
    friend istream &operator>>(istream &in, Dormitory &x);
    friend ostream &operator<<(ostream &out, Dormitory &x);
};

#endif