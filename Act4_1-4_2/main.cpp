/*
    Iván Alberto Romero Wells - A00833623
    Mariano Barberi iopaP - A

    Compilación:
        g++ -std=c++17 -Wall -o main *.cpp

    Ejecución:
        main < TestCases\test0X.txt > out0X.txt

*/

#include <iostream>
#include "Graph.h"
#include <sstream>

int main()
{
    std::stringstream in;
    in << std::cin.rdbuf();
    Graph g;
    g.loadDirWeightedGraph(in);

    std::cout << "Recorrido DFS: " << std::endl;
    g.DFS(5);
    std::cout << "Recorrido BFS: " << std::endl;
    g.BFS(5);
    std::cout << "Grafo Bipartita: " << std::boolalpha << g.isBipartite() << std::endl;
    return 0;
}