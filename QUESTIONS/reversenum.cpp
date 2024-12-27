#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int rem,res=0;
    while(n!=0){
         rem=n%10;
         res=res*10+rem;
         n/=10;
    }
    cout<<"The reverse num is:"<<res;
    return 0;
}