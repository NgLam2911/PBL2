#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include "Student.h"
#include "type/accommodation/Accommodation.h"
#include "utils/DoublyLinkedList.h"
#include "database/DataBaseManager.h"

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