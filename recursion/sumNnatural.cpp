#include<iostream>
using namespace std;

int Sum(int n){
    if(n == 0){
        return 0;
    }
    
    return n + Sum(n-1);
}


int main(){
    int n ;
    cout<<"Enter the valur of n:";
    cin>>n;

    cout<<endl;
    int res = Sum(n);
    cout<<res;
    return 0;
}