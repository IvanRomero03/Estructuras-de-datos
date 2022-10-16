#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Registro.h"

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
    std::ofstream bitacoraordenada;
    // chúpala mariano
}