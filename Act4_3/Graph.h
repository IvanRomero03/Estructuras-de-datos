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

    void readNodes(std::istream &in, int n);
    void readEdges(std::istream &in, int m);

public:
    Graph();
    ~Graph();
    void readGraph(std::istream &in);
    void printGraph(std::ostream &out);
    void countGraph(std::ostream &out);
    void getTopN(int n, std::ostream &out);
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
        //warning
        adjNum.push_back(Ip_Value(i, graph[i].size()));
        out << i << " " << graph[i].size() << std::endl;
    }
}

void Graph::getTopN(int n, std::ostream &out)
{
    PriorityQueue<Ip_Value> pq(adjNum);
    for (int i = 0; i < n; i++)
    {
        out << pq.top().ip << " " << pq.top().value << std::endl;
        pq.pop();
    }
}

#endif /* _GRAPH_H_ */