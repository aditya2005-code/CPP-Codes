#include<bits/stdc++.h>
using namespace std;

void diamond(int n){
    for(int i=0 ; i<n ; i++){
        for(int k = 0 ; k < n-i-1 ; k++){
            cout <<" ";
        }

        for(int j = 0 ; j<2*i+1 ; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i = n-2 ; i>= 0 ; i--){
        for(int k = 0 ; k < n-i-1 ; k++){
            cout <<" ";
        }
        for(int j=0 ; j < 2*i+1 ; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;

    diamond(n);

    return 0;
}