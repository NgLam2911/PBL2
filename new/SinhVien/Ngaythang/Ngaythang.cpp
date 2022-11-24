#pragma once
#include <iostream>
#include <string>
#include "Ngaythang.h"
using namespace std;
Ngaythang::Ngaythang(int ngay, int thang, int nam): ngay(ngay), thang(thang), nam(nam){}
Ngaythang::~Ngaythang(){}

void Ngaythang::setNgay(int ngay)
{
    this->ngay = ngay;
}
void Ngaythang::setThang(int thang)
{
    this->thang = thang;
}
void Ngaythang::setNam(int nam)
{
    this->nam = nam;
}

int Ngaythang::getNgay()
{
    return this->ngay;
}
int Ngaythang::getThang()
{
    return this->thang;
}
int Ngaythang::getNam()
{
    return this->nam;
}

istream& operator>>(istream &in, Ngaythang &x)
{
    cout << "Nhập ngày: "; in >> x.ngay;
    cout << "Nhập tháng: "; in >> x.thang;
    cout << "Nhập năm: "; in >> x.nam;
    return in;
}
ostream& operator<<(ostream &out, const Ngaythang &x)
{
    out << x.ngay << "/" << x.thang << "/" << x.nam << endl;
    return out;
}