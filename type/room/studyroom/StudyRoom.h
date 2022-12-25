#ifndef STUDYROOM_H
#define STUDYROOM_H
#include "type/room/Room.h"

#include <iostream>
using namespace std;

class StudyRoom : public Room
{
private:
    int table;
    int chair;
public:
    StudyRoom(int = 0, int = 0);
    ~StudyRoom();

    void setTable(int);
    void setChair(int);

    int getTable() const;
    int getChair() const;

    friend istream& operator>>(istream &in, StudyRoom &x);
    friend ostream& operator<<(ostream &out, const StudyRoom &x);

    virtual int Capacity() const;
};
#endif