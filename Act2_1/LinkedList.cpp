#include <LinkedList.h>
#include <iostream>
#include <exception>

template <class T>
LinkedList<T>::LinkedList()
{
    // O(1)
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &list)
{
    // O(n)
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node *temp = list.head;
    while (temp != nullptr)
    {
        addLast(temp->val);
        temp = temp->next;
    }
}
template <class T>
LinkedList<T>::LinkedList(T val)
{
    // O(1)
    head = nullptr;
    tail = nullptr;
    size = 0;
    addLast(val);
}
template <class T>
LinkedList<T>::~LinkedList()
{
    // O(n)
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
}
template <class T>
void LinkedList<T>::addFirst(T val)
{
    // O(1)
    Node *temp = new Node;
    temp->val = val;
    temp->next = head;
    head = temp;
    if (tail == nullptr)
    {
        tail = temp;
    }
    size++;
}
template <class T>
void LinkedList<T>::addLast(T val)
{
    // O(1)
    Node *temp = new Node;
    temp->val = val;
    temp->next = nullptr;
    if (tail != nullptr)
    {
        tail->next = temp;
    }
    tail = temp;
    if (head == nullptr)
    {
        head = temp;
    }
    size++;
}
template <class T>
bool LinkedList<T>::deleteData(T val)
{
    // O(n)
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->val == val)
        {
            if (prev == nullptr)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            if (temp == tail)
            {
                tail = prev;
            }
            delete temp;
            size--;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::deleteAt(int index)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        return false;
    }
    Node *temp = head;
    Node *prev = nullptr;
    for (int i = 0; i < index; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == nullptr)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    if (temp == tail)
    {
        tail = prev;
    }
    delete temp;
    size--;
    return true;
}
template <class T>
T LinkedList<T>::getData(int index)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->val;
}
template <class T>
void LinkedList<T>::updateData(T pastVal, T newVal)
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
    throw std::out_of_range("Value not found");
}
template <class T>
void LinkedList<T>::updateAt(int index, T newVal)
{
    // O(n)
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    temp->val = newVal;
}
template <class T>
int LinkedList<T>::findData(T val)
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
        index++;
        temp = temp->next;
    }
    return -1;
}
template <class T>
void LinkedList<T>::operator=(LinkedList<T> &list)
{
    // O(n)
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
    temp = list.head;
    while (temp != nullptr)
    {
        addLast(temp->val);
        temp = temp->next;
    }
}