// Iván Alberto Romero Wells A00833623

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> Lista(5);
    Lista.addFirst(4);
    Lista.addLast(6);
    std::cout << Lista.getData(0) << std::endl;
    std::cout << Lista.getData(1) << std::endl;
    std::cout << Lista.getData(2) << std::endl;
    Lista.deleteAt(0);
    Lista.deleteData(6);
    Lista.updateData(5, 7);
    Lista.updateAt(0, 8);
    std::cout << Lista.findData(7) << std::endl;
    LinkedList<int> newLista(9);
    Lista = newLista;
}