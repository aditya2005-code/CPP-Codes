#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V = V;
        l= new list<int>[V];
    }

    void insertEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs(int v , vector<bool>& visited ){
        
        visited[v] = true;
        cout<<v<<" ";
        for(int n : l[v]){
            if(!visited[n]){
                dfs(n , visited );
            }
        }
    }
};


int main(){
    int V;
    cout <<"Enter the number of vertices:";
    cin>>V;
    Graph graph(V);

    graph.insertEdge(0,1);
    graph.insertEdge(0,2);
    graph.insertEdge(1,3);
    graph.insertEdge(2,4);
    graph.insertEdge(3,4);
    graph.insertEdge(3,5);
    graph.insertEdge(4,5);
    graph.insertEdge(5,6);
    cout<<endl;
    vector<bool> visited(V,false);
    graph.dfs(0,visited);
    return 0;
}