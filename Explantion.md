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
## 🧠 Шагы работа алгоритма
1 steps:
![image](https://github.com/user-attachments/assets/98e0608b-2a36-458c-8fde-be962c6b5a87)
2 steps:
![image](https://github.com/user-attachments/assets/8b851707-3d07-45c7-b51a-1925156be0ce)
3 steps:
![image](https://github.com/user-attachments/assets/135ad1a3-c6d8-4e16-9b8e-2b2c91313502)
4 steps:
![image](https://github.com/user-attachments/assets/caf829b3-f731-4b1e-8963-636ff930d030)
5 steps:
![image](https://github.com/user-attachments/assets/bfae437d-c7ef-47d3-87c9-4f0e277eab0f)
6 steps:
![image](https://github.com/user-attachments/assets/ffbc61d3-b15a-48e5-8fec-358f8a986225)
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
