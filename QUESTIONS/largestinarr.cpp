#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int arr[n];
    cout<<"\nEnter the elements of array:";

    for(int i=0; i<n ; i++)
    {
        cin>>arr[i];
    }

    int max=0;

    for(int i=0 ; i<n ;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    cout<<"\nThe largest element in an array is :"<<max;
    return 0;
}