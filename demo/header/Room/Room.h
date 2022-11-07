#ifndef Room_h
#define Room_h
#include <iostream>
#include <string>

using namespace std;

class Room
{
protected:
    string roomID;
    bool status;
public:
    Room();
    ~Room();
};

#endif