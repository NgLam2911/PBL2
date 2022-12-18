#include "StudyRoomManager.h"

#include <iostream>
#include "type/accommodation/Accommodation.h"
using namespace std;

void StudyRoomManager::addStudyRoom()
{
    DoublyLinkedList<StudyRoom> list;
    DataBaseManager::readFileStudyRoom(list);
    DoublyLinkedList<Accommodation> listAccommodation;
    DataBaseManager::readFileAccommodationAndStudent(listAccommodation);
    StudyRoom newRoom;
    cout << "Enter the informations of new Study Room: " << endl;
    cin >> newRoom;
    for (int i = 0; i < listAccommodation.getSize(); i++)
        if (listAccommodation.get(i).getID() == newRoom.getID())
            throw domain_error("This object is duplicated!");
    try
    {
        list.push_back(newRoom);
    }
    catch(const domain_error& e)
    {
        cout << e.what() << endl;        
    }
    list.sort(ascending);
    DataBaseManager::writeFileStudyRoom(list);
}

void StudyRoomManager::deleteStudyRoom()
{
    DoublyLinkedList<StudyRoom> list;
    DataBaseManager::readFileStudyRoom(list);
    int code;
    bool check = false;
    cout << "Enter the Study Room's ID you want to delete: "; cin >> code;
    for (int i = 0; i < list.getSize(); i++){
        if (list.get(i).getID() == code)
        {
            list.remove(i);
            check = true;
            break;
        }
    }
    if (!check)
        throw invalid_argument("This ID was not found!");
    DataBaseManager::writeFileStudyRoom(list);
}

void StudyRoomManager::findStudyRoom()
{
    DoublyLinkedList<StudyRoom> list;
    DataBaseManager::readFileStudyRoom(list);
    int code;
    bool check = false;
    cout << "Enter the Study Room's ID you want to find: "; cin >> code;
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

void StudyRoomManager::updateStudyRoom()
{
    DoublyLinkedList<StudyRoom> list;
    DataBaseManager::readFileStudyRoom(list);
    int code;
    cout << "Enter the ID of the Study Room you want to edit: "; cin >> code;
    bool check = false;
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list.get(i).getID() == code)
        {
            check = true;
            StudyRoom StudyRoomEdited;
            cout << "Enter the informations of the edited Study Room: " << endl;
            cin >> StudyRoomEdited;
            list.remove(i);
            try
            {
                list.insert(StudyRoomEdited, i);
            }
            catch(const domain_error& e)
            {
                cout << e.what() << endl;
            }
            catch(const out_of_range& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
    }
    if (!check)
        throw invalid_argument("This ID was not found!");
    list.sort(ascending);
    DataBaseManager::writeFileStudyRoom(list);
}

void StudyRoomManager::seeListStudyRoom()
{
    DoublyLinkedList<StudyRoom> list;
    DataBaseManager::readFileStudyRoom(list);
    if (list.getSize() == 0)
        throw out_of_range("There are no Study Room in the Database!");
    cout << "LIST STUDY ROOM:" << endl;
    for (int i = 0; i < list.getSize(); i++)
        cout << list.get(i);
}