#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include "DoublyLinkedList.h"
#include "ListNode.h"
#include "Registro.h"
#include <string>
#include <fstream>
#include <sstream>

class Bitacora
{
private:
    DoublyLinkedList<Registro> *bitacora;
    void ReadEdge(std::string line);

public:
    Bitacora();
    ~Bitacora();
    void print();
    void ReadFile(std::ifstream &file);
    void sort();
    void busquedaRango(Registro start, Registro end, std::ofstream &resultado_busqueda);
};

Bitacora::Bitacora()
{
    bitacora = new DoublyLinkedList<Registro>();
}

Bitacora::~Bitacora()
{
    delete bitacora;
}

void Bitacora::ReadFile(std::ifstream &file)
{
    std::string line;
    while (getline(file, line))
    {
        ReadEdge(line);
    }
}

void Bitacora::ReadEdge(std::string line)
{
    std::string mes, dia, hora, minuto, segundo, ip, puerto, falla;
    std::stringstream ss(line);
    ss >> mes >> dia >> hora >> ip;
    std::getline(ss, falla);
    minuto = hora.substr(3, 2);
    segundo = hora.substr(6, 2);
    hora = hora.substr(0, 2);
    puerto = ip.substr(ip.find(":") + 1, ip.length());
    ip = ip.substr(0, ip.find(":"));
    Registro r(mes, dia, hora, minuto, segundo, ip, puerto, falla);
    bitacora->addLast(r);
}

void Bitacora::print()
{
    bitacora->print();
}

void Bitacora::sort()
{
    bitacora->sort();
}

void Bitacora::busquedaRango(Registro start, Registro end, std::ofstream &resultado_busqueda)
{
    DoublyLinkedList<Registro> rango = bitacora->getRange(start, end);
    rango.print();
    ListNode<Registro> *current = rango.getHead();
    while (current != nullptr)
    {
        resultado_busqueda << current << std::endl;
        current++;
    }
    if (rango.getHead()->getData() != start)
    {
        resultado_busqueda << "No se encontro el primer registro en el rango especificado" << std::endl;
    }
    if (rango.getTail()->getData() != end)
    {
        resultado_busqueda << "No se encontro el ultimo registro en el rango especificado" << std::endl;
    }
}

#endif // _BITACORA_H_