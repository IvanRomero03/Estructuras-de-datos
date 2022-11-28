#ifndef _HASHNODE_H_
#define _HASHNODE_H_

#include <iostream>
#include <string>

template <class T, class K>
class HashNode
{
private:
    T data;
    K key;
    HashNode<T, K> *next;
    HashNode<T, K> *prev;
    int status;

public:
    HashNode();
    HashNode(K key, T data);
    T getData();
    void setData(T data);
    K getKey();
    void setKey(K key);
    HashNode<T, K> *getNext();
    void clearNext();
    void setNext(HashNode<T, K> *next);
    HashNode<T, K> *getPrev();
    void clearPrev();
    void setPrev(HashNode<T, K> *prev);
    int getStatus();
    void setStatus(int);
    void clearData();
};

template <class T, class K>
HashNode<T, K>::HashNode()
{
    // O(1)
    this->key = K();
    this->data = T();
    this->status = 0;
    this->next = NULL;
    this->prev = NULL;
}

template <class T, class K>
HashNode<T, K>::HashNode(K key, T data)
{
    // O(1)
    this->key = key;
    this->data = data;
    this->status = 1;
    this->next = NULL;
    this->prev = NULL;
}

template <class T, class K>
T HashNode<T, K>::getData()
{
    // O(1)
    return data;
}

template <class T, class K>
void HashNode<T, K>::setData(T data)
{
    // O(1)
    this->data = data;
}

template <class T, class K>
K HashNode<T, K>::getKey()
{
    // O(1)
    return key;
}

template <class T, class K>
void HashNode<T, K>::setKey(K key)
{
    // O(1)
    this->key = key;
}

template <class T, class K>
HashNode<T, K> *HashNode<T, K>::getNext()
{
    // O(1)
    return next;
}

template <class T, class K>
void HashNode<T, K>::clearNext()
{
    // O(1)
    this->next = NULL;
}

template <class T, class K>
void HashNode<T, K>::setNext(HashNode<T, K> *next)
{
    // O(1)
    this->next = next;
}

template <class T, class K>
HashNode<T, K> *HashNode<T, K>::getPrev()
{
    // O(1)
    return prev;
}

template <class T, class K>
void HashNode<T, K>::clearPrev()
{
    // O(1)
    this->prev = NULL;
}

template <class T, class K>
void HashNode<T, K>::setPrev(HashNode<T, K> *prev)
{
    // O(1)
    this->prev = prev;
}

template <class T, class K>
int HashNode<T, K>::getStatus()
{
    // O(1)
    return status;
}

template <class T, class K>
void HashNode<T, K>::setStatus(int status)
{
    // O(1)
    this->status = status;
}

template <class T, class K>
void HashNode<T, K>::clearData()
{
    // O(1)
    this->data = T();
}

#endif // _HASHNODE_H_