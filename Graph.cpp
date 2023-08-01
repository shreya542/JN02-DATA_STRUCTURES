#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list representation

public:
    Graph(int numVertices) : V(numVertices), adjList(numVertices) {}

    // Function to add an edge between two vertices
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Since it's an undirected graph
    }

    // Function to perform Breadth-First Search traversal
    void BFS(int startVertex) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(startVertex);
        visited[startVertex] = true;

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int currVertex = q.front();
            cout << currVertex << " ";
            q.pop();

            for (int neighbor : adjList[currVertex]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }

    // Function to perform Depth-First Search traversal (Helper Function)
    void DFSHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSHelper(neighbor, visited);
            }
        }
    }

    // Function to perform Depth-First Search traversal
    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSHelper(startVertex, visited);
        cout << endl;
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges between vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Perform BFS traversal starting from vertex 0
    g.BFS(0);

    // Perform DFS traversal starting from vertex 2
    g.DFS(2);

    return 0;
}
