#include "StudyRoom.h"

#include <iostream>
#include <iomanip>
using namespace std;

StudyRoom::StudyRoom(int table, int chair): table(table), chair(chair){}
StudyRoom::~StudyRoom(){}

void StudyRoom::setTable(int table)
{
    this->table = table;
}
void StudyRoom::setChair(int chair)
{
    this->chair = chair;
}

int StudyRoom::getTable() const
{
    return this->table;
}
int StudyRoom::getChair() const
{
    return this->chair;
}

istream &operator>>(istream& in, StudyRoom &x)
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
            cout << "Enter Number of Tables: "; in >> x.table;
            if (x.table < 0)
                throw invalid_argument("Number of Tables must be greater than 0!");
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
            cout << "Enter Number of Chairs: "; in >> x.chair;
            if (x.chair < 0)
                throw invalid_argument("Number of Chairs must be greater than 0!");
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
ostream &operator<<(ostream& out, const StudyRoom &x)
{
    out << "Room " << x.getID() << ":"<< endl;
    out << setw(17) << "Tables: " << x.table;
    out << setw(15) << "Chairs: " << x.chair;
    out << setw(17) << "Capacity: " << x.Capacity() << endl;
    return out;
}

int StudyRoom::Capacity() const
{
    return this->chair;
}