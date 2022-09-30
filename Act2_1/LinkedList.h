#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>

template <class T>
class LinkedList
{
private:
    struct Node
    {
        T val;
        Node *next;
    };
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList();
    LinkedList(LinkedList<T> &list);
    LinkedList(T val);
    ~LinkedList();
    void addFirst(T val);
    void addLast(T val);
    bool deleteData(T val);
    bool deleteAt(int index);
    T getData(int index);
    void updateData(T pastVal, T newVal);
    void updateAt(int index, T newVal);
    int findData(T val);
    void operator=(LinkedList<T> &list);
};

#endif // _LINKEDLIST_H_