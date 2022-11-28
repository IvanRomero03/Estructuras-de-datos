#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include "HashNode.h"
#include "DoublyLinkedList.h"

template <class K, class T>
class HashTable
{
private:
    std::vector<DoublyLinkedList<T, K>> table;
    int currentSize;
    int maxSize;

public:
    HashTable(int selectedMaxSize);
    ~HashTable();
    int getHashIndex(K keyVal);
    int getCurrentSize();
    void print();
    void add(K keyValue, T dataValue);
    int find(K keyValue);
    T getDataAt(int index);
    void setAt(int index, T dataValue, T newValue);
    void remove(K keyValue);
    T operator[](K keyValue);
};

template <class K, class T>
HashTable<K, T>::HashTable(int maxSize)
{
    // O(1)
    this->currentSize = 0;
    this->maxSize = maxSize;
    this->table.resize(maxSize);
}

template <class K, class T>
HashTable<K, T>::~HashTable()
{
    // O(1)
    this->currentSize = 0;
    this->maxSize = 0;
    this->table.clear();
}

template <class K, class T>
int HashTable<K, T>::getHashIndex(K keyVal)
{
    // O(1)
    return keyVal % maxSize;
}

template <class K, class T>
int HashTable<K, T>::getCurrentSize()
{
    // O(1)
    return currentSize;
}

template <class K, class T>
void HashTable<K, T>::print()
{
    // O(n)
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << "Index " << i << ": ";
        table[i].print();
    }
}

template <class K, class T>
void HashTable<K, T>::add(K keyValue, T dataValue)
{
    // O(1)
    int index = getHashIndex(keyValue);
    table[index].add(keyValue, dataValue);
    currentSize++;
}

template <class K, class T>
int HashTable<K, T>::find(K keyValue)
{
    // O(1)
    int index = getHashIndex(keyValue);
    HashNode<T, K> *node = table[index].find(keyValue);
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

template <class K, class T>
T HashTable<K, T>::getDataAt(int index)
{
    // O(1)
    return table[index].getHead()->getData();
}

template <class K, class T>
void HashTable<K, T>::setAt(int index, T dataValue, T newValue)
{
    // O(1)
    HashNode<T, K> *node = table[index].find(dataValue);
    if (node == nullptr)
    {
        throw std::invalid_argument("No se encontro el valor");
    }
    else
    {
        node->setData(newValue);
    }
}

template <class K, class T>
void HashTable<K, T>::remove(K keyValue)
{
    // O(1)
    int index = getHashIndex(keyValue);
    if (index != -1)
    {
        table[index].remove(keyValue);
        currentSize--;
    }
}

template <class K, class T>
T HashTable<K, T>::operator[](K keyValue)
{
    // O(1)
    int index = getHashIndex(keyValue);
    HashNode<T, K> *node = table[index].find(keyValue);
    if (node == nullptr)
    {
        return T();
    }
    else
    {
        return node->getData();
    }
}

#endif