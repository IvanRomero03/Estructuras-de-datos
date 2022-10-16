/*
    g++ main.cpp -o main & .\main < .\bitacora-1-1.txt
*/

#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Registro.h"
#include <fstream>
#include <ctime>

int main()
{
    std::string line;
    Registro first, last;
    getline(cin, line);
    int n = line.find(":");
    std::string mes, dia, hora, minuto, segundo, falla, ip, puerto;
    n = n + 2;
    mes = line.substr(n, 3);
    n = n + 4;
    dia = line.substr(n, 2);
    n += 3;
    hora = line.substr(n, 2);
    n += 3;
    minuto = line.substr(n, 2);
    n += 3;
    segundo = line.substr(n, 2);
    first = Registro(mes, dia, hora, minuto, segundo, "", "", "");

    getline(cin, line);
    n = line.find(":");
    n = n + 2;
    mes = line.substr(n, 3);
    n = n + 4;
    dia = line.substr(n, 2);
    n += 3;
    hora = line.substr(n, 2);
    n += 3;
    minuto = line.substr(n, 2);
    n += 3;
    segundo = line.substr(n, 2);

    last = Registro(mes, dia, hora, minuto, segundo, "", "", "");
    getline(cin, line);
    getline(cin, line);
    n = line.find(":");
    int lim = line.find(" ", n);
    int N = stoi(line.substr(n + 2, lim - n - 2));
    DoublyLinkedList<Registro> lista;
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
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
        lista.addLast(Registro(mes, dia, hora, minuto, segundo, ip, puerto, falla));
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
    } else cout << "Problem with opening file";


    DoublyLinkedList<Registro> lista2;
    lista2 = lista.getRange(first,last);
    std::ofstream filesearch("resultado_busqueda.txt");
    if (filesearch.is_open())
    {
        DoublyLinkedList<Registro>::iterator it = lista2.begin();
        while (it != lista2.end())
        {
            filesearch << (*it) << endl;
            it++;
        } 
        filesearch.close();
    } else cout << "Problem with opening file";



    return 0;
}