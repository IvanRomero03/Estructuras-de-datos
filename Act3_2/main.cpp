// g++ -std=c++17 -Wall -O3 -o main *.cpp

#include <iostream> 
#include "PriorityQueue.h"

int main()
{
    std::cout << "Ejemplo de un Priority Queue (PQ)" << std::endl;

    PriorityQueue<int> PQ;
    PQ.push(10);
    PQ.push(20);
    PQ.push(30);
    PQ.push(15);
    PQ.push(5);
    PQ.push(115);
    PQ.push(3);
    PQ.push(3);

    PQ.print();

    std::cout << "PQ.top(): " << PQ.top() << std::endl;
    std::cout<<"pop"<<std::endl;
    PQ.pop();
    std::cout << "PQ.top(): " << PQ.top() << std::endl;
    PQ.print();
    std::cout<<"pop"<<std::endl;
    PQ.pop();
    std::cout << "PQ.top(): " << PQ.top() << std::endl;
    PQ.print();
    

    std::cout << "size " << PQ.size() << std::endl;
    std::cout << "empty? " << std::boolalpha << PQ.empty() << std::endl;

    return 0;
    
}