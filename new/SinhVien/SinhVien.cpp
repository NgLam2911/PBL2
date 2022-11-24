#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "SinhVien.h"
using namespace std;
SinhVien::SinhVien(int mssv, string hoten, int maphong, SinhVien* next): id(mssv), hoten(hoten), next(next)
{
    this->maphong = maphong;
}
SinhVien::~SinhVien(){}

void SinhVien::setID(int id)
{
    this->id = id;
}
void SinhVien::setHoten(string ten)
{
    this->hoten = ten;
}
void SinhVien::setNgaysinh(Ngaythang ngay)
{
    this->ngaysinh = ngay;
}
void SinhVien::setMaphong(int maphong)
{
    this->maphong = maphong;
}
void SinhVien::setNext(SinhVien* next)
{
    this->next = next;
}

int SinhVien::getID()
{
    return this->id;
}
string SinhVien::getHoten()
{
    return this->hoten;
}
Ngaythang SinhVien::getNgaysinh()
{
    return this->ngaysinh;
}
int SinhVien::getMaphong()
{
    return this->maphong;
}
SinhVien* SinhVien::getNext()
{
    return this->next;
}

istream &operator>>(istream &in, SinhVien &x)
{
    cout << "Nhập mã số sinh viên: "; in >> x.id;
    cout << "Nhập họ tên sinh viên: "; in.ignore(); getline(in, x.hoten);
    cout << "Nhập ngày sinh: " << endl; in >> x.ngaysinh;
    cout << "Nhập phòng sinh viên đăng ký: "; in >> x.maphong; 
    return in;
}
ostream &operator<<(ostream &out, const SinhVien &x)
{
    out << setw(5) << x.maphong << setw(15) << x.id << setw(30) << x.hoten << setw(10) << x.ngaysinh;
    return out;
}
SinhVien& SinhVien::operator=(const SinhVien &x)
{
    this->id = x.id;
    this->hoten = x.hoten;
    this->maphong = x.maphong;
    this->ngaysinh = x.ngaysinh;
    return *this;
}
void swap(SinhVien& x, SinhVien &y)
{
    SinhVien temp = x;
    x = y;
    y = temp;
}