#ifndef Phong_h
#define Phong_h
class Phong
{
protected:
    int makhu;
    int sophong;
public:
    Phong(int = 0, int = 0);
    ~Phong();

    void setMakhu(int);
    void setSophong(int);

    int getMakhu();
    int getSophong();

    int getID() const;
    virtual int SucChua() const = 0;
};
#endif