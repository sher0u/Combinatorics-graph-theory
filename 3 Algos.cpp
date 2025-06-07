/*
Enter the number of vertices:6
Enter the number of edges:6
Enter edges in the format: src dest
Edge 1:2 3 
Edge 2:3 1
Edge 3:4 0
Edge 4:4 1
Edge 5:5 0
Edge 6:5 2
Topological Sort of the given graph:
5 4 2 3 1 0
*/
//3Алгоритм топологической сортировки
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;

    for (int neighbor : adj[v]) {
        if (!visited[neighbor])
            topologicalSortUtil(neighbor, visited, Stack);
    }

    Stack.push(v);
}

void Graph::topologicalSort() {
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack);

    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges in the format: src dest\n";
    cout << "(Note: vertices should be from 0 to " << V-1 << ")\n";
    for (int i = 0; i < E; i++) {
        int src, dest;
        cout << "Edge " << i + 1 << ": ";
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    cout << "Topological Sort of the given graph:\n";
    g.topologicalSort();

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
    /*
Enter the number of vertices:6
Enter the number of edges:6
Enter edges in the format: src dest
Edge 1:2 3
Edge 2:3 1
Edge 3:4 0
Edge 4:4 1
Edge 5:5 0
Edge 6:5 2
Topological Sort of the given graph:
5 4 2 3 1 0
*/

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class TopologicalSortGraph {
    int totalVertices;
    list<int> *outgoingEdges;

    void exploreAndStack(int currentVertex, bool visited[], stack<int> &ordering);

public:
    TopologicalSortGraph(int verticesCount);
    void connectDirected(int fromVertex, int toVertex);
    void computeTopologicalOrdering();
};

TopologicalSortGraph::TopologicalSortGraph(int verticesCount) {
    totalVertices = verticesCount;
    outgoingEdges = new list<int>[verticesCount];
}

void TopologicalSortGraph::connectDirected(int fromVertex, int toVertex) {
    outgoingEdges[fromVertex].push_back(toVertex);
}

void TopologicalSortGraph::exploreAndStack(int currentVertex, bool visited[], stack<int> &ordering) {
    visited[currentVertex] = true;

    for (int next : outgoingEdges[currentVertex]) {
        if (!visited[next]) {
            exploreAndStack(next, visited, ordering);
        }
    }

    ordering.push(currentVertex);
}

void TopologicalSortGraph::computeTopologicalOrdering() {
    stack<int> ordering;
    bool *visited = new bool[totalVertices];

    for (int i = 0; i < totalVertices; i++)
        visited[i] = false;

    for (int vertex = 0; vertex < totalVertices; vertex++) {
        if (!visited[vertex]) {
            exploreAndStack(vertex, visited, ordering);
        }
    }

    while (!ordering.empty()) {
        cout << ordering.top() << " ";
        ordering.pop();
    }

    delete[] visited;
}

int main() {
    int vertexCount, edgeCount;
    cout << "Enter the number of vertices: ";
    cin >> vertexCount;

    TopologicalSortGraph topoGraph(vertexCount);

    cout << "Enter the number of edges: ";
    cin >> edgeCount;

    cout << "Enter edges in the format: src dest\n";
    cout << "(Note: vertices should be from 0 to " << vertexCount - 1 << ")\n";

    for (int i = 0; i < edgeCount; i++) {
        int from, to;
        cout << "Edge " << i + 1 << ": ";
        cin >> from >> to;
        topoGraph.connectDirected(from, to);
    }

    cout << "Topological Sort of the given graph:\n";
    topoGraph.computeTopologicalOrdering();

    return 0;
}
