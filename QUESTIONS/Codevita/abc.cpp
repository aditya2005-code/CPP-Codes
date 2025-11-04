#include <bits/stdc++.h>
using namespace std;

int calcLCS(const vector<char> &src, const vector<char> &dst){
    int n1 = src.size(), n2 = dst.size();
    vector<int> memo(n2+1, 0);

    for(int i=1;i<=n1;i++){
        int leftUp = 0;
        for(int j=1;j<=n2;j++){
            int prevCell = memo[j];
            if(src[i-1] == dst[j-1]){
                memo[j] = leftUp + 1;
            }else{
                memo[j] = max(memo[j], memo[j-1]);
            }
            leftUp = prevCell;
        }
    }
    return memo[n2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sizeN;
    cin >> sizeN;
    vector<char> original(sizeN);
    for(int i=0;i<sizeN;i++){
        cin >> original[i];
    }

    vector<int> fixedIdx; 
    string token;
    while(cin >> token){
        fixedIdx.push_back(stoi(token));
    }

    int cntA=0,cntB=0,cntC=0;
    for(char ch: original){
        if(ch=='A') cntA++;
        else if(ch=='B') cntB++;
        else if(ch=='C') cntC++;
    }

    vector<char> orderABC = {'A','B','C'};
    long long bestAns = LLONG_MAX;
    bool found = false;

    sort(orderABC.begin(), orderABC.end());
    do{
        vector<char> build;
        for(char label: orderABC){
            int freq = (label=='A'?cntA:(label=='B'?cntB:cntC));
            for(int k=0;k<freq;k++) build.push_back(label);
        }
        if((int)build.size()!=sizeN) continue;

        bool valid = true;
        for(int pos: fixedIdx){
            if(pos<1 || pos>sizeN || original[pos-1]!=build[pos-1]){
                valid=false;
                break;
            }
        }
        if(!valid) continue;

        found = true;
        int needMoves = sizeN - calcLCS(original, build);
        bestAns = min(bestAns, (long long)needMoves);

    }while(next_permutation(orderABC.begin(), orderABC.end()));

    if(!found) cout<<"Impossible";
    else cout<<bestAns;
}
