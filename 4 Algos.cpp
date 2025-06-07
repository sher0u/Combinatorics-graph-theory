/*
Enter number of vertices:6
Enter number of edges:10
Enter edges in the format: from to capacity (1-based indices):
Edge 1:1 2 16
Edge 2:1 3 13
Edge 3:2 3 10
Edge 4:3 2 4
Edge 5:2 4 12
Edge 6:4 3 9
Edge 7:3 5 14
Edge 8:5 4 7
Edge 9:4 6 20
Edge 10:5 6 4
Enter source vertex (1-based):1
Enter sink vertex (1-based):6
Maximum Flow: 23
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <set>
#include <limits>

using namespace std;

class FlowNetwork {
public:
    int V;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;

    FlowNetwork(int vertices) {
        V = vertices;
        capacity.assign(V, vector<int>(V, 0));
        adj.resize(V);
    }

    void addEdge(int u, int v, int cap) {
        if (capacity[u][v] == 0 && capacity[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u); // Residual edge
        }
        capacity[u][v] += cap; // Handles parallel edges
    }
};

// Safely reads an integer, returns false if invalid
bool readInt(int &value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

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

    cout << "Enter number of vertices: ";
    if (!readInt(V) || V < 2) {
        cout << "Error: number of vertices must be >= 2.\n";
        return 1;
    }

    cout << "Enter number of edges: ";
    if (!readInt(E) || E < 0) {
        cout << "Error: number of edges must be non-negative.\n";
        return 1;
    }

    FlowNetwork network(V);
    set<pair<int, int>> existingEdges;

    cout << "\nEnter edges in the format: from to capacity (1-based indices):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, cap;

        while (true) {
            cout << "Edge " << i + 1 << ": ";
            if (!readInt(u) || !readInt(v) || !readInt(cap)) {
                cout << "Invalid input. Please enter three integers.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            u--; v--; // Convert to 0-based

            if (u < 0 || u >= V || v < 0 || v >= V) {
                cout << "Error: vertex index out of range. Must be 1 to " << V << ".\n";
                continue;
            }

            if (u == v) {
                cout << "Error: self-loop is not allowed.\n";
                continue;
            }

            if (cap <= 0) {
                cout << "Error: capacity must be a positive integer.\n";
                continue;
            }

            if (existingEdges.count({u, v})) {
                cout << "Error: duplicate edge from " << u + 1 << " to " << v + 1 << ".\n";
                continue;
            }

            existingEdges.insert({u, v});
            network.addEdge(u, v, cap);
            break;
        }
    }

    int source, sink;
    cout << "\nEnter source vertex (1-based): ";
    if (!readInt(source)) {
        cout << "Invalid source input.\n";
        return 1;
    }

    cout << "Enter sink vertex (1-based): ";
    if (!readInt(sink)) {
        cout << "Invalid sink input.\n";
        return 1;
    }

    source--; sink--;

    if (source < 0 || source >= V || sink < 0 || sink >= V || source == sink) {
        cout << "Error: source and sink must be distinct and within range 1 to " << V << ".\n";
        return 1;
    }

    int maxFlow = edmondsKarp(network, source, sink);
    cout << "\nMaximum Flow: " << maxFlow << endl;

    return 0;
}
