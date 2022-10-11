// Iván Alberto Romero Wells A00833623
#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    std::cout << "Ejemplo de listas ligadas usando Head y Tail\n";

    DoublyLinkedList<int> miLista;
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
    std::cout << "\nfindData(3): " << miLista.findData(3) << std::endl;
    std::cout << "findData(14): " << miLista.findData(14) << std::endl;
    std::cout << std::endl;

    // operator

    // sort
    std::cout << "Lista desordenada: " << std::endl;
    miLista.print();
    std::cout << "Ordenando la lista..." << std::endl;
    miLista.sort();
    miLista.print();
    std::cout << std::endl;

    // duplicate
    /*
    std::cout << "Duplicar Lista: " << std::endl;
    miLista.print();
    miLista.duplicate();
    std::cout << "Despues: " << std::endl;
    miLista.print();
    */

    // remove duplicates
    std::cout << "Remover duplicados: " << std::endl;
    miLista.print();
    miLista.removeDuplicates();
    std::cout << "Despues: " << std::endl;
    miLista.print();
    std::cout << std::endl;

    // reverse
    std::cout << "Reversa: " << std::endl;
    miLista.print();
    miLista = miLista.getReversedSublist(0, miLista.getSize());
    std::cout << "Despues: " << std::endl;
    miLista.print();
    std::cout << std::endl;

    // clear
    std::cout << "Clear" << std::endl;
    miLista.clear();
    std::cout << "numElements: " << miLista.getSize() << std::endl
              << "Lista: ";
    miLista.print();
    std::cout << std::endl;

    return 0;
}