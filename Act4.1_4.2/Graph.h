#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include "LinkedList.h"
#include "QueueLinkedList.h"

class Graph {
  private:
    int numNodes;
    int numEdges;
    // Lista de adyacencia (vector de listas de pares (vertice, peso))
    std::vector<LinkedList<std::pair<int, int>>> adjList;

    void split(std::string line, std::vector<int> &res);
    void loadGraphList(std::istream &input);
    void printAdjList();

  public:
    Graph();
    ~Graph();
    void loadDirWeightedGraph(std::istream & input);
    void print();
    void BFS(int v);
    // To do
    void DFS(int v);
    bool isBipartite();


};




#endif // __GRAPH_H_