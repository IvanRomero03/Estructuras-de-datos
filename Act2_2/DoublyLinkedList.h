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
    void split(int index, DoublyLinkedList<T> &l1, DoublyLinkedList<T> &l2);
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

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
void DoublyLinkedList<T>::clear()
{
    // O(n)
    Node *temp = head;
    while (temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    // O(n)
    clear();
}

template <class T>
void DoublyLinkedList<T>::addFirst(T val)
{
    // O(1)
    Node *newNode = new Node(val);
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == nullptr)
    {
        tail = newNode;
    }
    size++;
}

template <class T>
void DoublyLinkedList<T>::addLast(T val)
{
    // O(1)
    Node *newNode = new Node(val);
    newNode->next = nullptr;
    newNode->prev = tail;
    if (tail != nullptr)
    {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr)
    {
        head = newNode;
    }
    size++;
}

template <class T>
bool DoublyLinkedList<T>::deleteData(T val)
{
    // O(n)
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->val == val)
        {
            if (temp->prev != nullptr)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                head = temp->next;
            }
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                tail = temp->prev;
            }
            delete temp;
            size--;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool DoublyLinkedList<T>::deleteAt(int index)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        return false;
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        tail = temp->prev;
    }
    delete temp;
    size--;
    return true;
}

template <class T>
T DoublyLinkedList<T>::getData(int index)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        return -1;
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->val;
}

template <class T>
void DoublyLinkedList<T>::updateData(T pastVal, T newVal)
{
    // O(n)
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->val == pastVal)
        {
            temp->val = newVal;
            return;
        }
        temp = temp->next;
    }
}

template <class T>
void DoublyLinkedList<T>::updateAt(int index, T newVal)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        return;
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    temp->val = newVal;
}

template <class T>
int DoublyLinkedList<T>::findData(T val)
{
    // O(n)
    Node *temp = head;
    int index = 0;
    while (temp != nullptr)
    {
        if (temp->val == val)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

template <class T>
int DoublyLinkedList<T>::getSize()
{
    // O(1)
    return size;
}

template <class T>
void DoublyLinkedList<T>::print()
{
    // O(n)
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// template <class T>
// void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> &list)
// {
//     // O(n)
//     clear();
//     Node *temp = list.head;
//     while (temp != nullptr)
//     {
//         addLast(temp->val);
//         temp = temp->next;
//     }
// }

template <class T>
void DoublyLinkedList<T>::operator=(std::vector<T> &list)
{
    // O(n)
    clear();
    for (int i = 0; i < list.size(); i++)
    {
        addLast(list[i]);
    }
}

template <class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list)
{
    // O(n)
    clear();
    Node *temp = list.head;
    while (temp != nullptr)
    {
        addLast(temp->val);
        temp = temp->next;
    }
}

template <class T>
void DoublyLinkedList<T>::split(int index, DoublyLinkedList<T> &l1, DoublyLinkedList<T> &l2)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        return;
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        l1.addLast(temp->val);
        temp = temp->next;
    }
    while (temp != nullptr)
    {
        l2.addLast(temp->val);
        temp = temp->next;
    }
}

template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::mergeSortedLists(DoublyLinkedList<T> &list1, DoublyLinkedList<T> &list2)
{
    // O(n)
    DoublyLinkedList<T> list;
    Node *temp1 = list1.head;
    Node *temp2 = list2.head;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->val < temp2->val)
        {
            list.addLast(temp1->val);
            temp1 = temp1->next;
        }
        else
        {
            list.addLast(temp2->val);
            temp2 = temp2->next;
        }
    }
    while (temp1 != nullptr)
    {
        list.addLast(temp1->val);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        list.addLast(temp2->val);
        temp2 = temp2->next;
    }
    return list;
}

template <class T>
void DoublyLinkedList<T>::sort()
{
    // O(nlogn)
    if (size <= 1)
    {
        return;
    }
    DoublyLinkedList<T> l1, l2;
    split(size / 2, l1, l2);
    l1.sort();
    l2.sort();
    *this = mergeSortedLists(l1, l2);
}

template <class T>
void DoublyLinkedList<T>::duplicate()
{
    // O(n)
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        if (newNode->next != nullptr)
        {
            newNode->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        temp = newNode->next;
        size++;
    }
}

template <class T>
void DoublyLinkedList<T>::removeDuplicates()
{
    // O(n)
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->next != nullptr && temp->val == temp->next->val)
        {
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            if (temp->next != nullptr)
            {
                temp->next->prev = temp;
            }
            else
            {
                tail = temp;
            }
            delete temp2;
            size--;
        }
        else
        {
            temp = temp->next;
        }
    }
}

template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::getReversedSublist(int start, int end)
{
    // O(n)
    DoublyLinkedList<T> list;
    Node *temp = tail;
    for (int i = size - 1; i >= 0; i--)
    {
        if (i >= start && i <= end)
        {
            list.addLast(temp->val);
        }
        temp = temp->prev;
    }
    return list;
}

#endif // _DoublyLinkedList_H_