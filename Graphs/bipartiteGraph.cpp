#include <bits/stdc++.h>
using namespace std;

void insertEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool bipartite(vector<vector<int>>& graph, int u, int V) {
    vector<char> color(V, 'n'); // 'n' = not colored
    queue<int> q;
    q.push(u);
    color[u] = 'b';

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int c : graph[v]) {
            if (color[c] == 'n') {
                color[c] = (color[v] == 'b') ? 'w' : 'b';
                q.push(c);
            } else if (color[c] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V);
    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 3);
    insertEdge(graph, 3, 4);
    insertEdge(graph, 4, 0);

    if (bipartite(graph, 0, V))
        cout << "Graph is bipartite\n";
    else
        cout << "Graph is NOT bipartite\n";

    return 0;
}
