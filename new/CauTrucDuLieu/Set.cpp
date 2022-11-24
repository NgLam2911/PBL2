#include <iostream>
#include <string>
#include "Set.h"
using namespace std;

template <typename T>
Set<T>::Set(T* head): head(head){};
template <typename T>
Set<T>::~Set()
{
    // delete head;
}

template <typename T>
void Set<T>::sapxep(Set &x)
{
    for (T *temp1 = this->head; temp1 != NULL; temp1 = temp1->getNext())
        for (T *temp2 = temp1->getNext(); temp2 != NULL; temp2 = temp2->getNext())
            if (temp1->getID() > temp2->getID())
                swap(*temp1, *temp2);
}

// template <typename T>
// void Set<T>::xoaLap(Set &x)
// {
//     for (T *temp1 = x.head; temp1 != NULL; temp1 = temp1->getNext())
//         for (T *temp2 = temp1->getNext(); temp2 != NULL; temp2 = temp2->getNext())
//             while (temp1->getID() == temp2->getID())
//             {
//                 if (temp2->getNext() == NULL)
//                 {
//                     temp1->setNext(NULL);
//                     return;
//                 }
//                 else
//                 {
//                     temp1->setNext(temp2->getNext());
//                     temp2 = temp1->getNext();
//                 }
//             }   
// }

template <typename T>
int Set<T>::size() const
{
    int count = 0;
    T *temp = this->head;
    while (temp != NULL)
    {
        temp = temp->getNext();
        count++;
    }
    return count;
}

template <typename T>
bool Set<T>::empty() const
{
    return this->head == NULL;
}

template <typename T>
void Set<T>::insert(T moi1)
{
    T *moi = new T;
    *moi = moi1;
    if (this->empty())
    {
        this->head = moi;
        cout << "Đã thêm!" << endl;
        return;
    }
    // if (moi->getID() > 1000 && this->size() == 8)
    // {
    //     cout << "Phòng này đã đầy người!" << endl << "Không thể thêm vào Cơ sở Dữ liệu!" << endl;
    //     return;
    // }
    for (T *temp = this->head; temp != NULL; temp = temp->getNext())
    if (temp->getID() == moi->getID())
    {
        cout << "Đã có trong Cơ sở dữ liệu!" << endl << "Hệ thống sẽ không ghi nhận thông tin này!" << endl;
        return;
    }
    T *temp = this->head;
    while (temp->getNext() != NULL)
        temp = temp->getNext();
    temp->setNext(moi);
    cout << "Đã thêm!" << endl;
    sapxep(*this);
    // xoaLap(*this);
    // delete moi;
}

template <typename T>
void Set<T>::erase(int x)
{
    T *temp1 = this->head, *temp2 = NULL;
    if (this->empty())
    {
        cout << "Rỗng!" << endl;
        return;
    }
    if (this->size() <= x)
    {
        cout << "Không có trong Cơ sở dữ liệu!" << endl;
        return;
    }
    if (x == 0)
    {
        this->head = (this->head)->getNext();
        cout << "Đã xóa!" << endl;
        delete temp1;
        return;
    }
    while (x-- > 0)
    {
        temp2 = temp1;
        temp1 = temp1->getNext();
    }
    temp2->setNext(temp1->getNext());
    cout << "Đã xóa!" << endl;
    delete temp1;
}

template <typename T>
T* Set<T>::find(int x) const
{
    T *temp = this->head;
    if (this->size() <= x)
    {
        cout << "Nằm ngoài Cơ sở dữ liệu!" << endl;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        return temp;
    }
    while(x)
    {
        temp = temp->getNext();
        x--;
    }
    return temp;
}