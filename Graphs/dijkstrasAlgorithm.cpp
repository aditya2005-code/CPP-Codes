#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int v;
    int wt;

    Edge(int v , int wt){
        this->v = v;
        this->wt = wt;
    }
};

void dijkstraImplem(vector<vector<Edge>>& graph , int n){
    vector<int> dist(n , INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();

        for(Edge e : graph[curr.second]){
            if(dist[e.v] > curr.first + e.wt){  // use '>' not '<'
                dist[e.v] = curr.first + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    for(int num : dist){
        cout << num << " ";
    }
}

int main(){
    int n = 6;  // total vertices
    vector<vector<Edge>> graph(n);

    graph[0].push_back(Edge(1 , 2));
    graph[0].push_back(Edge(2 , 4));

    graph[1].push_back(Edge(2 , 1));
    graph[1].push_back(Edge(3 , 7));

    graph[2].push_back(Edge(4 , 3));

    graph[3].push_back(Edge(5 , 1));

    graph[4].push_back(Edge(3 , 2));
    graph[4].push_back(Edge(5 , 5));

    dijkstraImplem(graph , n);

    return 0;
}
