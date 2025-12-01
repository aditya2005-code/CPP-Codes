#include<bits/stdc++.h>
using namespace std;

void butterfly(int n){
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            cout<<"*";
        }

        for(int k = 0 ; k < 2*(n-i-1) ; k++){
            cout<<" ";
        }

        for(int l = 0 ; l<=i ; l++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = 0 ; j<= i ; j++){
            cout<<"*";
        }

        for(int k = 0 ; k<2*(n-i-1) ; k++){
            cout<<" ";
        }

        for(int l = 0 ; l<= i ; l++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;

    butterfly(n);

    return 0;
}