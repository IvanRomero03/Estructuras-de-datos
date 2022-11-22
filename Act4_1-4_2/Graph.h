#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <fstream>
#include <queue>

class Graph
{
private:
    int numNodes;
    int numEdges;
    std::vector<std::vector<std::pair<int, int>>> adjList;
    void split(std::string line, std::vector<int> &res);
    void loadGraphList(std::istream &input);
    void DFS_helper(int v, std::vector<bool> &visited);
    bool isBipartite_helper(int v, std::vector<bool> &visited, std::vector<bool> &color);

public:
    Graph();
    ~Graph();
    void loadDirWeightedGraph(std::istream &input);
    void print(std::ostream &output);
    void BFS(int v);
    void DFS(int v);
    bool isBipartite();
};

Graph::Graph()
{
    //O(1)
    numNodes = 0;
    numEdges = 0;
}

Graph::~Graph()
{
    //O(n)
    for (auto &v : adjList)
    {
        v.clear();
    }
    adjList.clear();
}

void Graph::split(std::string line, std::vector<int> &res)
{
    //O(n)
    int v, w, weight;

    v = std::stoi(line.substr(0, line.find(" ")));
    line = line.substr(line.find(" ") + 1);

    w = std::stoi(line.substr(0, line.find(" ")));
    line = line.substr(line.find(" ") + 1);

    if (line.size() > 0)
    {
        weight = std::stoi(line);
    }
    else
    {
        weight = 1;
    }

    res.push_back(v);
    res.push_back(w);
    res.push_back(weight);
}

void Graph::loadGraphList(std::istream &input)
{
    //O(n)
    std::string line;
    std::vector<int> res;
    while (std::getline(input, line))
    {
        split(line, res);
        adjList[res[0]].push_back(std::make_pair(res[1], res[2]));
        res.clear();
    }
}

void Graph::loadDirWeightedGraph(std::istream &input)
{
    //O(n)
    std::string line;
    std::vector<int> res;

    std::getline(input, line);

    std::getline(input, line);
    this->numNodes = std::stoi(line.substr(0, line.find(" "))) + 1;
    line = line.substr(line.find(" ") + 1);
    line = line.substr(line.find(" ") + 1);
    this->numEdges = std::stoi(line.substr(0, line.find(" ")));
    this->adjList.resize(numNodes);
    loadGraphList(input);
}

void Graph::print(std::ostream &output = std::cout)
{
    //O(n)
    for (int i = 1; i < numNodes; i++)
    {
        output << i << ": ";
        for (int j = 0; j < (int)adjList[i].size(); j++)
        {
            output << adjList[i][j].first << "(" << adjList[i][j].second << ") ";
        }
        output << std::endl;
    }
}

void Graph::DFS(int v)
{
    //O(n)
    std::vector<bool> visited(numNodes, false);
    DFS_helper(v, visited);
    std::cout << std::endl;
}

void Graph::DFS_helper(int v, std::vector<bool> &visited)
{
    //O(n)
    visited[v] = true;
    std::cout << v << " ";
    for (auto i : adjList[v])
    {
        if (!visited[i.first])
        {
            DFS_helper(i.first, visited);
        }
    }
}

void Graph::BFS(int v)
{
    //O(n)
    std::vector<bool> visited(numNodes, false);
    std::queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        std::cout << u << " ";
        for (auto i : adjList[u])
        {
            if (!visited[i.first])
            {
                q.push(i.first);
                visited[i.first] = true;
            }
        }
    }
    std::cout << std::endl;
}

bool Graph::isBipartite()
{
    //O(n)
    std::vector<bool> visited(numNodes, false);
    std::vector<bool> color(numNodes, false);
    for (int i = 1; i < numNodes; i++)
    {
        if (!visited[i])
        {
            if (!isBipartite_helper(i, visited, color))
            {
                return false;
            }
        }
    }
    return true;
}

bool Graph::isBipartite_helper(int v, std::vector<bool> &visited, std::vector<bool> &color)
{
    //O(n)
    visited[v] = true;
    for (auto i : adjList[v])
    {
        if (!visited[i.first])
        {
            color[i.first] = !color[v];
            if (!isBipartite_helper(i.first, visited, color))
            {
                return false;
            }
        }
        else if (color[i.first] == color[v])
        {
            return false;
        }
    }
    return true;
}

#endif // __GRAPH_H_