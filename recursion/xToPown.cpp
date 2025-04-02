#include<iostream>
#include<vector>
using namespace std;

int powN(int n , int x ){
    if(n == 0){
        return 1;
    }
    return x*powN(n-1,x);
}


int main(){
    int n,x ;
    cout<<"Enter the valur of n and x:";
    cin>>n>>x;
    cout<<powN(n,x);
    return 0;
}