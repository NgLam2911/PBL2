#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include "Student.h"
#include "Accommodation.h"
#include "DoublyLinkedList.h"
#include "DataBaseManager.h"

class StudentManager
{
public:
    static void addStudent();
    static void deleteStudent();
    static void findStudent();
    static void updateStudent();
    static void seeListStudent();
};

#endif