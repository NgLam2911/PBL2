#ifndef ROOM_H
#define ROOM_H

class Room
{
protected:
    int idArea;
    int idRoom;
public:
    Room(int = 0, int = 0);
    ~Room();

    void setIdArea(int);
    void setIdRoom(int);

    int getIdArea() const;
    int getIdRoom() const;

    int getID() const;
    virtual int Capacity() const = 0;
};

#endif