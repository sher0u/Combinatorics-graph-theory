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
// Алгоритм Дейкстры / Dijkstra's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Функция для построения списка смежности / Function to construct adjacency list
vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V) {
    vector<vector<vector<int>>> adj(V);
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt}); // Добавляем ребро u -> v с весом wt / Add edge u -> v with weight wt
        adj[v].push_back({u, wt}); // Добавляем ребро v -> u с весом wt (т.к. граф неориентированный) / Add edge v -> u (undirected graph)
    }
    return adj;
}

// Возвращает кратчайшие расстояния от вершины src до всех остальных / Returns shortest distances from src to all other vertices
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<vector<int>>> adj = constructAdj(edges, V); // Создаём список смежности / Create adjacency list

    // Очередь с приоритетом (минимальная по расстоянию) / Min-heap priority queue
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    // Инициализируем расстояния как бесконечность / Initialize distances as infinity
    vector<int> dist(V, INT_MAX);

    // Начинаем с исходной вершины / Start from source vertex
    pq.push({0, src});
    dist[src] = 0;

    // Основной цикл Дейкстры / Dijkstra's main loop
    while (!pq.empty()) {
        int u = pq.top()[1]; // Текущая вершина / Current vertex
        pq.pop();

        // Проходим по всем соседям вершины u / Iterate over all neighbors of u
        for (auto x : adj[u]) {
            int v = x[0];       // Соседняя вершина / Neighbor vertex
            int weight = x[1];  // Вес ребра / Edge weight

            // Если найден более короткий путь / If a shorter path is found
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight; // Обновляем расстояние / Update distance
                pq.push({dist[v], v});      // Добавляем в очередь / Push to priority queue
            }
        }
    }

    return dist; // Возвращаем массив расстояний / Return distance array
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
        edges.push_back({u, v, w}); // Сохраняем введённые ребра / Store input edges
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> result = dijkstra(V, edges, src); // Запускаем алгоритм Дейкстры / Run Dijkstra's algorithm

    cout << "Shortest distances from vertex " << src << ": ";
    for (int dist : result)
        cout << dist << " "; // Выводим расстояния / Print distances
    cout << endl;

    return 0;
}
