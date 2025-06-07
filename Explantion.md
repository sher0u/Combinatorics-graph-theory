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
```
