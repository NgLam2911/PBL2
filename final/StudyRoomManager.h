#ifndef STUDYROOMMANAGER_H
#define STUDYROOMMANAGER_H
#include "StudyRoom.h"
#include "DoublyLinkedList.h"
#include "DataBaseManager.h"

class StudyRoomManager
{
public:
    static void addStudyRoom();
    static void deleteStudyRoom();
    static void findStudyRoom();
    static void updateStudyRoom();
    static void seeListStudyRoom();
};

#endif