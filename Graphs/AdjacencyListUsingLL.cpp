#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void insertEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printgraph(){
        for(int i=0 ; i < V ; i++){
            cout << i <<"->";
            for(auto node : l[i]){
                cout << node <<",";
            }
        }
    }
};

int main(){
    Graph graph(4);
    graph.insertEdge(0 , 1);
    graph.insertEdge(0 , 2);    
    graph.insertEdge(1 , 2);
    graph.insertEdge(2 , 3);
    graph.printgraph();
    return 0;
}