#ifndef ListStudent_h
#define ListStudent_h
#include "Student.h"

class ListStudent
{
private:
    Student *head;
public:
    ListStudent();
    ~ListStudent();
    void insertStudent();
    void editStudent(int index);
    void deleteStudent(int index);
    Student findStudent(int studentID);
};

#endif