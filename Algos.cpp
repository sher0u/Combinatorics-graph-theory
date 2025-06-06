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

-------------------------------------------------------------------------------------------------
  // C++ program for Breadth-first-traversal

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define a class named Graph to represent the graph
// structure.
class Graph {
    // Number of vertices in the graph.
    int V;
    // Adjacency list representation of the graph.
    vector<vector<int>> adjList;

public:
    // Constructor for initializing the graph with a given
    // number of vertex
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(vertices);
    }

    // Function for adding an edge to the graph.
    void addEdge(int src, int dest)
    {
        // Add destination vertex to source vertex's list.
        adjList[src].push_back(dest);
        // Add source vertex to destination vertex's list
        // (for undirected graph).
        adjList[dest].push_back(src);
    }

    // Function to perform Breadth-First Traversal (BFS)
    // starting from a given vertex.
    void bfs(int startVertex)
    {
        // Vector to keep track of visited vertices.
        vector<bool> visited(V, false);
        // Queue to help with the BFS traversal.
        queue<int> q;
        // Mark the start vertex as visited.
        visited[startVertex] = true;
        // Enqueue the start vertex.
        q.push(startVertex);

        while (!q.empty()) {
            // point currentVertex at front vertex from the queue.
            int currentVertex = q.front();
            // Print the current vertex.
            cout << currentVertex << " ";
            // Remove the front vertex from the queue.
            q.pop();

            // Iterate through all the neighbors of the
            // current vertex.
            for (int neighbor : adjList[currentVertex]) {
                // If the neighbor vertex has not been
                // visited yet.
                if (!visited[neighbor]) {
                    // Mark the neighbor vertex as visited.
                    visited[neighbor] = true;
                    // Enqueue the neighbor vertex.
                    q.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges in the format: src dest\n";
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "Breadth-First Traversal (starting from vertex " << startVertex << "):\n";
    g.bfs(startVertex);

    return 0;
}

-------------------------------------------------------------------------------------------------
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
-------------------------------------------------------------------------------------------------
