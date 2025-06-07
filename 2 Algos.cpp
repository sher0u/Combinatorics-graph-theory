/*
Enter the number of vertices:5
Enter the number of edges:5
Enter edges in the format: src dest
1 2
0 2 3
0 4
1 4
2 3
Enter the starting vertex: Breadth-First Traversal (starting from vertex 3):
3 0 2 1 4
*/

 //Алгоритм поиска в ширину

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define a class named Graph to represent the graph
// structure.
class Graph {
    // Number of vertices in the graph.
    int V;
    // Adjacency list representation of the graph.
    vector<vector<int>> adjList;

public:
    // Constructor for initializing the graph with a given
    // number of vertex
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(vertices);
    }

    // Function for adding an edge to the graph.
    void addEdge(int src, int dest)
    {
        // Add destination vertex to source vertex's list.
        adjList[src].push_back(dest);
        // Add source vertex to destination vertex's list
        // (for undirected graph).
        adjList[dest].push_back(src);
    }

    // Function to perform Breadth-First Traversal (BFS)
    // starting from a given vertex.
    void bfs(int startVertex)
    {
        // Vector to keep track of visited vertices.
        vector<bool> visited(V, false);
        // Queue to help with the BFS traversal.
        queue<int> q;
        // Mark the start vertex as visited.
        visited[startVertex] = true;
        // Enqueue the start vertex.
        q.push(startVertex);

        while (!q.empty()) {
            // point currentVertex at front vertex from the queue.
            int currentVertex = q.front();
            // Print the current vertex.
            cout << currentVertex << " ";
            // Remove the front vertex from the queue.
            q.pop();

            // Iterate through all the neighbors of the
            // current vertex.
            for (int neighbor : adjList[currentVertex]) {
                // If the neighbor vertex has not been
                // visited yet.
                if (!visited[neighbor]) {
                    // Mark the neighbor vertex as visited.
                    visited[neighbor] = true;
                    // Enqueue the neighbor vertex.
                    q.push(neighbor);
                }
            }
        }
    }
};

int main()
{
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
        g.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "Breadth-First Traversal (starting from vertex " << startVertex << "):\n";
    g.bfs(startVertex);

    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 /*
Enter the number of vertices:5
Enter the number of edges:5
Enter edges in the format: src dest
1 2
0 2 3
0 4
1 4
2 3
Enter the starting vertex: Breadth-First Traversal (starting from vertex 3):
3 0 2 1 4
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class BreadthFirstSearchGraph {
    int totalVertices;
    vector<vector<int>> connectionMap;

public:
    BreadthFirstSearchGraph(int vertexCount) {
        totalVertices = vertexCount;
        connectionMap.resize(vertexCount);
    }

    void linkUndirected(int vertexA, int vertexB) {
        connectionMap[vertexA].push_back(vertexB);
        connectionMap[vertexB].push_back(vertexA);
    }

    void traverseFrom(int startingPoint) {
        vector<bool> wasVisited(totalVertices, false);
        queue<int> frontier;

        wasVisited[startingPoint] = true;
        frontier.push(startingPoint);

        while (!frontier.empty()) {
            int current = frontier.front();
            cout << current << " ";
            frontier.pop();

            for (int neighbor : connectionMap[current]) {
                if (!wasVisited[neighbor]) {
                    wasVisited[neighbor] = true;
                    frontier.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int numberOfNodes, numberOfLinks;
    cout << "Enter the number of vertices: ";
    cin >> numberOfNodes;

    BreadthFirstSearchGraph bfsGraph(numberOfNodes);

    cout << "Enter the number of edges: ";
    cin >> numberOfLinks;

    cout << "Enter edges in the format: src dest\n";
    for (int i = 0; i < numberOfLinks; i++) {
        int from, to;
        cin >> from >> to;
        bfsGraph.linkUndirected(from, to);
    }

    int startPoint;
    cout << "Enter the starting vertex: ";
    cin >> startPoint;

    cout << "Breadth-First Traversal (starting from vertex " << startPoint << "):\n";
    bfsGraph.traverseFrom(startPoint);

    return 0;
}
