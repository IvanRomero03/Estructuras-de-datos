/*
    g++ main.cpp -o main & .\main < .\TestCases\test0X.txt > bitacora_ordenada.txt
*/

#include <iostream>
#include "Registro.h"
#include <ctime>

void readInput(std::vector<Registro> &Registros);
void sort(std::vector<Registro> &Registros);
int lowerBound(std::vector<Registro> &Registros, time_t fecha);
int upperBound(std::vector<Registro> &Registros, time_t fecha);
std::vector<Registro> getRango(std::vector<Registro> &Registros, time_t fechaInicio, time_t fechaFin);

int main()
{
    std::vector<Registro> Registros;
    std::string fecha1;
    std::string mes, dia, hora, minuto, segundo;
    std::cin >> mes >> mes;
    std::cin >> mes >> dia >> hora;
    minuto = hora.substr(3, 2);
    segundo = hora.substr(6, 2);
    hora = hora.substr(0, 2);
    time_t first = Registro(mes, dia, hora, minuto, segundo, "", "", "").getTimeStamp();
    std::cin >> mes >> mes;
    std::cin >> mes >> dia >> hora;
    minuto = hora.substr(3, 2);
    segundo = hora.substr(6, 2);
    hora = hora.substr(0, 2);
    time_t last = Registro(mes, dia, hora, minuto, segundo, "", "", "").getTimeStamp();
    readInput(Registros);
    sort(Registros);

    std::vector<Registro> rango = getRango(Registros, first, last);
    if (rango[0] != first)
    {
        std::cout << "No se encontro el primer registro del rango" << std::endl;
    }
    if (rango[rango.size() - 1] != last)
    {
        std::cout << "No se encontro el ultimo registro del rango" << std::endl;
    }
    std::cout << std::endl;
    for (auto i : rango)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

void readInput(std::vector<Registro> &Registros)
{
    //O(n)
    std::string line;
    getline(std::cin, line);
    int n, N;
    std::string mes, dia, hora, minuto, segundo, falla, ip, puerto;
    getline(std::cin, line);
    getline(std::cin, line);
    n = line.find(": ");
    N = stoi(line.substr(n + 2, line.find(" ", n) - n - 2));
    for (int i = 0; i < N; i++)
    {
        std::cin >> mes >> dia >> hora >> ip;
        minuto = hora.substr(3, 2);
        segundo = hora.substr(6, 2);
        hora = hora.substr(0, 2);
        puerto = ip.substr(ip.find(":") + 1, ip.size());
        ip = ip.substr(0, ip.find(":"));
        getline(std::cin, falla);
        Registros.push_back(Registro(mes, dia, hora, minuto, segundo, ip, puerto, falla));
    }
    return;
}

void sort(std::vector<Registro> &Registros)
{
    //O(nlogn)
    // merge sort
    std::vector<Registro> RegistrosSorted;
    if (Registros.size() <= 1)
    {
        return;
    }
    else
    {
        std::vector<Registro> left(Registros.begin(), Registros.begin() + Registros.size() / 2);
        std::vector<Registro> right(Registros.begin() + Registros.size() / 2, Registros.end());
        sort(left);
        sort(right);
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size())
        {
            if (left[i].getTimeStamp() < right[j].getTimeStamp())
            {
                RegistrosSorted.push_back(left[i]);
                i++;
            }
            else
            {
                RegistrosSorted.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size())
        {
            RegistrosSorted.push_back(left[i]);
            i++;
        }
        while (j < right.size())
        {
            RegistrosSorted.push_back(right[j]);
            j++;
        }
        Registros = RegistrosSorted;
    }
    return;
}

int lowerBound(std::vector<Registro> &Registros, time_t fecha)
{
    //O(logn)
    int i = 0, j = Registros.size() - 1, m;
    while (i < j)
    {
        m = (i + j) / 2;
        if (Registros[m].getTimeStamp() < fecha)
        {
            i = m + 1;
        }
        else
        {
            j = m;
        }
    }
    return i;
}

int upperBound(std::vector<Registro> &Registros, time_t fecha)
{
    //O(logn)
    int i = 0, j = Registros.size(), m;
    while (i < j)
    {
        m = (i + j) / 2;
        if (Registros[m].getTimeStamp() <= fecha)
        {
            i = m + 1;
        }
        else
        {
            j = m;
        }
    }
    return i;
}

std::vector<Registro> getRango(std::vector<Registro> &Registros, time_t fechaInicio, time_t fechaFin)
{
    //O(logn)
    std::vector<Registro> rango;
    int i = lowerBound(Registros, fechaInicio);
    int j = upperBound(Registros, fechaFin);
    for (int k = i; k < j; k++)
    {
        rango.push_back(Registros[k]);
    }
    return rango;
}