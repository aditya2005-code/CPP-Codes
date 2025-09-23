#include <bits/stdc++.h>
using namespace std;
void insertEdges(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}

void dfs(vector<vector<int>> &graph, int u, vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;

    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs(graph, v, visited, st);
        }
    }
    st.push(u);
}

vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(V);

    for (auto nums : edges)
    {
        insertEdges(graph, nums[0], nums[1]);
    }

    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, st);
        }
    }

    vector<int> res;

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main()
{
   vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
   vector<int> res = topoSort(4 , edges);

   cout<<"The result will be : ";

   for(int num : res){
    cout<<num<<" ";
   }
   return 0;
}