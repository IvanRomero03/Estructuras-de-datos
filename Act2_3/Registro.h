#ifndef _Registro_H_
#define _Registro_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <unordered_map>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define vector std::vector
#define unordered_map std::unordered_map
#define stoi std::stoi

class Registro
{
private:
    struct tm timeStruct;
    time_t timeStamp;
    std::string mes, dia, hora, minuto, segundo, ip, puerto, falla;
    unordered_map<std::string, int> meses = {
        {"Jan", 0},
        {"Feb", 1},
        {"Mar", 2},
        {"Apr", 3},
        {"May", 4},
        {"Jun", 5},
        {"Jul", 6},
        {"Aug", 7},
        {"Sep", 8},
        {"Oct", 9},
        {"Nov", 10},
        {"Dec", 11}};

public:
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string minuto, std::string segundo, std::string ip, std::string puerto, std::string falla);
    bool operator<(const Registro &r) const;
    bool operator<(const time_t &r) const;
    bool operator>(const Registro &r) const;
    bool operator>(const time_t &r) const;
    bool operator==(const Registro &r) const;
    bool operator==(const time_t &otro) const;
    bool operator!=(const Registro &r) const;
    bool operator!=(const time_t &r) const;
    bool operator<=(const Registro &r) const;
    bool operator<=(const time_t &r) const;
    bool operator>=(const Registro &r) const;
    bool operator>=(const time_t &r) const;
    time_t getTimeStamp();
    void print();
    std::string toString();
    friend std::ostream &operator<<(std::ostream &os, const Registro &r);
};

Registro::Registro()
{
    this->mes = "0";
    this->dia = "0";
    this->hora = "0";
    this->minuto = "0";
    this->segundo = "0";
    this->ip = "0";
    this->puerto = "0";
    this->falla = "0";
    this->timeStamp = 0;
}

Registro::Registro(std::string mes, std::string dia, std::string hora, std::string minuto, std::string segundo, std::string ip, std::string puerto, std::string falla)
{
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->ip = ip;
    this->puerto = puerto;
    this->falla = falla;
    this->timeStruct.tm_mon = meses[mes];
    this->timeStruct.tm_mday = stoi(dia);
    this->timeStruct.tm_hour = stoi(hora);
    this->timeStruct.tm_min = stoi(minuto);
    this->timeStruct.tm_sec = stoi(segundo);
    this->timeStruct.tm_year = 122;
    this->timeStamp = mktime(&timeStruct);
}
bool Registro::operator==(const Registro &otro) const
{
    return this->timeStamp == otro.timeStamp;
}
bool Registro::operator==(const time_t &otro) const
{
    return this->timeStamp == otro;
}
bool Registro::operator!=(const Registro &otro) const
{
    return this->timeStamp != otro.timeStamp;
}
bool Registro::operator!=(const time_t &otro) const
{
    return this->timeStamp != otro;
}
bool Registro::operator<(const Registro &otro) const
{
    return this->timeStamp < otro.timeStamp;
}
bool Registro::operator<(const time_t &otro) const
{
    return this->timeStamp < otro;
}
bool Registro::operator>(const Registro &otro) const
{
    return this->timeStamp > otro.timeStamp;
}
bool Registro::operator>(const time_t &otro) const
{
    return this->timeStamp > otro;
}
bool Registro::operator<=(const Registro &otro) const
{
    return this->timeStamp <= otro.timeStamp;
}
bool Registro::operator<=(const time_t &otro) const
{
    return this->timeStamp <= otro;
}
bool Registro::operator>=(const Registro &otro) const
{
    return this->timeStamp >= otro.timeStamp;
}
bool Registro::operator>=(const time_t &otro) const
{
    return this->timeStamp >= otro;
}
time_t Registro::getTimeStamp()
{
    return this->timeStamp;
}
void Registro::print()
{
    cout << this->mes << " " << this->dia << " " << this->hora << ":" << this->minuto << ":" << this->segundo << " " << this->ip << ":" << this->puerto << " " << this->falla << endl;
}
std::string Registro::toString()
{
    return this->mes + " " + this->dia + " " + this->hora + ":" + this->minuto + ":" + this->segundo + " " + this->ip + ":" + this->puerto + " " + this->falla;
}
std::ostream &operator<<(std::ostream &os, const Registro &r)
{
    os << r.mes << " " << r.dia << " " << r.hora << ":" << r.minuto << ":" << r.segundo << " " << r.ip << ":" << r.puerto << " " << r.falla;
    return os;
}

#endif