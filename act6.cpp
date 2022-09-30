// g++ act1_1.cpp -o act1_1
//  Iván Alberto Romero Wells A00833623
//  Mariano Barberi Garza A01571226
#include <iostream>
#include <vector>

#define print std::cout <<
#define endl std::endl

int busquedaSecuencial(std::vector<int> &v, int x)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(std::vector<int> &v, int x, int izq, int der)
{
    if (izq > der)
    {
        return -1;
    }
    int medio = (izq + der) / 2;
    if (v[medio] == x)
    {
        return medio;
    }
    else if (v[medio] > x)
    {
        return busquedaBinaria(v, x, izq, medio - 1);
    }
    else
    {
        return busquedaBinaria(v, x, medio + 1, der);
    }
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print "Busqueda Secuencial del 1 al 10, buscando 5" << endl;
    print busquedaSecuencial(v, 5) << endl;
    print "Busqueda Binaria del 1 al 10, buscando 5" << endl;
    print busquedaBinaria(v, 5, 0, v.size() - 1) << endl;
    print "Busqueda Secuencial del 1 al 10, buscando 11" << endl;
    print busquedaSecuencial(v, 11) << endl;
    print "Busqueda Binaria del 1 al 10, buscando 11" << endl;
    print busquedaBinaria(v, 11, 0, v.size() - 1) << endl;
    return 0;
}