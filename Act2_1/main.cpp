// g++ -std=c++17 -Wall -O3 -o main *.cpp

#include <iostream>
#include "LinkedList.h"

int main()
{
    std::cout << "Ejemplo de listas ligadas usando Head y Tail\n";

    LinkedList<int> miLista;
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    // addFirst
    std::cout << "Agregando 5 elementos al frente..." << std::endl;
    for (int i = 1; i < 6; i++)
    {
        miLista.addFirst(i);
    }
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    miLista.print();
    std::cout << std::endl;

    // addLast
    std::cout << "Agregando 5 elementos al final..." << std::endl;
    for (int i = 10; i < 15; i++)
    {
        miLista.addLast(i);
    }
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    miLista.print();
    std::cout << std::endl;

    // deleteData
    std::cout << "Delete 12: " << std::endl;
    miLista.deleteData(12);
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    miLista.print();
    std::cout << "Delete 5: " << std::endl;
    miLista.deleteData(5);
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    miLista.print();
    std::cout << "Delete 14: " << std::endl;
    miLista.deleteData(14);
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    miLista.print();
    std::cout << std::endl;

    // DeleteAt puede lanzar una excepcion
    std::cout << "DeleteAt 2: " << std::endl;
    try
    {
        miLista.deleteAt(2);
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Error: " << e.what() << std::endl
                  << "No se modifico la lista" << std::endl;
    }
    catch (...)
    {
        std::cout << "Error desconocido, no se modifico la lista" << std::endl;
    }
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    miLista.print();
    std::cout << "DeleteAt 19: " << std::endl;
    try
    {
        miLista.deleteAt(19);
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Error: " << e.what() << std::endl
                  << "No se modifico la lista" << std::endl;
    }
    catch (...)
    {
        std::cout << "Error desconocido, no se modifico la lista" << std::endl;
    }
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    miLista.print();
    std::cout << std::endl;

    // getData
    try
    {
        std::cout << "getData(3): " << miLista.getData(3) << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Error: " << e.what() << std::endl
                  << "No se modifico la lista" << std::endl;
    }
    catch (...)
    {
        std::cout << "Error desconocido, no se modifico la lista" << std::endl;
    }
    try
    {
        std::cout << "getData(13): " << miLista.getData(13) << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Error: " << e.what() << std::endl
                  << "No se modifico la lista" << std::endl;
    }
    catch (...)
    {
        std::cout << "Error desconocido, no se modifico la lista" << std::endl;
    }

    // findData

    std::cout << "findData(3): " << miLista.findData(3) << std::endl;
    std::cout << "findData(14): " << miLista.findData(14) << std::endl;
    return 0;

    // sobrecarga operador
    std::cout << "Sobrecarga operador: " << std::endl;
    LinkedList<int> miLista2;
    miLista2.addFirst(1);

    miLista = miLista2;
    miLista.print();
    std::cout << "numElements: " << miLista.getSize() << std::endl;
    miLista2.print();
}