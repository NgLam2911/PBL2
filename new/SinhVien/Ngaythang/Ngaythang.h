#ifndef Ngaythang_h
#define Ngaythang_h
// #include <iostream>
// #include <string>
using namespace std;
class Ngaythang
{
private:
    int ngay;
    int thang;
    int nam;
public:
    Ngaythang(int = 0, int = 0, int = 0);
    ~Ngaythang();

    void setNgay(int);
    void setThang(int);
    void setNam(int);

    int getNgay();
    int getThang();
    int getNam();

    friend istream& operator>>(istream &in, Ngaythang &x);
    friend ostream& operator<<(ostream &out, const Ngaythang &x);
};
#endif