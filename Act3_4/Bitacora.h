#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "BinarySearchTree.h"
#include "Registro.h"
#include "PriorityQueue.h"
#include "Node.h"
#include "Registro_Count.h"

class Bitacora
{
private:
    PriorityQueue<Registro> bitacora_pq;
    BinarySearchTree count_ips;
    void ReadEdge(std::string line);
    std::unordered_map<std::string, int> ips;

public:
    Bitacora();
    ~Bitacora();
    void print(std::ostream &out);
    void ReadFile(std::ifstream &file);
    void printTopN(int n, std::ofstream &ips_con_mayor_acceso);
    void printBitacora(std::ofstream &bitacora_ordenada);
};

Bitacora::Bitacora()
{
    // O(1)
}

Bitacora::~Bitacora()
{
    // O(n)
    count_ips.clear();
}

void Bitacora::ReadFile(std::ifstream &file)
{
    // O(n)
    std::string line;
    while (getline(file, line))
    {
        ReadEdge(line);
    }
}

void Bitacora::ReadEdge(std::string line)
{
    // O(1)
    std::string mes, dia, hora, minuto, segundo, ip, puerto, falla;
    std::stringstream ss(line);
    ss >> mes >> dia >> hora >> ip;
    std::getline(ss, falla);

    minuto = hora.substr(hora.find(":") + 1, hora.find(":"));
    segundo = hora.substr(hora.find(":", hora.find(":") + 1) + 1, hora.length());
    hora = hora.substr(0, hora.find(":"));
    puerto = ip.substr(ip.find(":") + 1, ip.length());
    ip = ip.substr(0, ip.find(":"));
    Registro r(mes, dia, hora, minuto, segundo, ip, puerto, falla);
    std::cout << r << std::endl;
    std::cout << "pushing " << std::endl;
    bitacora_pq.push(r);
    std::cout << "pushed " << std::endl;
    std::cout << "finding " << std::endl;

    if (ips.find(r.getIP()) == ips.end())
        std::cout << "new ip" << std::endl;

    ips[r.getIP()]++;

    if (count_ips.find(r))
    {
        std::cout << "found " << std::endl;
        std::cout << "incrementing " << std::endl;
        count_ips.addAt(r);
        std::cout << "incremented " << std::endl;
    }
    else
    {
        std::cout << "not found " << std::endl;
        std::cout << "inserting " << std::endl;
        count_ips.insert(Registro_Count(r));
        std::cout << "inserted " << std::endl;
    }
}

void Bitacora::print(std::ostream &out)
{
    // O(n)
    bitacora_pq.print(out);
}

void Bitacora::printTopN(int n, std::ofstream &ips_con_mayor_acceso)
{
    // O(n)
    Registro_Count Top;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Top " << i + 1 << ": ";
        Top = count_ips.getBiggest();
        std::cout << "aqui" << std::endl;
        std::cout << Top.getRegistro().getIP() << " " << Top.getCount() << std::endl;
        ips_con_mayor_acceso << Top.getRegistro().getIP() << " " << Top.getCount() << std::endl;
        std::cout << "aqui2" << std::endl;
        count_ips.deleteNode(Top);
        std::cout << "aqui3" << std::endl;
    }
}

void Bitacora::printBitacora(std::ofstream &bitacora_ordenada)
{
    // O(n)
    while (!bitacora_pq.empty())
    {
        bitacora_ordenada << bitacora_pq.top() << std::endl;
        bitacora_pq.pop();
    }
}

#endif // _BITACORA_H_
