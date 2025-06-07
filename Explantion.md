# Работа выполнена Юсфи Абделкадером под руководством преподавателя Александры Викторовны
# 1 - Поиск в Глубину (DFS) на C++

Этот репозиторий демонстрирует реализацию алгоритма **поиска в глубину (DFS)** на графе, представленном с помощью списка смежности на языке C++.

## 📌 Общее описание

Поиск в глубину (DFS) — это базовый алгоритм, используемый для обхода вершин и рёбер графа. В отличие от деревьев, графы могут содержать циклы, поэтому DFS использует массив `visited[]`, чтобы не посещать вершины повторно.

Алгоритм работает следующим образом:

* Посещает вершину
* Рекурсивно посещает всех её непосещённых соседей
* Возвращается назад, когда все соседи посещены

Эта программа позволяет:

* Ввести количество вершин и рёбер
* Задать рёбра графа
* Выбрать начальную вершину
* Выполнить обход графа в глубину от выбранной вершины

---

## 🧠 Логика алгоритма DFS

**Пошаговое объяснение:**

1. Инициализация графа с заданным числом вершин.
2. Чтение и сохранение всех рёбер в списке смежности.
3. Запрос начальной вершины у пользователя.
4. Запуск DFS от этой вершины.
5. Для каждой посещённой вершины:

   * Отметить её как посещённую
   * Вывести её
   * Рекурсивно пройтись по всем смежным непосещённым вершинам

---

## 📏 Пример ввода/вывода

```
Введите количество вершин (индексация с 0): 5
Введите количество рёбер: 5
Введите 5 рёбер в формате: src dest
Ребро 1: 1 2
Ребро 2: 1 0
Ребро 3: 2 0
Ребро 4: 2 3
Ребро 5: 2 4
Введите начальную вершину для DFS (от 0 до 4): 1
1 0 2 4 3
```
## 🧠 Шаги работы алгоритма

