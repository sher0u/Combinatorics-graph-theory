/*
Enter number of vertices:5
Enter number of edges:3
Enter edges (u v) with 0-based indexing:
0 1 
1 2
3 4
Connected components:
0 1 2
3 4
*/
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
