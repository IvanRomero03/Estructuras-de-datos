// g++ main.cpp -o main & .\main < .\TestCases\test0X.txt
//  Iván Alberto Romero Wells A00833623
//  Mariano Barberi Garza A01571226
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Registro.h"
#include "Bitacora.h"

int main()
{
    std::string line;
    time_t first, last;
    getline(cin, line);
    int n = line.find(":");
    std::string mes, dia, hora, minuto, segundo, falla, ip, puerto;
    n = n + 2;
    mes = line.substr(n, 3);
    n = n + 4;
    dia = line.substr(n, 2);
    n += 3;
    hora = line.substr(n, 2);
    n += 3;
    minuto = line.substr(n, 2);
    n += 3;
    segundo = line.substr(n, 2);
    first = Registro(mes, dia, hora, minuto, segundo, "", "", "").getTimeStamp();

    getline(cin, line);
    n = line.find(":");
    n = n + 2;
    mes = line.substr(n, 3);
    n = n + 4;
    dia = line.substr(n, 2);
    n += 3;
    hora = line.substr(n, 2);
    n += 3;
    minuto = line.substr(n, 2);
    n += 3;
    segundo = line.substr(n, 2);

    last = Registro(mes, dia, hora, minuto, segundo, "", "", "").getTimeStamp();
    getline(cin, line);
    getline(cin, line);
    n = line.find(":");
    int lim = line.find(" ", n);
    int N = stoi(line.substr(n + 2, lim - n - 2));
    Bitacora RegistroDeFallas;
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
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
        RegistroDeFallas.addRegistro(Registro(mes, dia, hora, minuto, segundo, ip, puerto, falla));
    }
    vector<Registro> fallas = RegistroDeFallas.getRango(first, last);
    cout << "Rango dado" << endl;
    for (int i = 0; i < fallas.size(); i++)
    {
        fallas[i].print();
    }
    RegistroDeFallas.saveBitacora("bitacora.txt");
    return 0;
}