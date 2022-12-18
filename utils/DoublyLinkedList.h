#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

template<typename type>
class DoublyLinkedList {
private:
    struct Node {
        type value;
        Node *next;
        Node *prev;
    };
    Node *head;
    int size;

    Node createNode(type data, Node *prev = nullptr, Node *next = nullptr);

protected:
    Node *getNode(int index) const;

    void insertNode(int index, Node &node);

    void removeNode(int index);

    void swapNodes(Node *node1, Node *node2);

public:
    DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList &orig);

    virtual ~DoublyLinkedList();

    int getSize() const;

    type &get(int index) const;

    type front() const;

    type back() const;

    bool isEmpty() const;

    void insert(type value, int index);

    void push_front(type value);

    void push_back(type value);

    void remove(int index);

    void pop_front();

    void pop_back();

    void clear();

    void sort(bool (*compare)(type, type));

    void reverse();

    void fill(type value, int fillSize = 0);
};

template<typename type>
DoublyLinkedList<type>::DoublyLinkedList() : head(nullptr), size(0) {}

template<typename type>
DoublyLinkedList<type>::DoublyLinkedList(const DoublyLinkedList &orig) {
    this->head = nullptr;
    this->size = 0;
    for (int i = 0; i < orig.getSize(); i++) {
        push_back(orig.get(i));
    }
}

template<typename type>
DoublyLinkedList<type>::~DoublyLinkedList() {
    clear();
}

template<typename type>
int DoublyLinkedList<type>::getSize() const {
    return this->size;
}

template<typename type>
type &DoublyLinkedList<type>::get(int index) const {
    return getNode(index)->value;
}

template<typename type>
type DoublyLinkedList<type>::front() const {
    return get(0);
}

template<typename type>
type DoublyLinkedList<type>::back() const {
    return get(getSize() - 1);
}

template<typename type>
bool DoublyLinkedList<type>::isEmpty() const {
    return getSize() == 0;
}

template<typename type>
void DoublyLinkedList<type>::insert(type value, int index) {
    if (index < 0 || index > getSize()) {
        throw std::out_of_range("Index out of range");
    }
    Node *node = new Node;
    *node = createNode(value);
    insertNode(index, *node);
}

template<typename type>
void DoublyLinkedList<type>::push_front(type value) {
    insert(value, 0);
}

template<typename type>
void DoublyLinkedList<type>::push_back(type value) {
    insert(value, getSize());
}

template<typename type>
void DoublyLinkedList<type>::remove(int index) {
    if (index < 0 || index >= getSize()) {
        throw std::out_of_range("Index out of range");
    }
    removeNode(index);
}

template<typename type>
void DoublyLinkedList<type>::pop_front() {
    remove(0);
}

template<typename type>
void DoublyLinkedList<type>::pop_back() {
    remove(getSize() - 1);
}

template<typename type>
void DoublyLinkedList<type>::clear() {
    while (!isEmpty()) {
        pop_front();
    }
}

template<typename type>
void DoublyLinkedList<type>::sort(bool (*compare)(type, type)) {
    for (int i = 0; i < getSize(); i++) {
        for (int j = 0; j < getSize() - 1; j++) {
            if (compare(get(j + 1), get(j))) {
                swapNodes(getNode(j), getNode(j + 1));
            }
        }
    }
}

template<typename type>
bool ascending(type type1, type type2) {
    return type1.getID() < type2.getID();
}

template<typename type>
bool descending(type type1, type type2) {
    return type1.getID() > type2.getID();
}

template<typename type>
void DoublyLinkedList<type>::reverse() {
    for (int i = 0; i < getSize() / 2; i++) {
        swapNodes(&getNode(i), &getNode(getSize() - 1 - i));
    }
}

template<typename type>
void DoublyLinkedList<type>::fill(type value, int fillSize) {
    clear();
    if (fillSize < 0) {
        throw std::invalid_argument("Fill size must be greater than or equal to 0");
    }
    if (fillSize == 0) {
        fillSize = getSize();
    }
    for (int i = 0; i < fillSize; i++) {
        push_back(value);
    }
}

template<typename type>
typename DoublyLinkedList<type>::Node DoublyLinkedList<type>::createNode(type data, Node *prev, Node *next) {
    Node node;
    node.value = data;
    node.prev = prev;
    node.next = next;
    return node;
}

template<typename type>
typename DoublyLinkedList<type>::Node *DoublyLinkedList<type>::getNode(int index) const {
    if (index < 0 || index >= getSize()) {
        throw std::out_of_range("Index out of range");
    }
    Node *node = this->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

template<typename type>
void DoublyLinkedList<type>::insertNode(int index, Node &node) {
    if (index < 0 || index > getSize()) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        node.prev = nullptr;
        node.next = this->head;
        if (this->head != nullptr) {
            this->head->prev = &node;
        }
        this->head = &node;
    } else {
        for (Node *temp = this->head; temp != nullptr; temp = temp->next)
            if (temp->value.getID() == node.value.getID())
                throw std::domain_error("This object is duplicated!");
        Node *prevNode = getNode(index - 1);
        node.prev = prevNode;
        node.next = prevNode->next;
        if (prevNode->next != nullptr) {
            prevNode->next->prev = &node;
        }
        prevNode->next = &node;
    }
    this->size++;
}

template<typename type>
void DoublyLinkedList<type>::removeNode(int index) {
    if (index < 0 || index >= getSize()) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        Node *node = this->head;
        this->head = node->next;
        if (node->next != nullptr) {
            node->next->prev = nullptr;
        }
        delete node;
    } else {
        Node *node = getNode(index);
        node->prev->next = node->next;
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        delete node;
    }
    this->size--;
}

template<typename type>
void DoublyLinkedList<type>::swapNodes(Node *node1, Node *node2) {
    if (node1 == node2) {
        return;
    }
    type temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

#endif