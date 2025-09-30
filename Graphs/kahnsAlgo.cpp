#include <bits/stdc++.h>
using namespace std;

void insertEdges(vector<vector<int>> &graph, int u, int v, vector<int> &indegree)
{
    graph[u].push_back(v);
    indegree[v]++;
}

void subtractIndegree(vector<int> &indegree, int curr, vector<vector<int>> &graph, queue<int> &q)
{

    for (int v : graph[curr])
    {
        indegree[v]--;
        if (indegree[v] == 0)
        {
            q.push(v);
        }
    }
}

vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    // code here
    vector<vector<int>> graph(V);
    vector<int> indegree(V, 0);

    for (auto nums : edges)
    {
        insertEdges(graph, nums[0], nums[1], indegree);
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> res;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        subtractIndegree(indegree, curr, graph, q);
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