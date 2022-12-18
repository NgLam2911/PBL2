#ifndef ACCOMMODATIONMANAGER_H
#define ACCOMMODATIONMANAGER_H
#include "Accommodation.h"
#include "utils/DoublyLinkedList.h"
#include "database/DataBaseManager.h"

class AccommodationManager
{
public:
    static void addAccommodation();
    static void deleteAccommodation();
    static void findAccommodation();
    static void updateAccommodation();
    static void seeListAccommodation();
};

#endif