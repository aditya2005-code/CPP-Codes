#include<iostream>
using namespace std;

int main(){
    int n,rem=0,res=0;
    cout<<"Enter the value of n:";
    cin>>n;
    int orginal;
    orginal=n;
    while(n!=0){
         rem=n%10;
         res=res+rem*rem*rem;
         n/=10;
    }
    if(res==orginal)
    {
        cout<<"Armstrong";
    }
    else{
        cout<<"Not Armstrong";
    }
    return 0;
}