#include "AccommodationManager.h"

#include <iostream>
using namespace std;

void AccommodationManager::addAccommodation()
{
    DoublyLinkedList<Accommodation> list;
    DataBaseManager::readFileAccommodationAndStudent(list);
    Accommodation newRoom;
    cout << "Enter the informations of new Accommodation Room: " << endl;
    cin >> newRoom;
    list.push_back(newRoom);
    list.sort(ascending);
    DataBaseManager::writeFileAccommodationAndStudent(list);
}

void AccommodationManager::deleteAccommodation()
{
    DoublyLinkedList<Accommodation> list;
    DataBaseManager::readFileAccommodationAndStudent(list);
    int code;
    bool check1, check2 = 0;
    cout << "Enter the Accommodation Room's ID you want to delete: "; cin >> code;
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list.get(i).getID() == code)
        {
            if (list.get(i).getListOfStudent().getSize() != 0)
            {
                cout << "If you delete this room, some students will also be deleted!" << endl;
                cout << "Do you want to continue? (Yes - 1 / No - 0): ";
                cin >> check1;
                if (!check1)
                    break;
            }
            list.remove(i);
            check2 = 1;
            break;
        }
    }
    if (!check2)
        throw invalid_argument("This ID was not found!");
    DataBaseManager::writeFileAccommodationAndStudent(list);
}

void AccommodationManager::findAccommodation()
{
    DoublyLinkedList<Accommodation> list;
    DataBaseManager::readFileAccommodationAndStudent(list);
    int code;
    bool check;
    cout << "Enter the Study Room's ID you want to find: "; cin >> code;
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list.get(i).getID() == code)
        {
            cout << list.get(i);
            check = 1;
            break;
        }
    }
    if (!check)
        throw invalid_argument("This ID was not found!");
}

void AccommodationManager::updateAccommodation()
{
    DoublyLinkedList<Accommodation> list;
    DataBaseManager::readFileAccommodationAndStudent(list);
    int code;
    cout << "Enter the ID of the Accommodation you want to edit: "; cin >> code;
    bool check1, check2 = 0;
    for (int i = 0; i < list.getSize(); i++)
    {
        if (list.get(i).getID() == code)
        {
            if (list.get(i).getListOfStudent().getSize() != 0)
            {
                cout << "If you edit this room, some students will also be deleted!" << endl;
                cout << "Do you want to continue? (Yes - 1 / No - 0): ";
                cin >> check1;
                if (!check1)
                    break;
            }
            Accommodation AccommodationEdited;
            cout << "Enter the informations of the edited Accommodation: " << endl;
            cin >> AccommodationEdited;
            check2 = 1;
            list.remove(i); 
            list.insert(AccommodationEdited, i);
            break;
        }
    }
    if (!check2)
        throw invalid_argument("This ID was not found!");
    list.sort(ascending);
    DataBaseManager::writeFileAccommodationAndStudent(list);
}

void AccommodationManager::seeListAccommodation()
{
    DoublyLinkedList<Accommodation> list;
    DataBaseManager::readFileAccommodationAndStudent(list);
    if (list.getSize() == 0)
        throw out_of_range("There are no Accommodation in the Database!");
    cout << "LIST ACCOMMODATION:" << endl;
    for (int i = 0; i < list.getSize(); i++)
        cout << list.get(i);
}