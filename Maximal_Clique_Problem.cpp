#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class BronKerbosch {
public:
    void readGraph() {
        int numNodes, numEdges;
        cout << "Enter the number of nodes: ";
        cin >> numNodes;
        cout << "Enter the number of edges: ";
        cin >> numEdges;

        for (int i = 1; i <= numEdges; ++i) {
            int fromNode, toNode;
            cout << "Enter the edge " << i << " (fromNode to toNode): ";
            cin >> fromNode >> toNode;

            neighbors[fromNode].insert(toNode);
            neighbors[toNode].insert(fromNode); // Assuming the graph is undirected
        }
    }

    void find_maximal_cliques() {
        vector<int> R;
        unordered_set<int> vertices;
        for (const auto& entry : neighbors) {
            vertices.insert(entry.first);
        }
        unordered_set<int> X;

        count = 0; // Initialize the clique count
        find_maximal_cliques(R, vertices, X);
    }

    void printMaximalCliques() {
        cout << "Maximal Clique Count: " << count << endl;
        cout << "Nodes in each maximal clique:" << endl;
        for (const auto& clique : maximal_cliques) {
            for (int v : clique) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

private:
    // Helper function to find the intersection of two sets
    unordered_set<int> intersect(const unordered_set<int>& set1, const unordered_set<int>& set2) {
        unordered_set<int> result;
        for (const int& elem : set1) {
            if (set2.count(elem) > 0) {
                result.insert(elem);
            }
        }
        return result;
    }

    // Bron-Kerbosch algorithm for finding all maximal cliques
    void find_maximal_cliques(vector<int>& R, unordered_set<int>& P, unordered_set<int>& X) {
        if (P.empty() && X.empty()) {
            maximal_cliques.push_back(R);
            count++; // Increment the clique count
            return;
        }

        for (int v : P) {
            vector<int> R_prime = R;
            R_prime.push_back(v);
            unordered_set<int> P_prime = intersect(P, neighbors[v]);
            unordered_set<int> X_prime = intersect(X, neighbors[v]);

            find_maximal_cliques(R_prime, P_prime, X_prime);

            P.erase(v);
            X.insert(v);
        }
    }

    // The graph and neighbors should be accessible from within the class
    unordered_map<int, unordered_set<int>> neighbors;
    vector<vector<int>> maximal_cliques;
    int count;
};

int main() 
{
    BronKerbosch bron_kerbosch_solver;
    bron_kerbosch_solver.readGraph();
    bron_kerbosch_solver.find_maximal_cliques();
    bron_kerbosch_solver.printMaximalCliques();

    return 0;
}
