#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int flag=0;
    for(int i=2 ; i<n/2 ; i++){
          if(n%i==0){
            flag++;
            break;
          }
    }
    if(flag==0){
        cout<<"\nPrime number";
    }
    else{
        cout<<"Not prime";
    }
    return 0;
}