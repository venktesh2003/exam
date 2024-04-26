#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

void parallelBFS(vector<int> adj[], int start, int n)
{

    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(start);
    cout << "\nBFS of the given graph is: " << endl;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << " ";
        vis[top] = 1;
#pragma omp parallel for shared(adj, vis, q)
        for (auto neigh : adj[top])
        {
            if (vis[neigh] == 0)
            {
                q.push(neigh);
                vis[neigh] = 1;
            }
        }
    }
}

void parallelDFS(vector<int> adj[], vector<int> &vis, int start)
{
    cout << start << " ";
    vis[start] = 1;
#pragma omp parallel for shared(Adj, vis)
    for (auto neigh : adj[start])
    {
        if (vis[neigh] == 0)
        {
            parallelDFS(adj, vis, neigh);
            vis[neigh] = 1;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the no of vertices in a graph: " << endl;
    cin >> n;
    int m;
    cout << "Enter the no of edges in a graph: " << endl;
    cin >> m;
    vector<int> adj[n + 1];
    cout << "Enter the  edges in a graph: " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cout << "Enter the starting node: " << endl;
    cin >> start;
    parallelBFS(adj, start, n);
    vector<int> vis(n + 1, 0);
    cout << "\nDFS of the given graph is:  " << endl;
    parallelDFS(adj, vis, start);
    return 0;
}
