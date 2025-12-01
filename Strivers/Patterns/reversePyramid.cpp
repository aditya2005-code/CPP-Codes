#include<bits/stdc++.h>
using namespace std;

void triangle(int n){
    for(int i=n-1 ; i>=0 ; i--){
        for(int k = 0 ; k < n-i-1 ; k++){
            cout <<" ";
        }
        for(int j = 0 ; j<2*i+1 ; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;

    triangle(n);

    return 0;
}