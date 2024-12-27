#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the n more than 3 digit:";
    cin>>n;
    int rem,res=0;

    while(n!=0){
        rem=n%10;
        res+=rem;
        n/=10;
    }
    cout<<"\nThe result is:"<<res;
    return 0;
}