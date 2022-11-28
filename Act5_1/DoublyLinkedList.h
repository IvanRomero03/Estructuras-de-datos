#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <iostream>
#include <string>
#include "HashNode.h"

template <class T, class K>
class DoublyLinkedList
{
private:
    HashNode<T, K> *head;
    HashNode<T, K> *tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void add(K key, T data);
    void remove(K key);
    void print();
    int getSize();
    HashNode<T, K> *getHead();
    HashNode<T, K> *getTail();
    HashNode<T, K> *find(K key);
};

template <class T, class K>
DoublyLinkedList<T, K>::DoublyLinkedList()
{
    // O(1)
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T, class K>
DoublyLinkedList<T, K>::~DoublyLinkedList()
{
    // O(1)
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T, class K>
void DoublyLinkedList<T, K>::add(K key, T data)
{
    // O(1)
    HashNode<T, K> *newNode = new HashNode<T, K>(key, data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    size++;
}

template <class T, class K>
void DoublyLinkedList<T, K>::remove(K key)
{
    // O(n)
    HashNode<T, K> *current = head;
    while (current != nullptr)
    {
        if (current->getKey() == key)
        {
            if (current->getPrev() != nullptr)
            {
                current->getPrev()->setNext(current->getNext());
            }
            else
            {
                head = current->getNext();
            }
            if (current->getNext() != nullptr)
            {
                current->getNext()->setPrev(current->getPrev());
            }
            else
            {
                tail = current->getPrev();
            }
            size--;
            delete current;
            return;
        }
        current = current->getNext();
    }
}

template <class T, class K>
void DoublyLinkedList<T, K>::print()
{
    // O(n)
    HashNode<T, K> *current = head;
    while (current != nullptr)
    {
        std::cout << current->getData() << std::endl;
        current = current->getNext();
    }
}

template <class T, class K>
int DoublyLinkedList<T, K>::getSize()
{
    // O(1)
    return size;
}

template <class T, class K>
HashNode<T, K> *DoublyLinkedList<T, K>::getHead()
{
    // O(1)
    return head;
}

template <class T, class K>
HashNode<T, K> *DoublyLinkedList<T, K>::getTail()
{
    // O(1)
    return tail;
}

template <class T, class K>
HashNode<T, K> *DoublyLinkedList<T, K>::find(K key)
{
    // O(n)
    HashNode<T, K> *current = head;
    while (current != nullptr)
    {
        if (current->getKey() == key)
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

#endif // _DOUBLY_LINKED_LIST_H_