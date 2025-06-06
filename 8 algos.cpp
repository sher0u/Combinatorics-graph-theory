//10алгоритма Флойда-Уоршелла
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
