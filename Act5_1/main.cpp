#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "HashNode.h"
#include "HashTable.h"

int main()
{
    HashTable<int, std::string> numerosARomano(18181);
    numerosARomano.add(1, "I");
    numerosARomano.add(2, "II");
    numerosARomano.add(3, "III");
    numerosARomano.add(4, "IV");
    numerosARomano.add(5, "V");
    numerosARomano.add(6, "VI");
    numerosARomano.add(7, "VII");
    numerosARomano.add(8, "VIII");
    numerosARomano.add(9, "IX");
    numerosARomano.add(10, "X");

    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << ": " << numerosARomano[i] << std::endl;
    }

    numerosARomano.remove(1);
    numerosARomano.remove(2);

    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << ": " << numerosARomano[i] << std::endl;
    }

    return 0;
}