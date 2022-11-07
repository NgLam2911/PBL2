#ifndef StudyRoom_h
#define StudyRoom_h
#include <iostream>
#include "Room.h"

using namespace std;

class StudyRoom : public Room
{
private:
    int table;
    int chair;
    StudyRoom *next;
public:
    StudyRoom();
    ~StudyRoom();
    friend istream &operator>>(istream &in, StudyRoom &x);
    friend ostream &operator<<(ostream &out, StudyRoom &x);
};

#endif