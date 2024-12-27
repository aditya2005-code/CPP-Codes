#include<iostream>
using namespace std;

void Enter_elements(char arr[],int n){
    cout<<"Enter the elements:";
    for(int i=0 ; i<=n ; i++){
        cin>>arr[i];
    }
    cout<<endl;
}



int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    char arr[n];

    Enter_elements(arr,n);


}