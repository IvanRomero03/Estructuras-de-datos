// Iván Alberto Romero Wells A00833623
#include <bits/stdc++.h>
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList<int> lista;
    lista.addLast(5);
    lista.addLast(3);
    lista.addLast(8);
    lista.addLast(1);

    lista.print();

    lista.sort();

    lista.print();

    return 0;
}