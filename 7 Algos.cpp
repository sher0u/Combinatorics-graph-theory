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

// Алгоритм Косарайю для проверки сильной связности ориентированного графа
// Kosaraju's algorithm for checking strong connectivity of a directed graph

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V;                 // Количество вершин / Number of vertices
    list<int>* adj;        // Список смежности / Adjacency list

    // Вспомогательная функция для DFS обхода
    // Helper function for DFS traversal
    void DFSUtil(int v, bool visited[]);

public:
    // Конструктор / Constructor
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    // Деструктор / Destructor
    ~Graph() { delete[] adj; }

    // Добавление ребра / Add edge to the graph
    void addEdge(int v, int w);

    // Проверка на сильную связность / Check if the graph is strongly connected
    bool isSC();

    // Получение транспонированного графа / Get transposed graph
    Graph getTranspose();
};

// Обход в глубину, начиная с вершины v
// Depth First Search starting from vertex v
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;

    // Рекурсивный обход всех непосещённых соседей
    // Recursively visit all unvisited neighbors
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// Создание транспонированного графа (обратное направление рёбер)
// Create a transposed graph (reverse direction of all edges)
Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++) {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);  // Добавляем обратное ребро
            // Add reversed edge
        }
    }
    return g;
}

// Добавление ребра из вершины v в вершину w
// Add an edge from vertex v to vertex w
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

// Проверка, является ли граф сильно связным
// Check if the graph is strongly connected
bool Graph::isSC()
{
    // Создаём массив посещённых вершин и инициализируем его
    // Create visited array and initialize it
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Выполняем DFS из первой вершины
    // Perform DFS from the first vertex
    DFSUtil(0, visited);

    // Проверяем, были ли посещены все вершины
    // Check if all vertices were visited
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;

    // Получаем транспонированный граф
    // Get the transposed graph
    Graph gr = getTranspose();

    // Повторно инициализируем массив посещённых вершин
    // Re-initialize visited array
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Выполняем DFS на транспонированном графе
    // Perform DFS on the transposed graph
    gr.DFSUtil(0, visited);

    // Если какая-либо вершина не была достигнута — граф не сильно связен
    // If any vertex was not visited — the graph is not strongly connected
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;

    // Если обе проверки пройдены — граф сильно связен
    // If both DFS passes were successful — graph is strongly connected
    return true;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    // Ввод количества вершин
    cin >> V;
    cout << "Enter number of edges: ";
    // Ввод количества рёбер
    cin >> E;

    Graph g(V);
    cout << "Enter edges (format: from to) each in a new line:\n";
    // Ввод рёбер графа
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    // Вывод результата: граф сильно связен или нет
    // Output result: whether the graph is strongly connected
    g.isSC() ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
