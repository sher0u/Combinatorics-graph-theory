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
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

#include <iostream>
#include <list>
using namespace std;

class DepthFirstSearchGraph {
    int totalVertices;
    list<int> *adjacencyLists;
    bool *alreadyVisited;

public:
    DepthFirstSearchGraph(int verticesCount);
    void connectDirected(int fromVertex, int toVertex);
    void exploreFrom(int startVertex);
};

DepthFirstSearchGraph::DepthFirstSearchGraph(int verticesCount) {
    totalVertices = verticesCount;
    adjacencyLists = new list<int>[verticesCount];
    alreadyVisited = new bool[verticesCount];
    for (int index = 0; index < totalVertices; index++)
        alreadyVisited[index] = false;
}

void DepthFirstSearchGraph::connectDirected(int fromVertex, int toVertex) {
    adjacencyLists[fromVertex].push_front(toVertex);
}

void DepthFirstSearchGraph::exploreFrom(int currentVertex) {
    alreadyVisited[currentVertex] = true;
    cout << currentVertex << " ";

    for (int adjacent : adjacencyLists[currentVertex]) {
        if (!alreadyVisited[adjacent]) {
            exploreFrom(adjacent);
        }
    }
}

int main() {
    int numberOfVertices, numberOfConnections;

    cout << "Total vertices (start from 0): ";
    cin >> numberOfVertices;

    DepthFirstSearchGraph dfsGraph(numberOfVertices);

    cout << "How many directed connections (edges)? ";
    cin >> numberOfConnections;

    cout << "Input " << numberOfConnections << " edges as: source destination" << endl;
    cout << "Valid vertex range: [0 to " << numberOfVertices - 1 << "]" << endl;

    for (int edgeIndex = 1; edgeIndex <= numberOfConnections; edgeIndex++) {
        int fromNode, toNode;
        cout << "Connection #" << edgeIndex << ": ";
        cin >> fromNode >> toNode;
        dfsGraph.connectDirected(fromNode, toNode);
    }

    int initialExplorer;
    cout << "Start exploring from vertex: ";
    cin >> initialExplorer;

    dfsGraph.exploreFrom(initialExplorer);

    return 0;
}
