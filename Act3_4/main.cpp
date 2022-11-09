#include <iostream>
#include "PriorityQueue.h"
#include "Registro.h"
#include <vector>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;

vector<Registro> leerArchivo(string nombreArchivo);
int getUntilDifferent(std::vector<Registro> registros, int i);
vector<pair<Registro, int>> getFrecuencias(std::vector<Registro> registros);

int main()
{
    vector<Registro> registros = leerArchivo("bitacoraHeap-1.txt");
    PriorityQueue<Registro> cola(registros);
    ofstream archivoSalida("bitacora_ordenada.txt");
    std::vector<Registro> lista = cola.getSortedList();
    for (int i = 0; i < lista.size(); i++)
    {
        archivoSalida << lista[i] << std::endl;
    }
    archivoSalida.close();

    vector<pair<Registro, int>> frecuencias = getFrecuencias(lista);

    ofstream archivoSalida2("ips_con_mayor_acceso.txt");

    BinarySearchTree<pair<int, Registro>> BST;
    for (int i = 0; i < frecuencias.size(); i++)
    {
        BST.insert({frecuencias[i].second, frecuencias[i].first});
    }

    for (int i = 0; i < 5; i++)
    {
        pair<int, Registro> Biggest = BST.getBiggest();
        archivoSalida2 << Biggest.second.getIP() << " " << Biggest.first << std::endl;
        BST.deleteNode(Biggest);
    }

    archivoSalida2.close();

    return 0;
}

vector<Registro> leerArchivo(string nombreArchivo)
{
    // O(n)
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

int getUntilDifferent(std::vector<Registro> registros, int i)
{
    // O(logn)
    int j = registros.size() - 1;
    int mid = (i + j) / 2;

    while (i < j)
    {
        if (registros[mid] == registros[i])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
        mid = (i + j) / 2;
    }
    return i;
}

vector<pair<Registro, int>> getFrecuencias(std::vector<Registro> registros)
{
    // O(nlogn)
    vector<pair<Registro, int>> frecuencias;
    int i = 0;
    while (i < registros.size() - 1)
    {
        int j = getUntilDifferent(registros, i);
        Registro registro = registros[i];
        int frecuencia = j - i;
        frecuencias.push_back(make_pair(registro, frecuencia));
        i = j + 1;
    }
    return frecuencias;
}