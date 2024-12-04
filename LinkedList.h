#pragma once
template <typename T>
struct Node {
    T *pData;
    Node *pNext;
};

template <typename T>
class LinkedList {
public:
    Node<T> *pStart;

    LinkedList() : pStart(nullptr) {}

    ~LinkedList() {
        while (pStart != nullptr) {
            Node<T> *temp = pStart;
            pStart = pStart->pNext;
            delete temp->pData;
            delete temp;
        }
    }

    void InsertAtFront(T *data) {
        Node<T> *node = new Node<T>{data, pStart};
        pStart = node;
    }

    void InsertAtEnd(T *data) {
        Node<T> *node = new Node<T>{data, nullptr};
        if (pStart == nullptr) {
            pStart = node;
        } else {
            Node<T> *current = pStart;
            while (current->pNext != nullptr) {
                current = current->pNext;
            }
            current->pNext = node;
        }
    }
};
