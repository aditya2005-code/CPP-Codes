#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int E;
    cin >> E;

    int maxNode = 0;
    vector<int> curr(2*E+2), targ(2*E+2);
    vector<bool> vis(2*E+2, false);

    for(int i=0;i<E;i++){
        int a,b; cin>>a>>b;
        curr[a]=b;
        maxNode = max({maxNode,a,b});
    }

    for(int i=0;i<E;i++){
        int a,b; cin>>a>>b;
        targ[a]=b;
        maxNode = max({maxNode,a,b});
    }

    int rotations=0;
    for(int i=1;i<=maxNode;i++){
        if(!vis[i] && targ[i]){
            int x=i;
            do{
                vis[x]=true;
                x=targ[x];
            }while(x!=i);
            rotations++;
        }
    }

    cout << rotations << "\n";
    return 0;
}