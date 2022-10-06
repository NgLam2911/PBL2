#include <iostream>

class Student{};
class Room{};

/*
class Acquaintance{};

struct acquaintanceList
{
    int information;
    acquaintanceList *next;
};
*/

struct studentList
{
    int information;
    //acquaintanceList acquaintance;
    studentList *next;
};

struct roomList
{
    int information;
    studentList student;
    roomList *next;
};

struct dormitory
{
    int information;
    roomList room;
};