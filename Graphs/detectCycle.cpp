#include<bits/stdc++.h>
using namespace std;

void insertEdge(vector<vector<int>>& graph , int u , int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool cycleExists(vector<vector<int>>& graph , int u, int parent , vector<bool>& visited){
    visited[u] = true;

    for(int v : graph[u]){
        if(!visited[v]){
            if(cycleExists(graph , v , u , visited)){
                return true;
            }
        }
        else{
            if(v != parent){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cout << "Enter the number of vertices";
    cin>>n;
    vector<vector<int>> adj(n);
    
    insertEdge(adj , 0 , 1);
    insertEdge(adj , 1 , 2);
    insertEdge(adj , 2 , 3);
    insertEdge(adj , 3 , 0);

    vector<bool> visited(n , false);
    //for connected graph
    bool cycle = cycleExists(adj , 0 , -1 , visited);
    if(cycle){
        cout<<"Cycle Exxists"<<endl;
    }
    else{
        cout<<"Cycle doesnt exists"<<endl;
    }

    return 0;
}