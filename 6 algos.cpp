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
// Алгоритм поиска компонент связности
// Algorithm for finding connected components

#include <iostream>
#include <vector>
using namespace std;

// Функция построения списка смежности из списка рёбер
// Function to build the adjacency list from edge list
vector<vector<int>> buildGraph(int V, vector<vector<int>>& edges) {
    
    vector<vector<int>> adj(V);

    // Заполняем список смежности по рёбрам
    // Populate the adjacency list from the edge list
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        // Добавляем оба направления, так как граф неориентированный
        // Add both directions since the graph is undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

// Обход графа в глубину для поиска всех вершин текущей компоненты
// Function to perform DFS and collect all nodes in the current connected component
void dfs(int node, vector<vector<int>>& adj,
         vector<bool>& vis, vector<int>& component) {
    
    // Отмечаем текущую вершину как посещённую
    // Mark the current node as visited
    vis[node] = true;

    // Добавляем вершину в текущую компоненту
    // Add the node to the current component
    component.push_back(node);

    // Обходим всех непосещённых соседей
    // Traverse all unvisited neighbors
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis, component);
        }
    }
}

// Функция нахождения всех компонент связности в неориентированном графе
// Function to find all connected components in an undirected graph
vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    
    // Создаём граф в виде списка смежности
    // Create the graph using the adjacency list
    vector<vector<int>> adj = buildGraph(V, edges);

    // Массив для отслеживания посещённых вершин
    // Initialize a visited array to keep track of visited nodes
    vector<bool> vis(V, false);

    // Список для хранения всех компонент связности
    // This will store all the connected components
    vector<vector<int>> res;

    // Проходим по всем вершинам
    // Iterate through all nodes
    for (int i = 0; i < V; ++i) {
        // Если вершина не посещена — найдена новая компонента
        // If the node has not been visited, it's a new component
        if (!vis[i]) {
            
            vector<int> component;

            // Запускаем DFS для сбора всех вершин этой компоненты
            // Perform DFS to collect all nodes in this component
            dfs(i, adj, vis, component);

            // Добавляем компоненту в список результатов
            // Add the component to the result list
            res.push_back(component);
        }
    }

    // Возвращаем список всех компонент связности
    // Return the list of all connected components
    return res;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    // Ввод количества вершин
    cin >> V;
    cout << "Enter number of edges: ";
    // Ввод количества рёбер
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter edges (u v) with 0-based indexing:\n";
    // Ввод рёбер графа
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Получаем компоненты связности
    vector<vector<int>> res = getComponents(V, edges);

    cout << "Connected components:\n";
    // Выводим компоненты связности
    for (const auto& comp : res) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
