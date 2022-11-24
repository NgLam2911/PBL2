#include "Phong.h"
Phong::Phong(int makhu, int sophong): makhu(makhu), sophong(sophong){}
Phong::~Phong(){}

void Phong::setMakhu(int makhu)
{
    this->makhu = makhu;
}
void Phong::setSophong(int sophong)
{
    this->sophong = sophong;
}

int Phong::getMakhu()
{
    return makhu;
}
int Phong::getSophong()
{
    return sophong;
}

int Phong::getID() const
{
    return this->makhu*100 + this->sophong;
}