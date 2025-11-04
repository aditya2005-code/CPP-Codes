#include <bits/stdc++.h>
using namespace std;

struct BoxInfo{
    int r,c,h;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    vector<BoxInfo> B(N);
    for(int i=0;i<N;i++){
        cin>>B[i].r>>B[i].c>>B[i].h;
    }

    auto manhattan = [&](int p,int q)->int{
        return abs(B[p].r - B[q].r) + abs(B[p].c - B[q].c);
    };

    vector<vector<int>> adj(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(B[i].h < B[j].h){
                int d = manhattan(i,j);
                if(B[j].h - B[i].h >= d){
                    adj[i].push_back(j);
                }
            }
        }
    }

    vector<int> matchR(N,-1);

    function<bool(int,vector<char>&)> tryMatch = [&](int u, vector<char> &seen){
        for(int nxt: adj[u]){
            if(seen[nxt]) continue;
            seen[nxt] = 1;
            if(matchR[nxt] == -1 || tryMatch(matchR[nxt], seen)){
                matchR[nxt] = u;
                return true;
            }
        }
        return false;
    };

    int successful = 0;
    for(int i=0;i<N;i++){
        vector<char> used(N,0);
        if(tryMatch(i,used)) successful++;
    }

    int answer = N - successful;
    cout<<answer;
    return 0;
}
