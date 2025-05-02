#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}
    void insertedge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void parallelDFS(int startVertex)
    {
        vector<bool> visited(V, false);
        parallelDFSUtil(startVertex, visited);
    }
    void parallelDFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        #pragma omp parallel for
        for (int i = 0; i < adj[v].size(); ++i)
        {
            int n = adj[v][i];
            if (!visited[n])
                parallelDFSUtil(n, visited);
        }
    }
    void parallelBFS(int startVertex)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";

            #pragma omp parallel for
            for (int i = 0; i < adj[v].size(); ++i)
            {
                int n = adj[v][i];
                if (!visited[n])
                {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
    }
};

int main()
{
    // int V, E;
    // cout << "Enter the number of vertices: ";
    // cin >> V;
    // cout << "Enter the number of edges: ";
    // cin >> E;
    // Graph g(V);

    // cout << "Enter the edges (format: vertex1 vertex2):" << endl;
    // for (int i = 0; i < E; ++i)
    // {
    //     int v, w;
    //     cin >> v >> w;
    //     g.addEdge(v, w);
    // }
    Graph g(5);
    g.insertedge(0,3);
    g.insertedge(0,1);
    g.insertedge(1,4);
    g.insertedge(2,4);
    
    g.insertedge(2,1);
    // g.printGraph();
    int startVertex;
    cout << "Enter the starting vertex for DFS and BFS: ";
    cin >> startVertex;
    cout << "Depth-First Search (DFS): ";
    g.parallelDFS(0);
    cout << endl;
    cout << "Breadth-First Search (BFS): ";
    g.parallelBFS(0);
    cout << endl;

    return 0;
}
