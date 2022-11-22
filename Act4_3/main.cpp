/*
    Iván Alberto Romero Wells - A00833623
    Mariano Barberi Garza - A01571226

    Compilación:
        g++ -std=c++17 -Wall -o main *.cpp

    Ejecución:
        main < TestCases\test0X.txt > out0X.txt

*/

#include <iostream>
#include "Graph.h"
#include <sstream>
#include <fstream>

int main()
{
    std::ifstream in("bitacoraGrafos.txt");
    Graph g;
    // std::ofstream out("out.txt");
    std::ofstream out2("grados_ips.txt");
    std::ofstream out3("mayores_grados_ips.txt");
    g.readGraph(in);
    // g.printGraph(out);
    g.countGraph(out2);
    g.getTopN(3, out3);
    // out.close();
    out2.close();
    out3.close();
    in.close();
    return 0;
}