#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <unordered_map>
#include "Registro.h"
#include <fstream>

class Bitacora
{
private:
    vector<Registro> bitacora;
    void Sort();
    int BS(time_t fecha);

public:
    Bitacora();
    Bitacora(vector<Registro> bitacora);
    void addRegistro(Registro registro);
    Registro getRegistro(int index);
    Registro operator[](int index);
    vector<Registro> getRango(time_t fechaInicio, time_t fechaFin);
    vector<Registro> getBitacora();
    void saveBitacora(std::string fileName);
};

Bitacora::Bitacora()
{
    this->bitacora = vector<Registro>();
}

Bitacora::Bitacora(vector<Registro> bitacora)
{
    this->bitacora = bitacora;
    this->Sort();
}

vector<Registro> Bitacora::getBitacora()
{
    return this->bitacora;
}

void Bitacora::Sort()
{
    int n = this->bitacora.size();
    if (n > 1)
    {
        int mid = n / 2;
        vector<Registro> left, right;
        for (int i = 0; i < mid; i++)
        {
            left.push_back(this->bitacora[i]);
        }
        for (int i = mid; i < n; i++)
        {
            right.push_back(this->bitacora[i]);
        }
        Bitacora leftBitacora(left);
        Bitacora rightBitacora(right);
        left = leftBitacora.getBitacora();
        right = rightBitacora.getBitacora();
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size())
        {
            if (left[i] < right[j])
            {
                this->bitacora[k] = left[i];
                i++;
            }
            else
            {
                this->bitacora[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < left.size())
        {
            this->bitacora[k] = left[i];
            i++;
            k++;
        }
        while (j < right.size())
        {
            this->bitacora[k] = right[j];
            j++;
            k++;
        }
    }
}

int Bitacora::BS(time_t fecha)
{
    int low = 0, high = this->bitacora.size() - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (this->bitacora[mid] == fecha)
        {
            return mid;
        }
        else
        {
            if (this->bitacora[mid] < fecha)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return low;
}

vector<Registro> Bitacora::getRango(time_t fechaInicio, time_t fechaFin)
{
    if (fechaInicio > fechaFin)
    {
        time_t temp = fechaInicio;
        fechaInicio = fechaFin;
        fechaFin = temp;
    }
    int low = this->BS(fechaInicio);
    int high = this->BS(fechaFin);
    vector<Registro> rango;
    for (int i = low; i < high; i++)
    {
        rango.push_back(this->bitacora[i]);
    }
    return rango;
}

void Bitacora::addRegistro(Registro registro)
{
    int n = this->BS(registro.getTimeStamp());
    this->bitacora.insert(this->bitacora.begin() + n, registro);
}

Registro Bitacora::getRegistro(int index)
{
    return this->bitacora[index];
}

Registro Bitacora::operator[](int index)
{
    return this->bitacora[index];
}

void Bitacora::saveBitacora(std::string fileName)
{
    std::ofstream file(fileName);
    for (int i = 0; i < this->bitacora.size(); i++)
    {
        file << this->bitacora[i].toString() << endl;
    }
    file.close();
}

#endif