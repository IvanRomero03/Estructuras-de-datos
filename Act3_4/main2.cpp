#include <iostream>
#include "PriorityQueue.h"
#include "Registro.h"
#include <vector>
#include <fstream>

using namespace std;

vector<Registro> leerArchivo(string nombreArchivo);

int main()
{
    vector<Registro> registros = leerArchivo("bitacoraHeap-1.txt");
    PriorityQueue<Registro> cola(registros);
    cola.print();

    return 0;
}

vector<Registro> leerArchivo(string nombreArchivo)
{
    vector<Registro> registros;
    ifstream archivo(nombreArchivo);
    string linea;
    while (getline(archivo, linea))
    {
        string mes, dia, hora, minuto, segundo, ip, puerto, falla;
        int i = 0;
        while (linea[i] != ' ')
        {
            mes += linea[i];
            i++;
        }

        i++;
        while (linea[i] != ' ')
        {
            dia += linea[i];
            i++;
        }

        i++;
        while (linea[i] != ':')
        {
            hora += linea[i];
            i++;
        }

        i++;
        while (linea[i] != ':')
        {
            minuto += linea[i];
            i++;
        }

        i++;
        while (linea[i] != ' ')
        {
            segundo += linea[i];
            i++;
        }

        i++;
        while (linea[i] != ':')
        {
            ip += linea[i];
            i++;
        }

        i++;
        while (linea[i] != ' ')
        {
            puerto += linea[i];
            i++;
        }

        i++;
        while (i < linea.size())
        {
            falla += linea[i];
            i++;
        }

        Registro registro(mes, dia, hora, minuto, segundo, ip, puerto, falla);
        registros.push_back(registro);
    }
    return registros;
}