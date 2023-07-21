#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; // A very large value representing infinity

class FlowNetwork {
private:
    int numNodes;
    int** graph;
    int* parent;

public:
    FlowNetwork(int numNodes) : numNodes(numNodes) {
        graph = new int*[numNodes];
        for (int i = 0; i < numNodes; ++i) {
            graph[i] = new int[numNodes];
            for (int j = 0; j < numNodes; ++j) {
                graph[i][j] = 0; // Initialize the graph with 0 capacity (no edge)
            }
        }

        parent = new int[numNodes];
    }

    ~FlowNetwork() {
        for (int i = 0; i < numNodes; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        delete[] parent;
    }

    // Function to add an edge to the flow network
    void addEdge(int source, int destination, int capacity) {
        graph[source][destination] = capacity;
    }

    // Function to find the maximum flow using Edmonds-Karp algorithm
    int edmondsKarp(int source, int sink) {
        int** residualGraph = new int*[numNodes];
        for (int i = 0; i < numNodes; ++i) {
            residualGraph[i] = new int[numNodes];
            for (int j = 0; j < numNodes; ++j) {
                residualGraph[i][j] = graph[i][j]; // Initialize residual graph with original capacities
            }
        }

        int maxFlow = 0;

        while (true) {
            fill(parent, parent + numNodes, -1);
            parent[source] = -2;
            queue<pair<int, int>> q;
            q.push({source, INF});

            while (!q.empty()) {
                int currentNode = q.front().first;
                int flow = q.front().second;
                q.pop();

                for (int nextNode = 0; nextNode < numNodes; ++nextNode) {
                    if (parent[nextNode] == -1 && residualGraph[currentNode][nextNode] > 0) {
                        parent[nextNode] = currentNode;
                        int newFlow = min(flow, residualGraph[currentNode][nextNode]);
                        if (nextNode == sink) {
                            maxFlow += newFlow;
                            while (nextNode != source) {
                                currentNode = parent[nextNode];
                                residualGraph[currentNode][nextNode] -= newFlow;
                                residualGraph[nextNode][currentNode] += newFlow;
                                nextNode = currentNode;
                            }
                            break;
                        }
                        q.push({nextNode, newFlow});
                    }
                }
            }

            if (parent[sink] == -1) // No augmenting path found, we've reached maximum flow
                break;
        }

        // Free allocated memory for residual graph
        for (int i = 0; i < numNodes; ++i) {
            delete[] residualGraph[i];
        }
        delete[] residualGraph;

        return maxFlow;
    }
};

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    FlowNetwork flowNetwork(numNodes);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges in the format: source destination capacity\n";
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, capacity;
        cin >> source >> destination >> capacity;
        flowNetwork.addEdge(source, destination, capacity);
    }

    int source, sink;
    cout << "Enter the source node: ";
    cin >> source;

    cout << "Enter the sink node: ";
    cin >> sink;

    int maxFlow = flowNetwork.edmondsKarp(source, sink);
    cout << "The maximum flow from node " << source << " to node " << sink << " is: " << maxFlow << endl;

    return 0;
}