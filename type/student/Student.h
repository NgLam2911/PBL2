#ifndef STUDENT_H
#define STUDENT_H

#include "utils/Date.h"

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    Date birth;
    int idRoom;
public:
    Student();

    virtual ~Student();

    void setID(int);

    void setName(string);

    void setBirth(Date);

    void setIdRoom(int);

    int getID() const;

    string getName() const;

    Date getBirth() const;

    int getIdRoom() const;

    friend istream &operator>>(istream &in, Student &x);

    friend ostream &operator<<(ostream &out, const Student &x);
};

#endif