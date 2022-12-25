cmake_minimum_required(VERSION 3.22)
project(PBL2)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(PBL2
        main.cpp
        utils/Date.h
        utils/Date.cpp
        utils/DoublyLinkedList.h
        database/DataBaseManager.h
        database/DataBaseManager.cpp
        type/room/accommodation/Accommodation.h
        type/room/accommodation/Accommodation.cpp
        type/room/accommodation/AccommodationManager.h
        type/room/accommodation/AccommodationManager.cpp
        type/room/Room.h
        type/room/Room.cpp
        type/room/studyroom/StudyRoom.h
        type/room/studyroom/StudyRoom.cpp
        type/room/studyroom/StudyRoomManager.h
        type/room/studyroom/StudyRoomManager.cpp
        type/student/Student.h
        type/student/Student.cpp
        type/student/StudentManager.h
        type/student/StudentManager.cpp
)
