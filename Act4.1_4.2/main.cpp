/** 
* Ejemplo que implementa Grafos ponderados dirigidos representados
* como una Lista de adyacencia y el recorrido BFS
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main < TestCases/graph01.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < TestCases/graph01.txt
**/

#include <iostream>
#include <sstream>
#include "Graph.h"

int main() {
  std::cout << "Ejemplo de grafos ponderados dirigidos y BFS)!\n";
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 
  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph g1;
  g1.loadDirWeightedGraph(inputInfo);
  g1.print();
  // Algoritmo BFS iniciando en el nodo 1 del grafo g1
  g1.BFS(5);
  
  return 0;
} 