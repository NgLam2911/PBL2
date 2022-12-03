#include "Student.h"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Student::Student(){}
Student::~Student(){}

void Student::setID(int id)
{
    this->id = id;
}
void Student::setName(string name)
{
    this->name = name;
}
void Student::setBirth(Date birth)
{
    this->birth = birth;
}
void Student::setIdRoom(int idRoom)
{
    this->idRoom = idRoom;
}

int Student::getID() const
{
    return this->id;
}
string Student::getName() const
{
    return this->name;
}
Date Student::getBirth() const
{
    return this->birth;
}
int Student::getIdRoom() const
{
    return this->idRoom;
}

istream &operator>>(istream &in, Student &x)
{
    for (;;)
    {
        try
        {
            cout << "Enter Student's ID: "; in >> x.id;
            if (x.id < 1000)
                throw invalid_argument("Student's ID must be greater than or equal to 10000!");
        }
        catch(invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
    cout << "Enter Student's Name: "; in.ignore(); getline(in, x.name);
    cout << "Enter Student's Birthday: " << endl; in >> x.birth;
    for (;;)
    {
        try
        {
            cout << "Enter the Registered Room's ID: "; in >> x.idRoom;
            if (x.idRoom > 1000 || x.idRoom < 0)
                throw invalid_argument("Student's ID must be greater than 0 and less than 10000!");
        }
        catch(invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
    return in;
}
ostream &operator<<(ostream &out, const Student &x)
{
    out << setw(5) << x.idRoom << setw(15) << x.id << setw(30) << x.name << setw(10) << x.birth;
    return out;
}