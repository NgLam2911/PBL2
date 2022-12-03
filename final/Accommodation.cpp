#include "Accommodation.h"

#include <iostream>
#include <iomanip>
using namespace std;

Accommodation::Accommodation(int bed): bed(bed){}
Accommodation::~Accommodation(){}

void Accommodation::setBed(int bed)
{
    this->bed = bed;
}
void Accommodation::setListOfStudent(DoublyLinkedList<Student> ListOfStudent)
{
    this->ListOfStudent = ListOfStudent;
}

int Accommodation::getBed() const
{
    return this->bed;
}
DoublyLinkedList<Student>& Accommodation::getListOfStudent()
{
    return ListOfStudent;
}

istream &operator>>(istream &in, Accommodation &x)
{
    for (;;)
    {
        try
        {
            cout << "Enter Area's ID: "; in >> x.idArea;
            if (x.idArea > 9 || x.idArea < 1)
                throw invalid_argument("Area's ID is only from 1 to 9!");
        }
        catch(invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
    for (;;)
    {
        try
        {
            cout << "Enter Room's ID: "; in >> x.idRoom;
            if (x.idArea > 99 || x.idArea < 1)
                throw invalid_argument("Room's ID is only from 1 to 99!");
        }
        catch(invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
    for (;;)
    {
        try
        {
            cout << "Enter Number of beds: "; in >> x.bed;
            if (x.bed < 0)
                throw invalid_argument("Number of Beds must be greater than 0!");
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
ostream &operator<<(ostream &out, const Accommodation&x)
{
    out << "Room " << x.getID() << ":"<< endl;
    out << setw(17) << "Bed: " << x.bed;
    out << setw(17) << "Capicity: " << x.Capacity() << endl;
    for (int i = 0; i < x.ListOfStudent.getSize(); i++)
    {
        cout << x.ListOfStudent.get(i) << endl;
    }
    return out;
}

int Accommodation::Capacity() const
{
    return this->bed;
}