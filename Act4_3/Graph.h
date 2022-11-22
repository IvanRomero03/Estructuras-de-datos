#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "PriorityQueue.h"
#include "Ip_Value.h"

class Graph
{
private:
    int numNodes;
    int numEdges;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph;
    std::unordered_set<std::string> nodes;
    std::vector<Ip_Value> adjNum;
    std::unordered_map<std::string, int> minCaminos;

    void readNodes(std::istream &in, int n);
    void readEdges(std::istream &in, int m);
    std::string bootMaster;

public:
    Graph();
    ~Graph();
    void readGraph(std::istream &in);
    void printGraph(std::ostream &out);
    void countGraph(std::ostream &out);
    void getTopN(int n, std::ostream &out);
    std::string getBootMaster();
    void getMinCaminos(std::string ipOrigen);
    void printMinCaminos(std::ostream &out);
};

Graph::Graph()
{
    numNodes = 0;
    numEdges = 0;
}

Graph::~Graph()
{
    graph.clear();
    nodes.clear();
}

void Graph::readNodes(std::istream &in, int n)
{
    std::string node;
    for (int i = 0; i < n; i++)
    {
        in >> node;
        nodes.insert(node);
    }
}

void Graph::readEdges(std::istream &in, int m)
{
    std::string mes, dia, hora, origen, destino, peso, type;
    std::string originIp, destIp;

    for (int i = 0; i < m; i++)
    {
        in >> mes >> dia >> hora >> origen >> destino >> peso;
        std::getline(in, type);
        originIp = origen.substr(0, origen.find(":"));
        destIp = destino.substr(0, destino.find(":"));
        graph[originIp].push_back(std::make_pair(destIp, std::stoi(peso)));
    }
}

void Graph::readGraph(std::istream &in)
{
    in >> numNodes >> numEdges;
    readNodes(in, numNodes);
    readEdges(in, numEdges);
}

void Graph::printGraph(std::ostream &out)
{
    for (auto i : nodes)
    {
        out << i << " -> ";
        for (auto j : graph[i])
        {
            out << j.first << " (" << j.second << ") ";
        }
        out << std::endl;
    }
    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        out << it->first << " -> ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            out << it2->first << " (" << it2->second << ") ";
        }
        out << std::endl;
    }
}

void Graph::countGraph(std::ostream &out)
{
    for (auto i : nodes)
    {
        adjNum.push_back(Ip_Value(i, graph[i].size()));
        out << i << " " << graph[i].size() << std::endl;
    }
}

void Graph::getTopN(int n, std::ostream &out)
{
    PriorityQueue<Ip_Value> pq(adjNum);
    bootMaster = pq.top().getIp();
    for (int i = 0; i < n; i++)
    {
        out << pq.top().getIp() << " " << pq.top().getValue() << std::endl;
        pq.pop();
    }
}

std::string Graph::getBootMaster()
{
    return bootMaster;
}

void Graph::getMinCaminos(std::string ipOrigen)
{
    PriorityQueue<std::pair<int, std::string>> pq(false);
    std::unordered_map<std::string, bool> visitados;
    std::unordered_map<std::string, int> distancias;

    visitados[ipOrigen] = true;
    distancias[ipOrigen] = 0;
    pq.push(std::make_pair(0, ipOrigen));
    while (!pq.empty())
    {
        for (auto i : graph[pq.top().second])
        {
            if (visitados.find(i.first) == visitados.end())
            {
                visitados[i.first] = true;
                distancias[i.first] = distancias[pq.top().second] + i.second;
                minCaminos[i.first] = distancias[i.first];
                pq.push(std::make_pair(distancias[i.first], i.first));
            }
            else if (distancias[i.first] > distancias[pq.top().second] + i.second)
            {
                distancias[i.first] = distancias[pq.top().second] + i.second;
                minCaminos[i.first] = distancias[i.first];
                pq.push(std::make_pair(distancias[i.first], i.first));
            }
        }
        pq.pop();
    }
}

void Graph::printMinCaminos(std::ostream &out)
{
    for (auto i : minCaminos)
    {
        out << i.first << " " << i.second << std::endl;
    }
}

#endif /* _GRAPH_H_ */