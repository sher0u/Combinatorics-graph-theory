/*
Enter number of vertices:5
Enter number of edges:5
Enter edges in format: u v weight
0 1 4
0 2 8
1 4 6
2 3 2
3 4 10
Enter source vertex:0
Shortest distances from vertex 0: 0 4 8 10 10
*/
//Алгоритм Дейкстры
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to construct adjacency
vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V) {
    vector<vector<vector<int>>> adj(V);
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return adj;
}

// Returns shortest distances from src to all other vertices
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<vector<int>>> adj = constructAdj(edges, V);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dist(V, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();

        for (auto x : adj[u]) {
            int v = x[0];
            int weight = x[1];

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges;
    cout << "Enter edges in format: u v weight" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> result = dijkstra(V, edges, src);

    cout << "Shortest distances from vertex " << src << ": ";
    for (int dist : result)
        cout << dist << " ";
    cout << endl;

    return 0;
}
