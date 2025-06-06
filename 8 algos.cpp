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
//алгоритма Флойда-Уоршелла
#include <iostream>
#include <algorithm>

//Максимальное значение веса = 100
#define INF 101

using namespace std;

void printMatrix(int** matrix, int numberOfVert) {
    for(int i = 0; i < numberOfVert; i++) {
        for(int j = 0; j < numberOfVert; j++) {
            if(matrix[i][j] == INF) {
                cout << "INF" << " ";
            }
            else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void originalFloydWarshall(int **matrix, int numberOfVert) {
    for(int k = 0; k < numberOfVert; k++) {
        for(int i = 0; i < numberOfVert; i++) {
            for(int j = 0; j < numberOfVert; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    return;
}

int main(int argc, char** argv) {
    int numberOfVert;
    cout << "Enter number of vertices: ";
    cin >> numberOfVert;

    // Матрица смежности с весами ребер графа (101 - ребра нет, 0 - ребро в себя)
    int **matrix = (int**)malloc(sizeof(int) * numberOfVert);
    for(int i = 0; i < numberOfVert; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * numberOfVert);
    }

    cout << "Enter adjacency matrix (" << numberOfVert << " x " << numberOfVert << "), use 101 for INF:\n";
    for(int i = 0; i < numberOfVert; i++) {
        for(int j = 0; j < numberOfVert; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Old matrix" << endl;
    printMatrix(matrix, numberOfVert);

    originalFloydWarshall(matrix, numberOfVert);

    cout << "New matrix" << endl;
    printMatrix(matrix, numberOfVert);

    return 0;
}
