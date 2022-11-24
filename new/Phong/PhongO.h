#ifndef PhongO_h
#define PhongO_h
// #include "Phong.cpp"
// #include "..\SinhVien\SinhVien.cpp"
#include "..\CauTrucDuLieu\Set.cpp"
class PhongO : public Phong
{
private:
    int sogiuong;
    Set<SinhVien> DSSinhVien;
    PhongO *next;
public:
    PhongO(int = 0, PhongO* = NULL);
    ~PhongO();

    void setSogiuong(int);
    void setDSSinhVien(Set<SinhVien>);
    void setNext(PhongO*);

    int getSogiuong();
    Set<SinhVien>* getDSSinhVien();
    PhongO* getNext();

    friend istream& operator>>(istream &in, PhongO &x);
    friend ostream& operator<<(ostream &out, const PhongO &x);
    PhongO& operator=(const PhongO &x);
    friend void swap(PhongO &x, PhongO &y);

    virtual int SucChua() const;
};
#endif