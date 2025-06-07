/*
Enter number of vertices:5 
Enter number of edges:5
Enter edges (u v) - 0-based indexing:
1 0 
0 2
2 1
0 3
3 4
Bridges in the graph:
3 4
0 3
*/
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
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /*
Enter number of vertices:5
Enter number of edges:5
Enter edges (u v) - 0-based indexing:
1 0
0 2
2 1
0 3
3 4
Bridges in the graph:
3 4
0 3
*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class UndirectedGraph {
    int vertexCount;
    list<int>* adjacencyList;

    void findBridgesDFS(int current, vector<bool>& visited, vector<int>& discoveryTime,
                        vector<int>& lowTime, int parent);

public:
    UndirectedGraph(int vertices);
    void addEdge(int u, int v);
    void findBridges();
};

UndirectedGraph::UndirectedGraph(int vertices) {
    vertexCount = vertices;
    adjacencyList = new list<int>[vertices];
}

void UndirectedGraph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

void UndirectedGraph::findBridgesDFS(int current, vector<bool>& visited, vector<int>& discoveryTime,
                                    vector<int>& lowTime, int parent) {
    static int timeCounter = 0;
    visited[current] = true;
    discoveryTime[current] = lowTime[current] = ++timeCounter;

    for (int neighbor : adjacencyList[current]) {
        if (neighbor == parent)
            continue;

        if (visited[neighbor]) {
            lowTime[current] = min(lowTime[current], discoveryTime[neighbor]);
        } else {
            findBridgesDFS(neighbor, visited, discoveryTime, lowTime, current);
            lowTime[current] = min(lowTime[current], lowTime[neighbor]);
            if (lowTime[neighbor] > discoveryTime[current]) {
                cout << current << " " << neighbor << "\n";
            }
        }
    }
}

void UndirectedGraph::findBridges() {
    vector<bool> visited(vertexCount, false);
    vector<int> discoveryTime(vertexCount, -1);
    vector<int> lowTime(vertexCount, -1);

    for (int i = 0; i < vertexCount; i++) {
        if (!visited[i]) {
            findBridgesDFS(i, visited, discoveryTime, lowTime, -1);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    UndirectedGraph graph(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v) - 0-based indexing:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "\nBridges in the graph:\n";
    graph.findBridges();

    return 0;
}
