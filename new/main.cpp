#include <iostream>
#include <string>
// #include ".\CauTrucDuLieu\Set.cpp"
#include ".\Phong\PhongO.cpp"

using namespace std;

int main()
{
    Set<PhongHoc> dsphonghoc;
    Set<PhongO> dsphongo;
    PhongHoc ph;
    PhongO po;
    SinhVien sv;
    int id;
    for (;;)
    {
        cout << "1.  Thêm một phòng học." << endl;
        cout << "2.  Thêm một phòng ở." << endl;
        cout << "3.  Thêm một sinh viên." << endl;
        cout << "4.  Tìm một phòng học." << endl;
        cout << "5.  Tìm một phòng ở." << endl;
        cout << "6.  Tìm một sinh viên." << endl;
        cout << "7.  Xóa một phòng học." << endl;
        cout << "8.  Xóa một phòng ở." << endl;
        cout << "9.  Xóa một sinh viên." << endl;
        cout << "10. Cập nhật một phòng học." << endl;
        cout << "11. Cập nhật một phòng ở." << endl;
        cout << "12. Cập nhật một sinh viên." << endl;
        cout << "13. Xem danh sách phòng học." << endl;
        cout << "14. Xem danh sách phòng ở." << endl;
        cout << "15. Xem danh sách sinh viên." << endl;
        int choice = 0;
        cin >> choice;
        bool check = 1;
        switch (choice)
        {
        case 1:
            cin >> ph;
            dsphonghoc.insert(ph);
            break;
        case 2:
            cin >> po;
            dsphongo.insert(po);
            break;
        case 3:
            cin >> sv;
            for (int i = 0; i < dsphongo.size(); i++)
            {
                if (dsphongo.find(i)->getID() == sv.getMaphong())
                {
                    if (dsphongo.find(i)->getDSSinhVien()->size() == dsphongo.find(i)->getSogiuong())
                    {
                        cout << "Phòng này đã đầy!" << endl;
                        check = 0;
                    }
                    else
                    {
                        dsphongo.find(i)->getDSSinhVien()->insert(sv); 
                        check = 0;
                    }
                }
            }
            if (check)
                cout << "Chưa có phòng này!" << endl << "Hãy nhập thông tin của phòng này trước!" << endl;
            break;
        case 4:
            cout << "Nhập mã phòng: "; cin >> id;
            for (int i = 0; i < dsphonghoc.size(); i++)
            {
                if (dsphonghoc.find(i)->getID() == id)
                {
                    cout << *(dsphonghoc.find(i)) << endl;
                    check = 0;
                }
            }
            if (check)
                cout << "Chưa có phòng này!" << endl << "Hãy nhập thông tin của phòng này trước!" << endl;
            break;
        case 5:
            cout << "Nhập mã phòng: "; cin >>  id;
            for (int i = 0; i < dsphongo.size(); i++)
            {
                if (dsphongo.find(i)->getID() == id)
                {
                    cout << *(dsphongo.find(i)) << endl;
                    check = 0;
                }
            }
            if (check)
                cout << "Chưa có phòng này!" << endl << "Hãy nhập thông tin của phòng này trước!" << endl;
            break;
        case 6:
            cout << "Nhập mã số sinh viên: "; cin >> id;
            for (int i = 0; i < dsphongo.size(); i++)
            {
                for (int j = 0; j < dsphongo.find(i)->getDSSinhVien()->size(); j++)
                {
                    if (dsphongo.find(i)->getDSSinhVien()->find(j)->getID() == id)
                    {
                        cout << *(dsphongo.find(i)->getDSSinhVien()->find(j)) << endl;
                        check = 0;
                    }
                }
            }
            if (check)
                cout << "Chưa có sinh viên này!" << endl << "Hãy nhập thông tin của sinh viên này trước!" << endl;
            break;
        case 7:
            cout << "Nhập mã phòng: "; cin >> id;
            for (int i = 0; i < dsphonghoc.size(); i++)
            {
                if (dsphonghoc.find(i)->getID() == id)
                {
                    dsphonghoc.erase(i);
                    check = 0;
                }
            }
            if (check)
                cout << "Chưa có phòng này!" << endl << "Hãy nhập thông tin của phòng này trước!" << endl;
            break;
        case 8:
            cout << "Nhập mã phòng: "; cin >>  id;
            for (int i = 0; i < dsphongo.size(); i++)
            {
                if (dsphongo.find(i)->getID() == id)
                {
                    dsphongo.erase(i);
                    check = 0;
                }
            }
            if (check)
                cout << "Chưa có phòng này!" << endl << "Hãy nhập thông tin của phòng này trước!" << endl;
            break;
        case 9:
            cout << "Nhập mã số sinh viên: "; cin >> id;
            for (int i = 0; i < dsphongo.size(); i++)
            {
                for (int j = 0; j < dsphongo.find(i)->getDSSinhVien()->size(); j++)
                {
                    if (dsphongo.find(i)->getDSSinhVien()->find(j)->getID() == id)
                    {
                        dsphongo.find(i)->getDSSinhVien()->erase(j);
                        check = 0;
                    }
                }
            }
            if (check)
                cout << "Chưa có sinh viên này!" << endl << "Hãy nhập thông tin của sinh viên này trước!" << endl;
            break;
        case 10:
            cout << "Nhập mã phòng: "; cin >> id;
            for (int i = 0; i < dsphonghoc.size(); i++)
            {
                if (dsphonghoc.find(i)->getID() == id)
                {
                    cin >> *(dsphonghoc.find(i));
                    check = 0;
                }
            }
            if (check)
                cout << "Chưa có phòng này!" << endl << "Hãy nhập thông tin của phòng này trước!" << endl;
            break;
        case 11:
            cout << "Nhập mã phòng: "; cin >>  id;
            for (int i = 0; i < dsphongo.size(); i++)
            {
                if (dsphongo.find(i)->getID() == id)
                {
                    cin >> *(dsphongo.find(i));
                    check = 0;
                }
            }
            if (check)
                cout << "Chưa có phòng này!" << endl << "Hãy nhập thông tin của phòng này trước!" << endl;
            break;
        case 12:
            cout << "Nhập mã số sinh viên: "; cin >> id;
            for (int i = 0; i < dsphongo.size(); i++)
            {
                for (int j = 0; j < dsphongo.find(i)->getDSSinhVien()->size(); j++)
                {
                    if (dsphongo.find(i)->getDSSinhVien()->find(j)->getID() == id)
                    {
                        cin >> *(dsphongo.find(i)->getDSSinhVien()->find(j));
                        check = 0;
                    }
                }
            }
            if (check)
                cout << "Chưa có sinh viên này!" << endl << "Hãy nhập thông tin của sinh viên này trước!" << endl;
            break;
        case 13:
            for (int i = 0; i < dsphonghoc.size(); i++)
                cout << *(dsphonghoc.find(i)) << endl;
            break;
        case 14:
            for (int i = 0; i < dsphongo.size(); i++)
                cout << *(dsphongo.find(i)) << endl;
            break;
        case 15:
            for (int i = 0; i < dsphongo.size(); i++)
                for (int j = 0; j < dsphongo.find(i)->getDSSinhVien()->size(); j++)
                        cout << *(dsphongo.find(i)->getDSSinhVien()->find(j)) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}