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
  // Алгоритм поиска в ширину

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
Алгоритм топологической сортировки
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
//Алгоритм Форда-Фалкерсона для поиска 
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <set>

using namespace std;

class FlowNetwork {
public:
    int V; // Number of vertices
    vector<vector<int>> capacity; // Capacity matrix
    vector<vector<int>> adj; // Adjacency list

    FlowNetwork(int vertices) {
        V = vertices;
        capacity.assign(V, vector<int>(V, 0));
        adj.resize(V);
    }

    void addEdge(int u, int v, int cap) {
        if (capacity[u][v] == 0 && capacity[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u); // Add reverse edge for residual graph
        }
        capacity[u][v] += cap; // In case of parallel edges
    }
};

int bfs(FlowNetwork &network, int s, int t, vector<int> &parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, numeric_limits<int>::max()});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v : network.adj[u]) {
            if (parent[v] == -1 && network.capacity[u][v] > 0) {
                parent[v] = u;
                int new_flow = min(flow, network.capacity[u][v]);
                if (v == t)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int edmondsKarp(FlowNetwork &network, int source, int sink) {
    int flow = 0;
    vector<int> parent(network.V);
    int new_flow;

    while ((new_flow = bfs(network, source, sink, parent))) {
        flow += new_flow;
        int v = sink;
        while (v != source) {
            int u = parent[v];
            network.capacity[u][v] -= new_flow;
            network.capacity[v][u] += new_flow;
            v = u;
        }
    }

    return flow;
}

int main() {
    int V, E;
    cout << "Enter number of vertices:";
    cin >> V;

    if (V <= 1) {
        cout << "Number of vertices must be > 1. Exiting.\n";
        return 1;
    }

    cout << "Enter number of edges:";
    cin >> E;

    if (E < 0) {
        cout << "Number of edges cannot be negative. Exiting.\n";
        return 1;
    }

    FlowNetwork network(V);
    set<pair<int, int>> existingEdges;

    cout << "\nEnter edges in the format: from to capacity (1-based indices):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, cap;
        cout << "Edge " << i + 1 << ":";
        cin >> u >> v >> cap;

        u--; v--; // Convert to 0-based

        if (u == v || u < 0 || u >= V || v < 0 || v >= V || cap <= 0) {
            cout << "Invalid edge. Try again.\n";
            i--;
            continue;
        }

        if (existingEdges.count({u, v})) {
            cout << "Edge already exists. Try again.\n";
            i--;
            continue;
        }

        existingEdges.insert({u, v});
        network.addEdge(u, v, cap);
    }

    int source, sink;
    cout << "\nEnter source vertex (1-based):";
    cin >> source;
    cout << "Enter sink vertex (1-based):";
    cin >> sink;
    source--; sink--;

    if (source == sink || source < 0 || sink < 0 || source >= V || sink >= V) {
        cout << "Invalid source or sink.\n";
        return 1;
    }

    int maxFlow = edmondsKarp(network, source, sink);
    cout << "\nMaximum Flow: " << maxFlow << endl;

    return 0;
}
-------------------------------------------------------------------------------------------------
//Алгоритм нахождения всех мостов графа.
#include<bits/stdc++.h>
using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    void bridge();    // prints all bridges
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent)
{
    // A static variable is used for simplicity, we can 
    // avoid use of static variable by passing a pointer.
    static int time = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
          
          // 1. If v is parent 
          if(v==parent)
            continue;
      
          //2. If v is visited
          if(visited[v]){
          low[u]  = min(low[u], disc[v]);
        }
      
          //3. If v is not visited
          else{
          parent = u;
          bridgeUtil(v, visited, disc, low, parent);
  
          // update the low of u as it's quite possible 
          // a connection exists from v's descendants to u
          low[u]  = min(low[u], low[v]);
          
          // if the lowest possible time to reach vertex v
          // is greater than discovery time of u it means 
          // that v can be only be reached by vertex above v
          // so if that edge is removed v can't be reached so it's a bridge
          if (low[v] > disc[u])
              cout << u <<" " << v << endl;
          
        }
    }
}

// DFS based function to find all bridges. It uses recursive 
// function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited disc and low as -1
    vector<bool> visited (V,false);
    vector<int> disc (V,-1);
      vector<int> low (V,-1);
    
      // Initially there is no parent so let it be -1
      int parent = -1;

    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

// Driver program to test above function
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v) - 0-based indexing:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nBridges in the graph:\n";
    g.bridge();

    return 0;
}

-------------------------------------------------------------------------------------------------
// Алгоритм поиска компонент связности
#include <iostream>
#include <vector>
using namespace std;

// Function to build the adjacency list from edge list
vector<vector<int>> buildGraph(int V, vector<vector<int>>& edges) {
    
    vector<vector<int>> adj(V);

    // Populate the adjacency list from the edge list
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        // Add both directions since the graph is undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

// Function to perform DFS and collect all
// nodes in the current connected component
void dfs(int node, vector<vector<int>>& adj,
         vector<bool>& vis, vector<int>& component) {
    
    // Mark the current node as visited
    vis[node] = true;

    // Add the node to the current component
    component.push_back(node);

    // Traverse all unvisited neighbors
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis, component);
        }
    }
}

// Function to find all connected components 
// in an undirected graph
vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    
    // Create the graph using the adjacency list
    vector<vector<int>> adj = buildGraph(V, edges);

    // Initialize a visited array to keep track of visited nodes
    vector<bool> vis(V, false);

    // This will store all the connected components
    vector<vector<int>> res;

    // Iterate through all nodes
    for (int i = 0; i < V; ++i) {
        // If the node has not been visited, it's a new component
        if (!vis[i]) {
            
            vector<int> component;

            // Perform DFS to collect all nodes in this component
            dfs(i, adj, vis, component);

            // Add the component to the result list
            res.push_back(component);
        }
    }

    // Return the list of all connected components
    return res;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter edges (u v) with 0-based indexing:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> res = getComponents(V, edges);

    cout << "Connected components:\n";
    for (const auto& comp : res) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
