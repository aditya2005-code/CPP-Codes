#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void insertEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph(){
        for(int i=0 ; i<V ; i++){
            cout << i <<":";
            for(int u : l[i]){
                cout << u <<" ";
            }
            cout<<endl;
        }
    }

    void bfs(){
        vector<bool> visited(V);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout << curr <<" ";
            for(int v : l[curr]){
                
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
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
    graph.printGraph();
    cout<<endl;
    graph.bfs();
    return 0;
}