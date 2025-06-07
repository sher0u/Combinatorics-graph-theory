/*
there is no direct edge (connection) between two vertices in the graph.
*/
/*
Enter number of vertices:5
Enter adjacency matrix (5 x 5), use 101 for INF:

0 4 101 5 101
101 0 1 101 6
2 101 0 3 101
101 101 1 0 2
1 101 101 4 0

Old matrix
0 4 INF 5 INF
INF 0 1 INF 6
2 INF 0 3 INF
INF INF 1 0 2
1 INF INF 4 0

New matrix
0 4 5 5 7
3 0 1 4 6
2 6 0 3 5
3 7 1 0 2
1 5 5 4 0
*/

// Реализация алгоритма Флойда-Уоршелла для поиска кратчайших путей между всеми парами вершин
// Floyd-Warshall algorithm for finding shortest paths between all pairs of vertices

#include <iostream>
#include <algorithm>

#define INF 101  // Обозначение бесконечности (отсутствие ребра) / Representation of infinity (no edge)

using namespace std;

// Функция вывода матрицы смежности
// Function to print adjacency matrix
void printMatrix(int** matrix, int numberOfVert) {
    for(int i = 0; i < numberOfVert; i++) {
        for(int j = 0; j < numberOfVert; j++) {
            if(matrix[i][j] == INF) {
                cout << "INF" << " "; // Если нет ребра, выводим INF / Output INF if no edge
            }
            else {
                cout << matrix[i][j] << " "; // Иначе выводим значение расстояния / Otherwise output weight
            }
        }
        cout << endl;
    }
}

// Основная функция алгоритма Флойда–Уоршелла
// Main Floyd-Warshall algorithm function
void originalFloydWarshall(int **matrix, int numberOfVert) {
    // Тройной цикл: для каждой промежуточной вершины k
    // Triple loop: for each intermediate vertex k
    for(int k = 0; k < numberOfVert; k++) {
        for(int i = 0; i < numberOfVert; i++) {
            for(int j = 0; j < numberOfVert; j++) {
                // Выбираем минимальное расстояние между i и j
                // Choose the shortest path from i to j
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    return;
}

int main(int argc, char** argv) {
    int numberOfVert;
    cout << "Enter number of vertices: ";
    // Ввод количества вершин / Input number of vertices
    cin >> numberOfVert;

    // Динамическое выделение памяти под матрицу смежности
    // Dynamic allocation for adjacency matrix
    int **matrix = (int**)malloc(sizeof(int) * numberOfVert);
    for(int i = 0; i < numberOfVert; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * numberOfVert);
    }

    // Ввод матрицы смежности (101 — отсутствие ребра)
    // Input adjacency matrix (101 means no edge)
    cout << "Enter adjacency matrix (" << numberOfVert << " x " << numberOfVert << "), use 101 for INF:\n";
    for(int i = 0; i < numberOfVert; i++) {
        for(int j = 0; j < numberOfVert; j++) {
            cin >> matrix[i][j];
        }
    }

    // Вывод исходной матрицы расстояний
    // Output the original distance matrix
    cout << "Old matrix" << endl;
    printMatrix(matrix, numberOfVert);

    // Запуск алгоритма Флойда–Уоршелла
    // Run the Floyd-Warshall algorithm
    originalFloydWarshall(matrix, numberOfVert);

    // Вывод новой (обновлённой) матрицы расстояний
    // Output the new (updated) distance matrix
    cout << "New matrix" << endl;
    printMatrix(matrix, numberOfVert);

    return 0;
}
