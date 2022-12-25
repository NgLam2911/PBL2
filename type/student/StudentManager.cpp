#include "StudentManager.h"

#include <iostream>
using namespace std;

void StudentManager::addStudent()
{
    DoublyLinkedList<Accommodation> listAccommodation;
    DataBaseManager::readFileAccommodationAndStudent(listAccommodation);
    Student newStudent;
    cout << "Enter the informations of new Student: " << endl;
    cin >> newStudent;
    for (int i = 0; i < listAccommodation.getSize(); i++)
        if (listAccommodation.get(i).getID() == newStudent.getIdRoom())
        {
            if (listAccommodation.get(i).Capacity() == 0)
                throw out_of_range("This room is full!");
            DoublyLinkedList<Student> listStudent;
            DataBaseManager::readFileStudent(listStudent);
            listStudent.push_back(newStudent);
            listStudent.sort(ascending);
            DataBaseManager::writeFileStudent(listStudent);
            return;
        }
    cout << "There is no suitable accommodation for this student!" << endl;
    cout << "Please create this new room first!" << endl;
}

void StudentManager::deleteStudent()
{
    DoublyLinkedList<Student> list;
    DataBaseManager::readFileStudent(list);
    int code;
    bool check = false;
    cout << "Enter the Student's ID you want to delete: "; cin >> code;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter the Student's ID you want to delete: ";
        cin >> code;
    }
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list.get(i).getID() == code)
        {
            list.remove(i);
            check = true;
            break;
        }
    }
    if (!check)
        throw invalid_argument("This ID was not found!");
    DataBaseManager::writeFileStudent(list);
}

void StudentManager::findStudent()
{
    DoublyLinkedList<Student> list;
    DataBaseManager::readFileStudent(list);
    int code;
    bool check = false;
    cout << "Enter the Student's ID you want to find: "; cin >> code;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter the Student's ID you want to find: ";
        cin >> code;
    }
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list.get(i).getID() == code)
        {
            cout << list.get(i);
            check = true;
            break;
        }
    }
    if (!check)
        throw invalid_argument("This ID was not found!");
}

void StudentManager::updateStudent()
{
    DoublyLinkedList<Student> list;
    DataBaseManager::readFileStudent(list);
    int code;
    bool check = false;
    cout << "Enter the Student's ID you want to edit: "; cin >> code;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter the Student's ID you want to edit: ";
        cin >> code;
    }
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list.get(i).getID() == code)
        {
            list.remove(i);
            check = true;
            break;
        }
    }
    if (!check)
        throw invalid_argument("This ID was not found!");
    DataBaseManager::writeFileStudent(list);
    StudentManager::addStudent();
}

void StudentManager::seeListStudent()
{
    DoublyLinkedList<Student> list;
    DataBaseManager::readFileStudent(list);
    if (list.getSize() == 0)
        throw out_of_range("There are no Student in the Database!");
    cout << "LIST STUDENT:" << endl;
    for (int i = 0; i < list.getSize(); i++)
        cout << list.get(i);
}