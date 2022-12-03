#include "Room.h"

Room::Room(int idArea, int idRoom): idArea(idArea), idRoom(idRoom){}
Room::~Room(){}

void Room::setIdArea(int idArea)
{
    this->idArea = idArea;
}
void Room::setIdRoom(int idRoom)
{
    this->idRoom = idRoom;
}

int Room::getIdArea() const
{
    return idArea;
}
int Room::getIdRoom() const
{
    return idRoom;
}

int Room::getID() const
{
    return this->idArea*100 + this->idRoom;
}