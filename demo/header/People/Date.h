#ifndef Date_h
#define Date_h
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
    ~Date();
    friend istream &operator>>(istream &in, Date &x);
    friend ostream &operator<<(ostream &out, Date&x);
    Date addDay(int x);
};

#endif