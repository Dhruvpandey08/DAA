#include <iostream>
using namespace std;

#define INF 1000000000 // Infinity

class Array {
private:
    int V;
    int **dist;
    int **parent;

public:
    Array(int vertices) {
        V = vertices;

        // Allocate memory for distance matrix
        dist = new int *[V];
        for (int i = 0; i < V; i++) {
            dist[i] = new int[V];
        }

        // Allocate memory for parent matrix
        parent = new int *[V];
        for (int i = 0; i < V; i++) {
            parent[i] = new int[V];
        }

        // Initialize the distance matrix and parent matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;

                parent[i][j] = -1;
            }
        }
    }

    void addEdge(int src, int dest, int weight) {
        dist[src][dest] = weight;
        parent[src][dest] = src;
    }

    void printPath(int i, int j) {
        if (i == j)
            cout << i << " ";
        else if (parent[i][j] == -1)
            cout << "No path exists";
        else {
            printPath(i, parent[i][j]);
            cout << j << " ";
        }
    }

    void floydWarshall() {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
    }

    void printShortestPaths() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << "The Shortest distance between " << i << " and " << j << " is ";
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";

                cout << "and the shortest path is: ";
                printPath(i, j);
                cout << endl;
            }
        }
    }

    // Destructor to deallocate memory
    ~Array() {
        for (int i = 0; i < V; i++) {
            delete[] dist[i];
            delete[] parent[i];
        }
        delete[] dist;
        delete[] parent;
    }
};

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Array graph(V);

    cout << "Enter the adjacency matrix (enter -1 for infinity):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int weight;
            cin >> weight;
            if (weight == -1)
                weight = INF;
            graph.addEdge(i, j, weight);
        }
    }

    graph.floydWarshall();
    graph.printShortestPaths();

    return 0;
}
