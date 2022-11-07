#ifndef ListAccommodation_h
#define ListAccommodation_h
#include "Accommodation.h"

class ListAccommodation
{
private:
    Accommodation *head;
public:
    ListAccommodation(/* args */);
    ~ListAccommodation();
    void insertAccommodation();
    void editAccommodation(int index);
    void deleteAccommodation(int index);
    Accommodation findAccommodation(string roomID);
};

#endif