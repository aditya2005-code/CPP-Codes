#include<iostream>
using namespace std;

void Input_array(int arr[],int n)
{
    cout<<"Enter the elements of the array:";
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
}

int Occurence(int arr[],int n)
{
    for(int i=0; i<n ; i++){
        for(int j=i+1; j<n ;j++){
            if(arr[i]==arr[j]){
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<endl;

    int arr[n];

    Input_array(arr,n);

    int result=Occurence(arr,n);

    if(result!=0){
        cout<<"\nTrue";
    }
    else{
        cout<<"\nFalse";
    }
    return 0;
}