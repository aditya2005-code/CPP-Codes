#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int sum=0;
    for(int i=1 ; i<n ;i++){
       cout<<i<<"\t";
       sum+=i;
    }
    cout<<endl<<"The sum is :"<<sum;
    return 0;
}
