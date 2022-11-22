#ifndef _PRIOQUEUE_H
#define _PRIOQUEUE_H

#include <iostream>
#include <vector>
#include <exception>

template <typename T>
class PriorityQueue
{
private:
    bool maxHeap;
    std::vector<T> list;
    void swap(int i, int j);
    void heap(int i);

public:
    PriorityQueue();
    PriorityQueue(bool maxHeap);
    PriorityQueue(std::vector<T> &v);
    ~PriorityQueue();
    void push(T value);
    void pop();
    T top();
    bool empty();
    int size();
    void print();
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    maxHeap = true;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(bool maxHeap)
{
    // O(1)
    this->maxHeap = maxHeap;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(std::vector<T> &v)
{
    // O(n)
    this->maxHeap = true;
    for (long long unsigned int i = 0; i < v.size(); i++)
    {
        list.push_back(v[i]);
    }
    for (int i = list.size() / 2 - 1; i >= 0; i--)
    {
        heap(i);
    }
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
}

template <typename T>
void PriorityQueue<T>::swap(int i, int j)
{
    T temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

template <typename T>
void PriorityQueue<T>::heap(int i)
{
    if (maxHeap)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < list.size() && list[left] > list[largest])
        {
            largest = left;
        }
        if (right < list.size() && list[right] > list[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(i, largest);
            heap(largest);
        }
    }
    else
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < list.size() && list[left] < list[smallest])
        {
            smallest = left;
        }
        if (right < list.size() && list[right] < list[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(i, smallest);
            heap(smallest);
        }
    }
}

template <typename T>
void PriorityQueue<T>::push(T value)
{
    list.push_back(value);
    int i = list.size() - 1;
    while (i > 0 && list[(i - 1) / 2] < list[i])
    {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

template <typename T>
void PriorityQueue<T>::pop()
{
    if (!empty())
    {
        list[0] = list[list.size() - 1];
        list.pop_back();
        heap(0);
    }
    return;
}

template <typename T>
T PriorityQueue<T>::top()
{
    if (!empty())
        return list[0];
    else
    {
        std::cout << "Empty queue" << std::endl;
    }
    return list[0];
}

template <typename T>
bool PriorityQueue<T>::empty()
{
    return list.size() == 0;
}

template <typename T>
int PriorityQueue<T>::size()
{
    return list.size();
}

template <typename T>
void PriorityQueue<T>::print()
{
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}

#endif // _PRIOQUEUE_H