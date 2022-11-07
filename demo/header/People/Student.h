#ifndef Student_h
#define Student_h
#include <iostream>
#include "People.h"
#include "ListAcquaintance.h"

using namespace std;

class Student : public People
{
private:
    int studentID;
    string classname;
    string roomID;
    Date expirationDay;
    ListAcquaintance listAcqua;
    Student *next;
public:
    Student();
    ~Student();
    friend istream &operator>>(istream &in, Student &x);
    friend ostream &operator<<(ostream &out, Student &x);
};

#endif