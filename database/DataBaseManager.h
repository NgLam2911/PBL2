#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "utils/DoublyLinkedList.h"
#include "type/room/StudyRoom.h"
#include "type/student/Student.h"
#include "type/accommodation/Accommodation.h"

class DataBaseManager
{
private:
    static bool is_empty(ifstream& infile);
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