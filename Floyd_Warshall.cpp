#include <iostream>
#include <climits>
using namespace std;
void printPath(int parent[], int i, int j)
{
    if (i == j)
        cout << i << " ";
    else if (parent[j] == -1)
        cout << "No path exists";
    else
    {
        printPath(parent, i, parent[j]);
        cout << j << " ";
    }
}
int main()
{
    int V;
    cin>>V;
    int dist[V][V];
    for(int i =0;i<V;i++)
    {
        for(int j =0;j<V;j++)
        {
            cin>>dist[i][j];
            if(dist[i][j]==0&&i!=j)
            {
                dist[i][j]=INT_MAX;
            }
        }
    }

    int parent[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] != INT_MAX && i != j)
                parent[i][j] = i;
            else
                parent[i][j] = -1;
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << "The Shortest distance between " << i << " and " << j << " is ";
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";

            cout << "and the shortest path is: ";
            printPath(parent[i], i, j);
            cout << endl;
        }
    }
    return 0;
}