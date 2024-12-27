#include<iostream>
using namespace std;

int fibnocii(int n){
    if (n==0 || n==1){
        return 1;
    }
    else{
        return fibnocii(n-1)+fibnocii(n-2);
    }
    
}

int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    for(int i=0; i<n ; i++){
        cout<<fibnocii(i)<<" ";
    }
    return 0;
    
}