### Шаг 1  
![Шаг 1](https://github.com/user-attachments/assets/98e0608b-2a36-458c-8fde-be962c6b5a87)

### Шаг 2  
![Шаг 2](https://github.com/user-attachments/assets/8b851707-3d07-45c7-b51a-1925156be0ce)

### Шаг 3  
![Шаг 3](https://github.com/user-attachments/assets/135ad1a3-c6d8-4e16-9b8e-2b2c91313502)

### Шаг 4  
![Шаг 4](https://github.com/user-attachments/assets/caf829b3-f731-4b1e-8963-636ff930d030)

### Шаг 5  
![Шаг 5](https://github.com/user-attachments/assets/bfae437d-c7ef-47d3-87c9-4f0e277eab0f)

### Шаг 6  
![Шаг 6](https://github.com/user-attachments/assets/ffbc61d3-b15a-48e5-8fec-358f8a986225)

---

## 💻 Код на C++ с комментариями

```cpp
// Алгоритм поиска в глубину (DFS) / Depth-First Search Algorithm
#include <iostream>
#include <list>
using namespace std;

// Определение класса графа / Definition of the Graph class
class Graph {
    int numVertices;           // Количество вершин / Number of vertices
    list<int> *adjLists;       // Массив списков смежности / Array of adjacency lists
    bool *visited;             // Массив посещённых вершин / Array to track visited vertices

public:
    Graph(int V);              // Конструктор / Constructor
    void addEdge(int src, int dest); // Метод добавления ребра / Method to add an edge
    void DFS(int vertex);      // Метод DFS / Method for DFS traversal
};

// Инициализация графа / Graph initialization
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];   // Выделяем память под списки смежности / Allocate memory for adjacency lists
    visited = new bool[vertices];         // Выделяем память под массив посещённых / Allocate memory for visited array

    // Изначально все вершины не посещены / Initially mark all vertices as unvisited
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
}

// Метод добавления ребра в граф / Method to add an edge to the graph
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest); // Добавляем dest в список смежности src / Add dest to adjacency list of src
}

// Рекурсивный алгоритм поиска в глубину / Recursive DFS algorithm
void Graph::DFS(int vertex) {
    visited[vertex] = true; // Отмечаем вершину как посещённую / Mark the current vertex as visited
    list<int> adjList = adjLists[vertex]; // Получаем список смежных вершин / Get the adjacency list

    cout << vertex << " "; // Выводим текущую вершину / Print current vertex

    // Рекурсивно посещаем все непосещённые смежные вершины / Recursively visit all unvisited adjacent vertices
    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    int V, E;

    // Ввод количества вершин / Input number of vertices
    cout << "Введите количество вершин (индексация с 0): ";
    cin >> V;
    Graph g(V); // Создаём граф с V вершинами / Create a graph with V vertices

    // Ввод количества рёбер / Input number of edges
    cout << "Введите количество рёбер: ";
    cin >> E;

    // Ввод рёбер / Input the edges
    cout << "Введите " << E << " рёбер в формате: src dest" << endl;
    cout << "Примечание: вершины должны быть в диапазоне [0, " << V - 1 << "]" << endl;

    for (int i = 0; i < E; i++) {
        int src, dest;
        cout << "Ребро " << i + 1 << ": ";
        cin >> src >> dest;
        g.addEdge(src, dest); // Добавляем ребро в граф / Add the edge to the graph
    }

    int startVertex;

    // Ввод стартовой вершины / Input starting vertex for DFS
    cout << "Введите начальную вершину для DFS (от 0 до " << V - 1 << "): ";
    cin >> startVertex;

    // Запуск обхода в глубину / Start DFS traversal
    g.DFS(startVertex);

    return 0;
}
```
# Алгоритм поиска в ширину в C++

Этот репозиторий демонстрирует реализацию алгоритма **Обхода в ширину (BFS)** для графа с помощью списка смежности на C++.

---

## 📌 Обзор

Обход в ширину (BFS) — это алгоритм для обхода или поиска в графе. Он начинает с указанной стартовой вершины и последовательно посещает все вершины на одном уровне перед переходом к вершинам следующего уровня.

В отличие от обхода в глубину, BFS использует очередь для запоминания вершин, которые надо посетить, и массив `visited[]` для того, чтобы не посещать вершины повторно.

---

## 🧠 Логика алгоритма BFS

**Пошаговое описание:**

1. Инициализировать граф с заданным количеством вершин.  
2. Считать все рёбра и сохранить их в списке смежности.  
3. Запросить у пользователя стартовую вершину.  
4. Поместить стартовую вершину в очередь и пометить её как посещённую.  
5. Пока очередь не пуста:  
    - Извлечь вершину из очереди и вывести её.  
    - Добавить в очередь всех соседей, которые ещё не посещены, и пометить их как посещённые.

---

## 📏 Пример ввода/вывода
```
Enter the number of vertices: 5
Enter the number of edges: 5
Enter edges in the format: src dest
1 2
0 2
3 0
4 1
4 2
Enter the starting vertex: 3
Breadth-First Traversal (starting from vertex 3):
3 0 2 1 4
```
## 🧠 Шаги работы алгоритма


### Шаг 1  
![Шаг 1](https://github.com/user-attachments/assets/8de4978e-a32b-4ba7-85e5-12a3edc12308)

### Шаг 2  
![Шаг 2](https://github.com/user-attachments/assets/ff1c4ec9-bd98-4b98-b8ac-d5fc18f9f20d)

### Шаг 3  
![Шаг 3](https://github.com/user-attachments/assets/5deff6d6-39b8-468d-bbff-7f6d068c72f1)

### Шаг 4  
![Шаг 4](https://github.com/user-attachments/assets/eccdb01c-c346-4f20-888a-c751d1d10f5f)

### Шаг 5  
![Шаг 5](https://github.com/user-attachments/assets/691bfd1d-6dcf-48a3-b23c-a25227d84ad1)

### Шаг 6  
![Шаг 6](https://github.com/user-attachments/assets/3725d149-a12b-41f3-826f-a8b75d9542f0)

### Шаг 7  
![Шаг 7](https://github.com/user-attachments/assets/e6127ae0-9fb8-45f0-bb14-773db7439b80)


## 💻 Код на C++ с комментариями

```cpp
// Алгоритм поиска в ширину (BFS) / Breadth-First Search Algorithm
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Класс графа / Graph class
class Graph {
    int V;                      // Количество вершин / Number of vertices
    vector<vector<int>> adjList; // Список смежности / Adjacency list

public:
    Graph(int vertices) {       // Конструктор / Constructor
        V = vertices;
        adjList.resize(vertices); // Инициализация списка смежности / Initialize adjacency list
    }

    void addEdge(int src, int dest) { // Добавление ребра / Add edge
        adjList[src].push_back(dest); // Добавляем dest в список src / Add dest to src's adjacency list
        adjList[dest].push_back(src); // Для неориентированного графа добавляем src в список dest / For undirected graph
    }

    void bfs(int startVertex) {   // Обход в ширину / BFS traversal
        vector<bool> visited(V, false); // Массив посещённых вершин / Visited array
        queue<int> q;                   // Очередь для BFS / Queue for BFS

        visited[startVertex] = true;    // Отмечаем стартовую вершину посещённой / Mark start vertex visited
        q.push(startVertex);            // Добавляем стартовую вершину в очередь / Enqueue start vertex

        while (!q.empty()) {
            int currentVertex = q.front(); // Текущая вершина / Current vertex
            cout << currentVertex << " ";  // Выводим вершину / Print current vertex
            q.pop();                       // Удаляем из очереди / Dequeue

            // Обрабатываем всех соседей текущей вершины / Iterate through neighbors
            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) { // Если сосед ещё не посещён
                    visited[neighbor] = true; // Отмечаем как посещённый
                    q.push(neighbor);          // Добавляем в очередь
                }
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges in the format: src dest\n";
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest); // Добавляем ребро в граф
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "Breadth-First Traversal (starting from vertex " << startVertex << "):\n";
    g.bfs(startVertex);

    return 0;
}
```
# 3 Алгоритм топологической сортировки (Topological Sort) на C++

Этот репозиторий демонстрирует реализацию алгоритма **топологической сортировки** для ориентированного ацикличного графа (DAG) на языке C++ с использованием списков смежности.

---

## 📌 Обзор
```
Топологическая сортировка — это упорядочение вершин ориентированного ацикличного графа так, чтобы для каждого ребра (u -> v) вершина u предшествовала вершине v в порядке.
```
## Этот алгоритм полезен для:

- планирования задач,
- определения порядка компиляции модулей,
- анализа зависимостей и т.д.

---

## 🧠 Логика алгоритма
```
1. Создаем стек для хранения порядка вершин.
2. Используем обход в глубину (DFS) для посещения всех вершин.
3. При возвращении из рекурсии добавляем вершину в стек.
4. После обхода выводим вершины в порядке, обратном порядку добавления в стек.

---
```
## 📏 Пример ввода/вывода
```
Enter the number of vertices: 6
Enter the number of edges: 6
Enter edges in the format: src dest
Edge 1: 2 3
Edge 2: 3 1
Edge 3: 4 0
Edge 4: 4 1
Edge 5: 5 0
Edge 6: 5 2
Topological Sort of the given graph:
5 4 2 3 1 0


---
```
## 🧠 Шаги работы алгоритма

### Шаг 1  
![image](https://github.com/user-attachments/assets/393a27a0-4c2e-4ed1-bede-f2bd8d9f0440)


### Шаг 2  
![image](https://github.com/user-attachments/assets/b64993b5-17bf-4fe7-914e-9158350ca486)


### Шаг 3  
![image](https://github.com/user-attachments/assets/1362335c-dd7b-4a7a-a5a7-f57e98ac3551)


### Шаг 4  
![image](https://github.com/user-attachments/assets/d11aa16e-3ae3-464b-8ed7-57ee1a2e8762)


### Шаг 5  
![image](https://github.com/user-attachments/assets/5b85de9e-5264-49e0-b5f5-32a839821cdf)


## 💻 Код на C++ с комментариями
```cpp
// Алгоритм топологической сортировки / Topological Sort Algorithm
#include <iostream>
#include <list>
#include <stack>
using namespace std;

// Класс для представления графа / Graph class definition
class Graph {
    int V;              // Количество вершин / Number of vertices
    list<int> *adj;     // Массив списков смежности / Adjacency list

    // Вспомогательная функция для топологической сортировки (DFS)
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);               // Конструктор / Constructor
    void addEdge(int v, int w); // Метод добавления ребра / Add edge method
    void topologicalSort();     // Метод топологической сортировки / Topological sort method
};

// Инициализация графа / Graph initialization
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

// Добавление ребра в граф / Add edge to graph
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

// Рекурсивный DFS для топологической сортировки
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;  // Отмечаем вершину как посещённую

    // Обход всех смежных вершин
    for (int neighbor : adj[v]) {
        if (!visited[neighbor])
            topologicalSortUtil(neighbor, visited, Stack);
    }

    // Добавляем вершину в стек после обработки всех соседей
    Stack.push(v);
}

// Основной метод топологической сортировки
void Graph::topologicalSort() {
    stack<int> Stack;            // Стек для хранения порядка вершин
    bool *visited = new bool[V]; // Массив посещённых вершин

    // Изначально все вершины не посещены
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Вызываем вспомогательную функцию для всех непосещённых вершин
    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack);

    // Выводим вершины в порядке из стека (обратный порядок)
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges in the format: src dest\n";
    cout << "(Note: vertices should be from 0 to " << V-1 << ")\n";

    for (int i = 0; i < E; i++) {
        int src, dest;
        cout << "Edge " << i + 1 << ": ";
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    cout << "Topological Sort of the given graph:\n";
    g.topologicalSort();

    return 0;
}
---
```
## 4 Алгоритм Форда-Фалкерсона  для поиска максимального потока 

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <set>

using namespace std;

class FlowNetwork {
public:
    int V; // Количество вершин / Number of vertices
    vector<vector<int>> capacity; // Матрица пропускных способностей / Capacity matrix
    vector<vector<int>> adj; // Список смежности / Adjacency list

    FlowNetwork(int vertices) {
        V = vertices;
        capacity.assign(V, vector<int>(V, 0));
        adj.resize(V);
    }

    void addEdge(int u, int v, int cap) {
        // Если ребро еще не добавлено (прямое и обратное ребро)
        // If the edge does not exist yet (direct and reverse edge)
        if (capacity[u][v] == 0 && capacity[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u); // Добавляем обратное ребро для остаточной сети / Add reverse edge for residual graph
        }
        capacity[u][v] += cap; // Если параллельные рёбра, суммируем пропускные способности / Sum capacities if parallel edges
    }
};

// Поиск в ширину (BFS) для нахождения увеличивающего пути
// Breadth-First Search (BFS) to find augmenting path
int bfs(FlowNetwork &network, int s, int t, vector<int> &parent) {
    fill(parent.begin(), parent.end(), -1); // Инициализация массива родителей / Initialize parent array
    parent[s] = -2; // Исток помечаем специальным значением / Mark source with special value
    queue<pair<int, int>> q;
    q.push({s, numeric_limits<int>::max()}); // Начинаем с истока и максимально возможного потока / Start from source with infinite flow

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v : network.adj[u]) {
            // Если вершина еще не посещена и пропускная способность положительна
            // If vertex not visited and capacity > 0
            if (parent[v] == -1 && network.capacity[u][v] > 0) {
                parent[v] = u;
                int new_flow = min(flow, network.capacity[u][v]); // Поток ограничен минимальной пропускной способностью на пути / Flow limited by min capacity on path
                if (v == t)
                    return new_flow; // Достигли стока, возвращаем найденный поток / Reached sink, return flow
                q.push({v, new_flow});
            }
        }
    }
    return 0; // Увеличивающий путь не найден / No augmenting path found
}

// Алгоритм Эдмондса-Карпа для нахождения максимального потока
// Edmonds-Karp algorithm for maximum flow
int edmondsKarp(FlowNetwork &network, int source, int sink) {
    int flow = 0;
    vector<int> parent(network.V);
    int new_flow;

    // Пока существует увеличивающий путь
    // While there is an augmenting path
    while ((new_flow = bfs(network, source, sink, parent))) {
        flow += new_flow; // Увеличиваем общий поток / Increase total flow
        int v = sink;
        // Обновляем остаточную сеть (уменьшаем прямые, увеличиваем обратные ребра)
        // Update residual network (reduce forward edges, increase reverse edges)
        while (v != source) {
            int u = parent[v];
            network.capacity[u][v] -= new_flow;
            network.capacity[v][u] += new_flow;
            v = u;
        }
    }

    return flow; // Возвращаем максимальный поток / Return max flow
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

        u--; v--; // Конвертация в 0-базированный индекс / Convert to 0-based index

        // Проверка корректности введенных данных / Validate input
        if (u == v || u < 0 || u >= V || v < 0 || v >= V || cap <= 0) {
            cout << "Invalid edge. Try again.\n";
            i--;
            continue;
        }

        // Проверка на повторное ребро / Check for duplicate edge
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
    source--; sink--; // Конвертация в 0-базированный индекс / Convert to 0-based

    // Проверка корректности истока и стока / Validate source and sink
    if (source == sink || source < 0 || sink < 0 || source >= V || sink >= V) {
        cout << "Invalid source or sink.\n";
        return 1;
    }

    int maxFlow = edmondsKarp(network, source, sink);
    cout << "\nMaximum Flow: " << maxFlow << endl;

    return 0;
}
---
```
Краткие шаги алгоритма / Short Steps of the Algorithm
```
    Создаем сеть с вершинами и ребрами с пропускными способностями.
    Create a network with vertices and edges with capacities.

    Ищем увеличивающий путь из истока в сток с помощью поиска в ширину (BFS).
    Find an augmenting path from source to sink using BFS.

    Если путь найден, вычисляем минимальную пропускную способность на этом пути.
    If path is found, compute minimum capacity on this path.

    Увеличиваем общий поток на эту минимальную пропускную способность.
    Increase total flow by that minimum capacity.

    Обновляем остаточную сеть: уменьшаем пропускные способности вдоль пути и увеличиваем обратные ребра.
    Update residual network: decrease capacities along the path and increase reverse edges.

    Повторяем, пока не будет найдено больше увеличивающих путей.
    Repeat until no more augmenting paths exist.

    Итоговый поток — максимальный поток сети.
    Final flow is the maximum flow in the network.
---
```
Пример ввода / Example input
```
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
```


## 4 Алгоритм поиска мостов в графе (Bridges in Graph)

## Логика алгоритма
```
```
```
Мост — это ребро графа, удаление которого увеличивает количество компонент связности.
Алгоритм использует DFS для поиска таких ребер. Для каждого узла фиксируется время входа (discovery time) и минимальное время входа достижимое из его потомков (low). Если для ребра (u, v) значение low[v] > disc[u], то это мост.
```
## Пример ввода/вывода
```
Enter number of vertices:5 
Enter number of edges:5
Enter edges (u v) - 0-based indexing:
1 0 
0 2
2 1
0 3
3 4
Bridges in the graph:
3 4
0 3
```

## 🧠 Шаги работы алгоритма
```
```
### Шаг 1  
```
Обход графа с помощью DFS, запоминая время входа в каждую вершину и минимальное время входа достижимое из потомков.
```
### Шаг 2  
```
Для каждого ребра проверяется условие: если минимальное время входа потомка больше времени входа текущей вершины — ребро является мостом.
```
### Шаг 3  
```
Выводятся все найденные мосты.
```
## Код на C++ с комментариями
```cpp
#include<bits/stdc++.h>
using namespace std;

// Класс, представляющий неориентированный граф
class Graph
{
    int V;    // Кол-во вершин
    list<int> *adj;    // Массив списков смежности
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent);
public:
    Graph(int V);   // Конструктор
    void addEdge(int v, int w);   // Добавить ребро
    void bridge();    // Поиск и вывод всех мостов
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Граф неориентированный
}

// Рекурсивная функция для поиска мостов с помощью DFS
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent)
{
    static int time = 0;  // Время посещения

    visited[u] = true;    // Отмечаем вершину как посещённую
    disc[u] = low[u] = ++time;  // Инициализируем время входа и low

    for (int v : adj[u])  // Для всех соседей вершины u
    {
        if (v == parent)  // Если сосед — родитель, пропускаем
            continue;

        if (visited[v])  // Если сосед уже посещён, обновляем low[u]
            low[u] = min(low[u], disc[v]);
        else
        {
            bridgeUtil(v, visited, disc, low, u);  // Рекурсивный вызов
            low[u] = min(low[u], low[v]);

            // Если нет обратных рёбер из потомков v к предкам u, ребро - мост
            if (low[v] > disc[u])
                cout << u << " " << v << endl;
        }
    }
}

// Функция для запуска поиска мостов во всем графе
void Graph::bridge()
{
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    int parent = -1;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            bridgeUtil(i, visited, disc, low, parent);
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v) - 0-based indexing:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nBridges in the graph:\n";
    g.bridge();

    return 0;
}
```

