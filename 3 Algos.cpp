/*
Enter the number of vertices:6
Enter the number of edges:6
Enter edges in the format: src dest
Edge 1:2 3 
Edge 2:3 1
Edge 3:4 0
Edge 4:4 1
Edge 5:5 0
Edge 6:5 2
Topological Sort of the given graph:
5 4 2 3 1 0
*/#include <iostream>
#include <list>
#include <stack>
#include <limits> // for numeric_limits
using namespace std;

class TopologicalSortGraph {
    int totalVertices;
    list<int> *outgoingEdges;

    void exploreAndStack(int currentVertex, bool visited[], stack<int> &ordering);

public:
    TopologicalSortGraph(int verticesCount);
    ~TopologicalSortGraph();
    void connectDirected(int fromVertex, int toVertex);
    void computeTopologicalOrdering();
};

TopologicalSortGraph::TopologicalSortGraph(int verticesCount) {
    totalVertices = verticesCount;
    outgoingEdges = new list<int>[verticesCount];
}

TopologicalSortGraph::~TopologicalSortGraph() {
    delete[] outgoingEdges;
}

void TopologicalSortGraph::connectDirected(int fromVertex, int toVertex) {
    outgoingEdges[fromVertex].push_back(toVertex);
}

void TopologicalSortGraph::exploreAndStack(int currentVertex, bool visited[], stack<int> &ordering) {
    visited[currentVertex] = true;

    for (int next : outgoingEdges[currentVertex]) {
        if (!visited[next]) {
            exploreAndStack(next, visited, ordering);
        }
    }

    ordering.push(currentVertex);
}

void TopologicalSortGraph::computeTopologicalOrdering() {
    stack<int> ordering;
    bool *visited = new bool[totalVertices]{false};

    for (int vertex = 0; vertex < totalVertices; vertex++) {
        if (!visited[vertex]) {
            exploreAndStack(vertex, visited, ordering);
        }
    }

    while (!ordering.empty()) {
        cout << ordering.top() << " ";
        ordering.pop();
    }
    cout << endl;

    delete[] visited;
}

// Utility function to safely read an integer
bool readInt(int &value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    int vertexCount, edgeCount;

    cout << "Enter the number of vertices: ";
    if (!readInt(vertexCount) || vertexCount <= 0) {
        cout << "Error: number of vertices must be a positive integer.\n";
        return 1;
    }

    TopologicalSortGraph topoGraph(vertexCount);

    cout << "Enter the number of edges: ";
    if (!readInt(edgeCount) || edgeCount < 0) {
        cout << "Error: number of edges must be a non-negative integer.\n";
        return 1;
    }

    cout << "Enter edges in the format: src dest\n";
    cout << "(Note: vertices should be from 0 to " << vertexCount - 1 << ")\n";

    for (int i = 0; i < edgeCount; i++) {
        int from, to;
        cout << "Edge " << i + 1 << ": ";
        if (!readInt(from) || !readInt(to)) {
            cout << "Error: edge must consist of two integers.\n";
            return 1;
        }
        if (from < 0 || from >= vertexCount || to < 0 || to >= vertexCount) {
            cout << "Error: vertices must be in range [0, " << vertexCount - 1 << "].\n";
            return 1;
        }
        topoGraph.connectDirected(from, to);
    }

    cout << "Topological Sort of the given graph:\n";
    topoGraph.computeTopologicalOrdering();

    return 0;
}

