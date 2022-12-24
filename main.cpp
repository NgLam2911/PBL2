#include "type/student/StudentManager.h"
#include "type/accommodation/AccommodationManager.h"
#include "type/room/StudyRoomManager.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    for (;;) {
        cout << "       PBL2: DO AN CO SO LAP TRINH" << endl;
        cout << "       Giao vien huong dan: Dang Hoai Phuong" << endl;
        cout << "       Sinh Vien thuc hien: Nguyen Dinh Loc" << endl;
        cout << "                             Nguyen Duc Ngoc Lam" << endl;
        cout << endl;
        cout << "       DE TAI: QUAN LY KY TUC XA SINH VIEN" << endl;
        cout << "1. Add Student / Room." << endl;
        cout << "2. Delete Student / Room." << endl;
        cout << "3. Find Student / Room." << endl;
        cout << "4. Edit Student / Room." << endl;
        cout << "5. See list of Student / Room." << endl;
        cout << "0.Exit." << endl << endl;

        int choice1 = 0, choice2 = 0;
        cout << "Enter number of action: ";
        cin >> choice1;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Enter number of action: ";
            cin >> choice1;
        }
        if (choice1 == 0)
            break;
        switch (choice1) {
            case 1:
                system("cls");
                cout << "1. Add a student." << endl;
                cout << "2. Add a Accommodation." << endl;
                cout << "3. Add a StudyRoom." << endl << endl;

                cout << "Enter number of action: ";
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        try { StudentManager::addStudent(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        try { AccommodationManager::addAccommodation(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 3:
                        try { StudyRoomManager::addStudyRoom(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    default:
                        break;
                }
                break;

            case 2:
                system("cls");
                cout << "1. Delete a student." << endl;
                cout << "2. Delete a Accommodation." << endl;
                cout << "3. Delete a StudyRoom." << endl << endl;

                cout << "Enter number of action: ";
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        try { StudentManager::deleteStudent(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        try { AccommodationManager::deleteAccommodation(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 3:
                        try { StudyRoomManager::deleteStudyRoom(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    default:
                        break;
                }
                break;

            case 3:
                system("cls");
                cout << "1. Find a student." << endl;
                cout << "2. Find a Accommodation." << endl;
                cout << "3. Find a StudyRoom." << endl << endl;

                cout << "Enter number of action: ";
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        try { StudentManager::findStudent(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        try { AccommodationManager::findAccommodation(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 3:
                        try { StudyRoomManager::findStudyRoom(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    default:
                        break;
                }
                break;

            case 4:
                system("cls");
                cout << "1. Edit a student." << endl;
                cout << "2. Edit a Accommodation." << endl;
                cout << "3. Edit a StudyRoom." << endl << endl;

                cout << "Enter number of action: ";
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        try { StudentManager::updateStudent(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        try { AccommodationManager::updateAccommodation(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 3:
                        try { StudyRoomManager::updateStudyRoom(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    default:
                        break;
                }
                break;

            case 5:
                system("cls");
                cout << "1. See list of student." << endl;
                cout << "2. See list of Accommodation." << endl;
                cout << "3. See list of StudyRoom." << endl << endl;

                cout << "Enter number of action: ";
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        try { StudentManager::seeListStudent(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        try { AccommodationManager::seeListAccommodation(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    case 3:
                        try { StudyRoomManager::seeListStudyRoom(); }
                        catch (const invalid_argument &e) { cout << e.what() << endl; }
                        catch (const out_of_range &e) { cout << e.what() << endl; }
                        catch (const overflow_error &e) { cout << e.what() << endl; }
                        catch (const domain_error &e) { cout << e.what() << endl; }
                        catch (...) { cout << "Something wrong!" << endl; }
                        system("pause");
                        system("cls");
                        break;

                    default:
                        break;
                }
                break;

            default:
                cout << "Wrong action, please enter again!" << endl;
                system("pause");
                system("cls");
                break;
        }
    }
    return 0;
}