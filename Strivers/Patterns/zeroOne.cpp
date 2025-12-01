#include<bits/stdc++.h>
using namespace std;

void zeroOne(int n){
    for(int i = 1 ; i<=n ; i++){
        int start;
        if( i % 2 == 0){
            start = 0;
        }
        else{
            start = 1;
        }
        for(int j = 1 ; j<=i ; j++){
            cout<< start % 2;
            start++;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;

    zeroOne(n);

    return 0;
}