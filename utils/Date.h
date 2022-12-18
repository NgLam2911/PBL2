#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int = 0, int = 0, int = 0);
    virtual ~Date();

    void setDay(int);
    void setMonth(int);
    void setYear(int);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    friend istream& operator>>(istream &in, Date &x);
    friend ostream& operator<<(ostream &out, const Date &x);
};

#endif