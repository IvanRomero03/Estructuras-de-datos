#include "Graph.h"

Graph::Graph() {
  numNodes = 0;
  numEdges = 0;
  adjList.clear();
}

Graph::~Graph() {
  adjList.clear();
}

void Graph::split(std::string line, std::vector<int> & res) {
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
      lastPos = strPos + 1;
      strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::loadDirWeightedGraph(std::istream & input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) {
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> result;
      split(line, result);
      numNodes = result[0];
      numEdges = result[2];
      // Reservar la memoria para los renglones de la lista de adyacencia
      // Nodos son cero basados (renglon 0 no sera utilizado)
      adjList.resize(numNodes + 1);
      // Declarar un lista vacia de pares (vertice, peso) 
      // para cada renglon y se almacena en el vector
      for (int k = 1; k <= numNodes; k++) {
        LinkedList<std::pair<int,int>> tmpList;
        adjList[k] = tmpList;
      }
      i++;
      continue;
    }
    // Lectura de aristas del grafo
    std::vector<int> result;
    split(line, result);
    int nodoU = result[0];
    int nodoV = result[1];
    int peso = result[2];
    // grafo dirigido se agrega solo la arista (u,v)
    adjList[nodoU].addLast(std::make_pair(nodoV, peso));    
    i++;
  }
}


void Graph::print(){
  std::cout << "Adjacency List" << std::endl;
  for (int nodeU = 1; nodeU <= numNodes; nodeU++){
      std::cout << "vertex " << nodeU << ": ";
      LLNode<std::pair<int,int>> *ptr = adjList[nodeU].getHead();
      while (ptr != nullptr) {
        std::pair<int, int> par = ptr->data;
        std::cout << "{"<< par.first << "," << par.second << "}  ";
        ptr = ptr->next;
      }
      std::cout << std::endl;  
  }
}


void Graph::BFS(int u) {
  // Declaramos un set del STL de C++ (elementos unicos y ordenados)
  std::set<int> visited;
  // Creamos una queue 
  QueueLinkedList<int> queue;
  // Marcamos el vertice actual u como visitado y entra al queue
  visited.insert(u);
  queue.enqueue(u);
  std::cout << "Recorrido BFS " << std::endl;
  while(!queue.isEmpty()) {
    // Extraemos un vertice del queue y lo procesamos (print) 
    u = queue.dequeue();  
    std::cout << u << " ";
    // Obtenemos los vertices adyacentes del vertice u
    // Si estos no han sido visitados entonces se marcan como visitados
    // y los metemos al queue
    LLNode<std::pair<int,int>> *ptr = adjList[u].getHead();
    while (ptr != nullptr) {
      std::pair<int, int> par = ptr->data;
      int v = par.first;
      // Verifica si v ya fue visitado en tiempo O(log n)
      bool isInVisited = visited.find(v) != visited.end();
      if (!isInVisited) {
        visited.insert(v);
        queue.enqueue(v);
      }
      ptr = ptr->next;
    }
  }
  std::cout << std::endl;
}
