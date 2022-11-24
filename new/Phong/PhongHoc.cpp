#include <iostream>
#include <iomanip>
#include "PhongHoc.h"
using namespace std;
PhongHoc::PhongHoc(int soban, int soghe, PhongHoc* next): soban(soban), soghe(soghe), next(NULL){}
PhongHoc::~PhongHoc(){}

void PhongHoc::setBan(int soban)
{
    this->soban = soban;
}
void PhongHoc::setGhe(int soghe)
{
    this->soghe = soghe;
}
void PhongHoc::setNext(PhongHoc *next)
{
    this->next = next;
}

int PhongHoc::getBan()
{
    return this->soban;
}
int PhongHoc::getGhe()
{
    return this->soghe;
}
PhongHoc* PhongHoc::getNext()
{
    return this->next;
}

istream &operator>>(istream& in, PhongHoc &x)
{
    cout << "Nhập mã khu: "; in >> x.makhu;
    cout << "Nhập số phòng: "; in >> x.sophong;
    cout << "Nhập số lượng bàn: "; in >> x.soban;
    cout << "Nhập số lượng ghế: "; in >> x.soghe;
    return in;
}
ostream &operator<<(ostream& out, const PhongHoc &x)
{
    out << "Phòng " << x.getID() << ":"<< endl;
    out << setw(17) << "Số bàn: " << x.soban;
    out << setw(15) << "Số ghế: " << x.soghe;
    out << setw(17) << "Sức chứa: " << x.SucChua();
    return out;
}
PhongHoc& PhongHoc::operator=(const PhongHoc &x)
{
    this->makhu = x.makhu;
    this->sophong =x.sophong;
    this->soban = x.soban;
    this->soghe = x.soghe;
    return *this;
}
void swap(PhongHoc &x, PhongHoc &y)
{
    PhongHoc temp = x;
    x = y;
    y = temp;
}

int PhongHoc::SucChua() const
{
    return this->soghe;
}