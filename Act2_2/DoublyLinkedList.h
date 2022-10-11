#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>

template <class T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T val;
        Node *next;
        Node *prev;
        Node(T val)
        {
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node *head;
    Node *tail;
    int size;
    // FIXME: Ver si no ocupa std:: // si ocupaba jaja
    std::pair<DoublyLinkedList<T>, DoublyLinkedList<T>> split(int index);
    DoublyLinkedList<T> mergeSortedLists(DoublyLinkedList<T> &list1, DoublyLinkedList<T> &list2);

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addFirst(T val);
    void addLast(T val);
    bool deleteData(T val);
    bool deleteAt(int index);
    T getData(int index);
    void updateData(T pastVal, T newVal);
    void updateAt(int index, T newVal);
    int findData(T val);
    int getSize();
    void print();
    void operator=(DoublyLinkedList<T> &list);
    void operator=(std::vector<T> &list);
    void operator=(DoublyLinkedList<T> list);
    void clear();
    void sort();
    void duplicate();
    void removeDuplicates();
    DoublyLinkedList<T> getReversedSublist(int start, int end);
};

#endif // _DoublyLinkedList_H_