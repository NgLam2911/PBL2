#ifndef ACCOMMODATION_H
#define ACCOMMODATION_H
#include "Room.h"
#include "Student.h"
#include "DoublyLinkedList.h"

class Accommodation : public Room
{
private:
    int bed;
    DoublyLinkedList<Student> ListOfStudent;
public:
    Accommodation(int = 0);
    ~Accommodation();

    void setBed(int);
    void setListOfStudent(DoublyLinkedList<Student>);

    int getBed() const;
    DoublyLinkedList<Student>& getListOfStudent();

    friend istream& operator>>(istream &in, Accommodation &x);
    friend ostream& operator<<(ostream &out, const Accommodation &x);

    virtual int Capacity() const;
};

#endif