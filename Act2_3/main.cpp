/*
    g++ main.cpp -o main & .\main < .\bitacora-1-1.txt
*/

#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Registro.h"
#include <fstream>

int main()
{
    std::string line;
    int n, lim;
    std::string mes, dia, hora, minuto, segundo, falla, ip, puerto;
    DoublyLinkedList<Registro> lista;
    while (getline(cin, line))
    {
        n = 0;
        mes = line.substr(0, 3);
        n = n + 4;
        dia = line.substr(n, 2);
        n += 3;
        hora = line.substr(n, 2);
        n += 3;
        minuto = line.substr(n, 2);
        n += 3;
        segundo = line.substr(n, 2);
        n += 3;
        lim = line.find(":", n);
        ip = line.substr(n, lim - n);
        n = lim + 1;
        lim = line.find(" ", n);
        puerto = line.substr(n, lim - n);
        n = lim + 1;
        falla = line.substr(n, line.size() - n);
        Registro reg(mes, dia, hora, minuto, segundo, falla, ip, puerto);
        lista.addLast(reg);
    }
    lista.sort();
    std::ofstream filesort("bitacora_ordenada.txt");
    if (filesort.is_open())
    {
        DoublyLinkedList<Registro>::iterator it = lista.begin();
        while (it != lista.end())
        {
            filesort << (*it) << endl;
            it++;
        }
        filesort.close();
    } 
    else cout << "Problem with opening file";
}