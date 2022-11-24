#ifndef PhongHoc_h
#define PhongHoc_h
#include <iostream>
#include "Phong.cpp"
using namespace std;
class PhongHoc : public Phong
{
private:
    int soban;
    int soghe;
    PhongHoc *next;
public:
    PhongHoc(int = 0, int = 0, PhongHoc* = NULL);
    ~PhongHoc();

    void setBan(int);
    void setGhe(int);
    void setNext(PhongHoc*);

    int getBan();
    int getGhe();
    PhongHoc* getNext();

    friend istream& operator>>(istream &in, PhongHoc &x);
    friend ostream& operator<<(ostream &out, const PhongHoc &x);
    PhongHoc& operator=(const PhongHoc &x);
    friend void swap(PhongHoc &x, PhongHoc &y);

    virtual int SucChua() const;
};
#endif