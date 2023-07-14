#include <iostream>
#include <climits>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge {
    int src, dest, weight;
};

// a structure to represent a connected, directed, and weighted graph
struct Graph {
    int V, E; // V-> Number of vertices, E-> Number of edges
    Edge* edge; // graph is represented as an array of edges

    // Constructor
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        edge = new Edge[E];
    }
};

// A utility function used to print the solution
void printArr(int dist[], int n)
{
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < n; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

// The main function that finds the shortest distances from src
// to all other vertices using the Bellman-Ford algorithm. The
// function also detects negative weight cycles.
void BellmanFord(Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Step 1: Initialize distances from src to all other
    // vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: Check for negative-weight cycles.
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle";
            return;
        }
    }

    printArr(dist, V);
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph* graph = new Graph(V, E);

    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cout << "Enter source, destination, and weight for edge " << i + 1 << ": ";
        cin >> src >> dest >> weight;

        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    BellmanFord(graph, source);

    return 0;
}