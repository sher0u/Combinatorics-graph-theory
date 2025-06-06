//4 Алгоритм Форда-Фалкерсона для поиска 
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
