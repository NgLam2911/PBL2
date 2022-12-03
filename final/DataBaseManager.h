#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "DoublyLinkedList.h"
#include "StudyRoom.h"
#include "Student.h"
#include "Accommodation.h"

class DataBaseManager
{
public:
    static void readFileStudyRoom(DoublyLinkedList<StudyRoom>&);
    static void readFileStudent(DoublyLinkedList<Student>&);
    static void readFileAccommodationAndStudent(DoublyLinkedList<Accommodation>&);
    // static void readAllFile(DoublyLinkedList<StudyRoom>&, DoublyLinkedList<Accommodation>&, DoublyLinkedList<Student>&);

    static void writeFileStudyRoom(DoublyLinkedList<StudyRoom>&);
    static void writeFileStudent(DoublyLinkedList<Student>&);
    static void writeFileAccommodationAndStudent(DoublyLinkedList<Accommodation>&);
    // static void writeAllFile(DoublyLinkedList<StudyRoom>&, DoublyLinkedList<Accommodation>&, DoublyLinkedList<Student>&);
};

#endif