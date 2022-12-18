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
        type/accommodation/Accommodation.h
        type/accommodation/Accommodation.cpp
        type/accommodation/AccommodationManager.h
        type/accommodation/AccommodationManager.cpp
        type/room/Room.h
        type/room/Room.cpp
        type/room/StudyRoom.h
        type/room/StudyRoom.cpp
        type/room/StudyRoomManager.h
        type/room/StudyRoomManager.cpp
        type/student/Student.h
        type/student/Student.cpp
        type/student/StudentManager.h
        type/student/StudentManager.cpp
)
