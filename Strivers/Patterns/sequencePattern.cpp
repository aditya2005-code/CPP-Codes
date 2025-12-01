#include<bits/stdc++.h>
using namespace std;

void sequencePattern(int n){
    int num = 1;
    for(int i = 1 ; i<=n ; i++){
        for(int j = 0 ; j <= i ; j++){
            cout<<num++;;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;

    sequencePattern(n);

    return 0;
}