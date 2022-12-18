#include "Date.h"

#include <iostream>
#include <string>
using namespace std;

Date::Date(int day, int month, int year): day(day), month(month), year(year){}
Date::~Date()= default;

void Date::setDay(int Day)
{
    this->day = Day;
}
void Date::setMonth(int Month)
{
    this->month = Month;
}
void Date::setYear(int Year)
{
    this->year = Year;
}

int Date::getDay() const
{
    return this->day;
}
int Date::getMonth() const
{
    return this->month;
}
int Date::getYear() const
{
    return this->year;
}

istream& operator>>(istream &in, Date &x)
{
    for (;;)
    {
        try
        {
            cout << "Enter Day: ";
            in >> x.day;
            if (x.day < 1 || x.day > 31)
                throw invalid_argument("Day can't be less than 1 or greater than 31!");
        }
        catch (invalid_argument& e)
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
            cout << "Enter Month: "; in >> x.month;
            if (x.month < 1 || x.month > 12)
                throw invalid_argument("Month only from 1 to 12!");
            if (x.day == 30 && x.month == 2)
                throw invalid_argument("Can't be February!");
            if(x.day == 31 && (x.month == 2 || x.month == 4 || x.month == 6 || x.month == 9 || x.month == 11))
                throw invalid_argument("Can't be February, April, June, September, November!");
        }
        catch (invalid_argument& e)
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
            cout << "Enter Year: "; in >> x.year;
            if (x.day == 29 && x.month == 2 && (x.year % 4 != 0 || (x.year % 100 == 0 && x.year % 400 != 0)))
                throw invalid_argument("Not a leap year!");
        }
        catch (invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
    return in;
}
ostream& operator<<(ostream &out, const Date &x)
{
    out << x.day << "/" << x.month << "/" << x.year << endl;
    return out;
}