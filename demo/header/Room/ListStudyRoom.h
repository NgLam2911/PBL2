#ifndef ListStudyRoom_h
#define ListStudyRoom_h
#include "StudyRoom.h"

class ListStudyRoom
{
private:
    StudyRoom *head;
public:
    ListStudyRoom();
    ~ListStudyRoom();
    void insertStudyRoom();
    void editStudyRoom(int index);
    void deleteStudyRoom(int index);
    StudyRoom findStudyRoom(string roomID);
};

#endif