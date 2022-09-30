// g++ act1_2.cpp -o act1_2 & .\act1_2 < .\TestCases\test0X.txt
//  Iván Alberto Romero Wells A00833623
//  Mariano Barberi Garza A01571226
#include <iostream>
#include <vector>

#define cout std::cout
#define endl std::endl
#define cin std::cin
#define vector std::vector

void ordenaBurbuja(vector<int> &v)
{
    int n = v.size();
    int i, j, aux;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    return;
}

void ordenaMerge(vector<int> &v)
{
    int n = v.size();
    if (n > 1)
    {
        int m = n / 2;
        vector<int> izq;
        vector<int> der;
        for (int i = 0; i < m; i++)
        {
            izq.push_back(v[i]);
        }
        for (int i = m; i < n; i++)
        {
            der.push_back(v[i]);
        }
        ordenaMerge(izq);
        ordenaMerge(der);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < izq.size() && j < der.size())
        {
            if (izq[i] < der[j])
            {
                v[k] = izq[i];
                i++;
            }
            else
            {
                v[k] = der[j];
                j++;
            }
            k++;
        }
        while (i < izq.size())
        {
            v[k] = izq[i];
            i++;
            k++;
        }
        while (j < der.size())
        {
            v[k] = der[j];
            j++;
            k++;
        }
    }
    return;
}

void ordenaQuick(vector<int> &v)
{
    int n = v.size();
    if (n > 1)
    {
        int pivote = v[0];
        vector<int> izq;
        vector<int> der;
        for (int i = 1; i < n; i++)
        {
            if (v[i] < pivote)
            {
                izq.push_back(v[i]);
            }
            else
            {
                der.push_back(v[i]);
            }
        }
        ordenaQuick(izq);
        ordenaQuick(der);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < izq.size())
        {
            v[k] = izq[i];
            i++;
            k++;
        }
        v[k] = pivote;
        k++;
        while (j < der.size())
        {
            v[k] = der[j];
            j++;
            k++;
        }
    }
}

int busquedaSecuencialOrd(vector<int> &v, int x)
{
    int n = v.size();
    int i = 0;
    while (i < n && v[i] < x)
    {
        i++;
    }
    if (i < n && v[i] == x)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int busquedaBinaria(vector<int> &v, int x)
{
    int n = v.size();
    int i = 0;
    int j = n - 1;
    int m;
    while (i <= j)
    {
        m = (i + j) / 2;
        if (v[m] == x)
        {
            return m;
        }
        else if (v[m] < x)
        {
            i = m + 1;
        }
        else
        {
            j = m - 1;
        }
    }
    return -1;
}

int main()
{
    void (*Ordenamientos[3])(vector<int> &) = {ordenaBurbuja, ordenaMerge, ordenaQuick};
    int (*Busquedas[2])(vector<int> &, int) = {busquedaSecuencialOrd, busquedaBinaria};
    int n;
    int algoritmoOrdenamiento;
    int algoritmoBusqueda;
    int x;
    vector<int> v;
    cin >> n;
    cin >> algoritmoOrdenamiento;
    cin >> algoritmoBusqueda;
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    Ordenamientos[algoritmoOrdenamiento - 1](v);
    int pos = Busquedas[algoritmoBusqueda - 1](v, x);
    cout << pos << endl;
}