#include "Accommodation.h"

#include <iostream>
#include <iomanip>
using namespace std;

Accommodation::Accommodation(int bed): bed(bed){}
Accommodation::~Accommodation()= default;

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
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter Area's ID: ";
                cin >> x.idArea;
            }
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
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter Room's ID: ";
                cin >> x.idRoom;
            }
            if (x.idRoom > 99 || x.idRoom < 1)
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
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter Number of beds: ";
                cin >> x.bed;
            }
            if (x.bed < 0 || x.bed > 8)
                throw invalid_argument("Number of Beds is only from 1 to 8!");
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

Accommodation& Accommodation::operator=(const Accommodation& x)
{
    this->bed = x.bed;
    this->idArea = x.idArea;
    this->idRoom = x.idRoom;
    this->ListOfStudent.clear();
    for (int i = 0; i < x.ListOfStudent.getSize(); i++)
    {
        this->ListOfStudent.push_back(x.ListOfStudent.get(i));
    }
    return *this;
}

int Accommodation::Capacity() const
{
    return this->bed - this->ListOfStudent.getSize();
}