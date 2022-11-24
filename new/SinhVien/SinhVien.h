#ifndef SinhVien_h
#define SinhVien_h
#include <iostream>
using namespace std;
#include ".\Ngaythang\Ngaythang.cpp"
class SinhVien
{
private:
    int id;
    string hoten;
    Ngaythang ngaysinh;
    int maphong;
    SinhVien *next;
public:
    SinhVien(int = 0, string = "NULL", int = 0, SinhVien* = NULL);
    ~SinhVien();

    void setID(int);
    void setHoten(string);
    void setNgaysinh(Ngaythang);
    void setMaphong(int);
    void setNext(SinhVien*);

    int getID();
    string getHoten();
    Ngaythang getNgaysinh();
    int getMaphong();
    SinhVien* getNext();

    friend istream& operator>>(istream &in, SinhVien &x);
    friend ostream& operator<<(ostream &out, const SinhVien &x);
    SinhVien& operator=(const SinhVien &x);
    friend void swap(SinhVien &x, SinhVien &y);
};
#endif