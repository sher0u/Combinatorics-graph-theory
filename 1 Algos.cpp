//1Алгоритм поиска в глубину
#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

// Graph initialization
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
}

// Adding edges
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

// Depth-First Search algorithm
void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (indexed from 0): ";
    cin >> V;
    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter " << E << " edges in the format: src dest" << endl;
    cout << "Note: vertices must be in the range [0, " << V - 1 << "]" << endl;

    for (int i = 0; i < E; i++) {
        int src, dest;
        cout << "Edge " << i + 1 << ": ";
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS (0 to " << V - 1 << "): ";
    cin >> startVertex;

    g.DFS(startVertex);

    return 0;
}
