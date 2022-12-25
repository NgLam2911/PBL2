#include "DataBaseManager.h"

#include <fstream>

using namespace std;

const string DataBaseManager::STUDENT_FILE = "saves/Student.txt";
const string DataBaseManager::STUDYROOM_FILE = "saves/StudyRoom.txt";
const string DataBaseManager::ACCOMMODATION_FILE = "saves/Accommodation.txt";

bool DataBaseManager::is_empty(ifstream &infile) {
    return infile.peek() == ifstream::traits_type::eof();
}

void DataBaseManager::readFileStudyRoom(DoublyLinkedList<StudyRoom> &list) {
    ifstream infile;
    infile.open(DataBaseManager::STUDYROOM_FILE);
    if (is_empty(infile)) {
        infile.close();
        return;
    }
    string f;
    while (!infile.eof()) {
        StudyRoom a;
        infile >> f;
        a.setIdArea(stoi(f, nullptr, 10) / 100);
        a.setIdRoom(stoi(f, nullptr, 10) % 100);
        infile >> f;
        a.setTable(stoi(f, nullptr, 10));
        infile >> f;
        a.setChair(stoi(f, nullptr, 10));
        list.push_back(a);
    }
    infile.close();
}

void DataBaseManager::readFileStudent(DoublyLinkedList<Student> &list) {
    ifstream infile;
    infile.open(DataBaseManager::STUDENT_FILE);
    if (is_empty(infile)) {
        infile.close();
        return;
    }
    string f;
    int d, m, y;
    while (!infile.eof()) {
        char temp[50];
        Student a;
        infile >> f;
        a.setIdRoom(stoi(f, nullptr, 10));
        infile >> f;
        a.setID(stoi(f, nullptr, 10));
        infile >> d;
        infile >> m;
        infile >> y;
        Date ngay(d, m, y);
        a.setBirth(ngay);
        infile.ignore(1, ' ');
        infile.getline(temp, 50);
        f = temp;
        a.setName(f);
        list.push_back(a);
    }
    infile.close();
}

void DataBaseManager::readFileAccommodationAndStudent(DoublyLinkedList<Accommodation> &list) {
    ifstream infile;
    infile.open(DataBaseManager::ACCOMMODATION_FILE);
    if (is_empty(infile)) {
        infile.close();
        return;
    }
    string f;
    while (!infile.eof()) {
        Accommodation a;
        infile >> f;
        a.setIdArea(stoi(f, nullptr, 10) / 100);
        a.setIdRoom(stoi(f, nullptr, 10) % 100);
        infile >> f;
        a.setBed(stoi(f, nullptr, 10));
        list.push_back(a);
    }
    infile.close();
    DoublyLinkedList<Student> listStudent;
    DataBaseManager::readFileStudent(listStudent);
    for (int i = 0; i < list.getSize(); i++)
        for (int j = 0; j < listStudent.getSize(); j++)
            if (list.get(i).getID() == listStudent.get(j).getIdRoom())
                list.get(i).getListOfStudent().push_back(listStudent.get(j));
}

void DataBaseManager::writeFileStudyRoom(DoublyLinkedList<StudyRoom> &list) {
    ofstream outfile(DataBaseManager::STUDYROOM_FILE);
    if (outfile.fail())
        throw overflow_error("Can't open file at StudyRoom.txt!");
    for (int i = 0; i < list.getSize(); i++) {
        if (i == list.getSize() - 1)
            outfile << list.get(i).getID() << " " << list.get(i).getTable() << " " << list.get(i).getChair();
        else
            outfile << list.get(i).getID() << " " << list.get(i).getTable() << " " << list.get(i).getChair() << endl;
    }
    outfile.close();
}

void DataBaseManager::writeFileStudent(DoublyLinkedList<Student> &list) {
    ofstream outfile(DataBaseManager::STUDENT_FILE);
    if (outfile.fail())
        throw overflow_error("Can't open file at Student.txt!");
    for (int i = 0; i < list.getSize(); i++) {
        outfile << list.get(i).getIdRoom() << " " << list.get(i).getID() << " ";
        outfile << list.get(i).getBirth().getDay() << " ";
        outfile << list.get(i).getBirth().getMonth() << " ";
        outfile << list.get(i).getBirth().getYear() << " ";
        if (i == list.getSize() - 1)
            outfile << list.get(i).getName();
        else
            outfile << list.get(i).getName() << endl;
    }
    outfile.close();
}

void DataBaseManager::writeFileAccommodationAndStudent(DoublyLinkedList<Accommodation> &list) {
    ofstream outfile1(DataBaseManager::ACCOMMODATION_FILE);
    ofstream outfile2(DataBaseManager::STUDENT_FILE);
    if (outfile1.fail() || outfile2.fail())
        throw overflow_error("Can't open file at Accommodation.txt or Student.txt!");
    for (int i = 0; i < list.getSize(); i++) {
        if (i == list.getSize() - 1)
            outfile1 << list.get(i).getID() << " " << list.get(i).getBed();
        else
            outfile1 << list.get(i).getID() << " " << list.get(i).getBed() << endl;
        for (int j = 0; j < list.get(i).getListOfStudent().getSize(); j++) {
            outfile2 << list.get(i).getListOfStudent().get(j).getIdRoom() << " ";
            outfile2 << list.get(i).getListOfStudent().get(j).getID() << " ";
            outfile2 << list.get(i).getListOfStudent().get(j).getBirth().getDay() << " ";
            outfile2 << list.get(i).getListOfStudent().get(j).getBirth().getMonth() << " ";
            outfile2 << list.get(i).getListOfStudent().get(j).getBirth().getYear() << " ";
            if (j == list.get(i).getListOfStudent().getSize() - 1)
                outfile2 << list.get(i).getListOfStudent().get(j).getName();
            else
                outfile2 << list.get(i).getListOfStudent().get(j).getName() << endl;
        }
    }
    outfile2.close();
    outfile1.close();
}

