/* How to run this program
Enter number of vertices:5
Enter number of edges:5
Enter edges in format: source destination weight
1 3 2
4 3 -1
2 4 1
1 2 1
0 1 5
Enter source vertex:0
Shortest distances from vertex 0: 0 5 6 6 7
*/
//Алгоритм Беллмана-Форда.
#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                if (i == V - 1)
                    return {-1}; // Negative weight cycle detected
                dist[v] = dist[u] + wt;
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
    cout << "Enter edges in format: source destination weight" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> ans = bellmanFord(V, edges, src);

    if (ans.size() == 1 && ans[0] == -1) {
        cout << "Negative weight cycle detected." << endl;
    } else {
        cout << "Shortest distances from vertex " << src << ": ";
        for (int dist : ans)
            cout << dist << " ";
        cout << endl;
    }

    return 0;
}
