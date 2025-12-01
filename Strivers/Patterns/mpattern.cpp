#include<bits/stdc++.h>
using namespace std;

void mPattern(int n){
    
    for(int i=1 ; i<=n; i ++){
        for(int j = 1 ; j<= i ; j++ ){
            cout<<j;
        }

        for(int k = 0 ; k<=2*(n-i-1) ; k++){
            cout<<" ";
        }

        for(int l = 1 ; l <= i ; l++){
            cout<<l;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;

    mPattern(n);

    return 0;
}