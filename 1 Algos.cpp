/*
Enter the number of vertices (indexed from 0):5
Enter the number of edges:5
Enter 5 edges in the format: src dest
Note: vertices must be in the range [0, 4]
Edge 1:1 2
Edge 2:1 0
Edge 3:2 0
Edge 4:2 3
Edge 5:2 4
Enter the starting vertex for DFS (0 to 4):1
1 0 2 4 3
*/

//Алгоритм поиска в глубину
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

    if (V <= 0) {
        cout << "The number of vertices must be greater than 0." << endl;
        return 1;
    }

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter " << E << " edges in the format: src dest" << endl;
    cout << "Note: vertices must be in the range [0, " << V - 1 << "]" << endl;

    for (int i = 0; i < E; i++) {
        int src, dest;
        cout << "Edge " << i + 1 << ": ";
        cin >> src >> dest;
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            cout << "Invalid edge. Vertices must be in range [0, " << V - 1 << "]." << endl;
            i--; // repeat the same edge input
            continue;
        }
        g.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS (0 to " << V - 1 << "): ";
    cin >> startVertex;

    if (startVertex < 0 || startVertex >= V) {
        cout << "Invalid starting vertex." << endl;
        return 1;
    }

    g.DFS(startVertex);
    cout << endl;

    return 0;
}
