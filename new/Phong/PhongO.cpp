#include <iostream>
#include <iomanip>
#include "PhongO.h"
using namespace std;
PhongO::PhongO(int sogiuong, PhongO *next): sogiuong(sogiuong), next(next){}
PhongO::~PhongO(){}

void PhongO::setSogiuong(int sogiuong)
{
    this->sogiuong = sogiuong;
}
void PhongO::setDSSinhVien(Set<SinhVien> dsSV)
{
    this->DSSinhVien = dsSV;
}
void PhongO::setNext(PhongO *next)
{
    this->next = next;
}

int PhongO::getSogiuong()
{
    return this->sogiuong;
}
Set<SinhVien>* PhongO::getDSSinhVien()
{
    return &DSSinhVien;
}
PhongO* PhongO::getNext()
{
    return this->next;
}

istream &operator>>(istream &in, PhongO &x)
{
    cout << "Nhập mã khu: "; in >> x.makhu;
    cout << "Nhập số phòng: "; in >> x.sophong;
    cout << "Nhập số lượng giường: "; in >> x.sogiuong;
    return in;
}
ostream &operator<<(ostream &out, const PhongO&x)
{
    out << "Phòng " << x.getID() << ":"<< endl;
    out << setw(17) << "Số giường: " << x.sogiuong;
    out << setw(17) << "Sức chứa: " << x.SucChua() << endl;
    for (int i = 0; i < x.DSSinhVien.size(); i++)
    {
        cout << *(x.DSSinhVien.find(i)) << endl;
    }
    return out;
}
PhongO& PhongO::operator=(const PhongO& x)
{
    this->makhu = x.makhu;
    this->sophong = x.sophong;
    this->sogiuong = x.sogiuong;
    this->DSSinhVien = x. DSSinhVien;
    return *this;
}

void swap(PhongO &x, PhongO&y)
{
    PhongO temp = x;
    x = y;
    y = temp;
}

int PhongO::SucChua() const
{
    return this->sogiuong;
}