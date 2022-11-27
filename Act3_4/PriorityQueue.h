#ifndef _PRIOQUEUE_H
#define _PRIOQUEUE_H

#include <iostream>
#include <vector>
#include <exception>

template <typename T>
class PriorityQueue
{
private:
    std::vector<T> list;
    void swap(int i, int j);
    void heap(int i);

public:
    PriorityQueue();
    PriorityQueue(std::vector<T> list);
    ~PriorityQueue();
    void push(T value);
    void pop();
    T top();
    bool empty();
    int size();
    void print(std::ostream &os);
    std::vector<T> getList();
    std::vector<T> getSortedList();
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    // O(1)
}

template <typename T>
PriorityQueue<T>::PriorityQueue(std::vector<T> list)
{
    // O(n)
    this->list = list;
    for (int i = list.size() / 2; i >= 0; i--)
    {
        heap(i);
    }
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    // O(1)
}

template <typename T>
void PriorityQueue<T>::swap(int i, int j)
{
    // O(1)
    T temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

template <typename T>
void PriorityQueue<T>::heap(int i)
{
    // O(logn)
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < (int)list.size() && list[left] > list[largest])
        largest = left;
    if (right < (int)list.size() && list[right] > list[largest])
        largest = right;
    if (largest != i)
    {
        swap(i, largest);
        heap(largest);
    }
}

template <typename T>
void PriorityQueue<T>::push(T value)
{
    // O(logn)
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
    // O(logn)
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
    // O(1)
    if (!empty())
        return list[0];
    else
    {
        std::cout << "Empty queue" << std::endl;
    }
    return T();
}

template <typename T>
bool PriorityQueue<T>::empty()
{
    // O(1)
    return list.size() == 0;
}

template <typename T>
int PriorityQueue<T>::size()
{
    // O(1)
    return list.size();
}

template <typename T>
void PriorityQueue<T>::print(std::ostream &os)
{
    // O(n)
    for (int i = 0; i < (int)list.size(); i++)
    {
        os << list[i] << std::endl;
    }
}

template <typename T>
std::vector<T> PriorityQueue<T>::getList()
{
    // O(1)
    return list;
}

template <typename T>
std::vector<T> PriorityQueue<T>::getSortedList()
{
    // O(nlogn)
    std::vector<T> sortedList;
    PriorityQueue<T> copy = PriorityQueue<T>(list);
    while (!copy.empty())
    {
        sortedList.push_back(copy.top());
        copy.pop();
    }
    return sortedList;
}

#endif // _PRIOQUEUE_H