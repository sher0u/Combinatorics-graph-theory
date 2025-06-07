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
// Алгоритм Беллмана-Форда / Bellman-Ford Algorithm
#include <iostream>
#include <vector>
using namespace std;

// Функция алгоритма Беллмана-Форда / Bellman-Ford algorithm function
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8); // Инициализируем расстояния как "бесконечность" / Initialize distances as "infinity"
    dist[src] = 0; // Расстояние до исходной вершины = 0 / Distance to source vertex is 0

    // Основной цикл (V итераций) / Main loop (V iterations)
    for (int i = 0; i < V; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0]; // Откуда / From
            int v = edge[1]; // Куда / To
            int wt = edge[2]; // Вес ребра / Edge weight

            // Если путь через u короче — обновляем расстояние до v / Relax the edge if a shorter path is found
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                if (i == V - 1)
                    return {-1}; // Обнаружен цикл отрицательного веса / Negative weight cycle detected
                dist[v] = dist[u] + wt; // Обновление расстояния / Update distance
            }
        }
    }

    return dist; // Возвращаем массив кратчайших расстояний / Return shortest distances
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
        edges.push_back({u, v, w}); // Сохраняем ребро / Store the edge
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> ans = bellmanFord(V, edges, src); // Запуск алгоритма / Run Bellman-Ford algorithm

    // Проверка на наличие цикла отрицательного веса / Check for negative weight cycle
    if (ans.size() == 1 && ans[0] == -1) {
        cout << "Negative weight cycle detected." << endl;
    } else {
        cout << "Shortest distances from vertex " << src << ": ";
        for (int dist : ans)
            cout << dist << " "; // Выводим расстояния от src до всех вершин / Print distances from src
        cout << endl;
    }

    return 0;
}
