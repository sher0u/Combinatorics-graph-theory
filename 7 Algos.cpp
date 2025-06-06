/*
Enter number of vertices:5
Enter number of edges:6
Enter edges (format: from to) each in a new line:
0 1
1 2
2 3
3 0
2 4
4 2
Yes
*/
// Алгоритм Косарайю
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V;
    list<int>* adj;

    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph() { delete[] adj; }

    void addEdge(int v, int w);
    bool isSC();
    Graph getTranspose();
};

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++) {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isSC()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(0, visited);

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;

    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
        visited[i] = false;

    gr.DFSUtil(0, visited);

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;

    return true;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);
    cout << "Enter edges (format: from to) each in a new line:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.isSC() ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
