#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recStack)
{
    if (recStack[u])
        return true;

    if (visited[u])
        return false;

    visited[u] = true;
    recStack[u] = true;

    for (int x : adj[u])
    {
        if (isCyclicUtil(adj, x, visited, recStack))
            return true;
    }

    recStack[u] = false;
    return false;
}

vector<vector<int>> constructadj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &it : edges)
    { 
        adj[it[0]].push_back(it[1]); 
    }
    return adj;
}

bool isCyclic(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj = constructadj(V, edges);

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCyclicUtil(adj, i, visited, recStack))
            return true; 
    }

    return false; 
}

int main()
{
    int V = 4; 

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};

    cout << (isCyclic(V, edges) ? "true" : "false") << endl;

    return 0;
}