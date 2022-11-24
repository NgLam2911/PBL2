#ifndef Set_h
#define Set_h
#include "..\SinhVien\SinhVien.cpp"
#include "..\Phong\PhongHoc.cpp"
// #include "..\Phong\PhongO.cpp"

class PhongO;

template <typename T>
class Set
{
private:
    T *head;
public:
    Set(T* = NULL);
    ~Set();

    void sapxep(Set &x);
    // void xoaLap(Set &x);

    int size() const;
    bool empty() const;
    void insert(T);
    void erase(int); // xóa theo iterator
    T* find(int) const; // tìm theo iterator
};
#endif