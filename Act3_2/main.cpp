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

    std::cout << "top " << PQ.top() << std::endl;
    PQ.pop();
    std::cout << "top " << PQ.top() << std::endl;
    PQ.pop();
    std::cout << "top " << PQ.top() << std::endl;
    PQ.pop();
    std::cout << "top " << PQ.top() << std::endl;
    PQ.pop();
    std::cout << "top " << PQ.top() << std::endl;
    PQ.pop();
    std::cout << "top " << PQ.top() << std::endl;
    PQ.pop();
    std::cout << "top " << PQ.top() << std::endl;
    PQ.pop();
    std::cout << "top " << PQ.top() << std::endl;
    PQ.pop();
    try {
        std::cout << "top " << PQ.top() << std::endl;
        PQ.pop();
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "size " << PQ.size() << std::endl;
    std::cout << "empty " << std::boolalpha << PQ.empty() << std::endl;

    return 0;
    
}