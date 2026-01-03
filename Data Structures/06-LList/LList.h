#ifndef LLIST_H
#define LLIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
class LList {
    private:
        int count;
        Node<T>* head;
    public:
        LList() : head(nullptr) {};
        ~LList();
        void insert(const T& item); // add in between
        void remove(const T& item);
        void search(const T& item);
        void printAll();
        bool isEmpty();
};

template <typename T>
LList<T>::~LList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
void LList<T>::insert(const T& item) {
    auto* newNode = new Node<T>;
    newNode->data = item;

    if (isEmpty() || newNode->data < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node<T>* current = head;
    Node<T>* temp = nullptr;
    while (current->next != nullptr && current->next->data < newNode->data) {
        current = current->next;
    }

    temp = current->next;
    current->next = newNode;
    newNode->next = temp;
}

template<typename T>
void LList<T>::printAll() {
    if (isEmpty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

template<typename T>
bool LList<T>::isEmpty() {
    return head == nullptr;
}


#endif