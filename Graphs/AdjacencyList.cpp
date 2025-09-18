#include<bits/stdc++.h>
using namespace std;

void insertEdge(vector<vector<int>> &graph , int u , int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void displayGraph(vector<vector<int>> graph)
{
    for(int i=0 ; i<graph.size() ; i++){
        cout<<i<<"->";
        for(int j=0 ; j<graph[i].size() ; j++){
            cout<<graph[i][j]<<" ";
        }
    }
}
int main(){
    vector<vector<int>> adj;
    
    cout<<"Enter number of vertices and edges: ";
    int n , m;
    cin >> n >> m;

    for(int i=0 ; i<n ; i++){
        adj.push_back({});
    }

    for(int i=0 ; i<m ; i++){
        int u , v;
        cin >> u >> v;
        insertEdge(adj , u , v);
    }
    
    displayGraph(adj);
    return 0;
}