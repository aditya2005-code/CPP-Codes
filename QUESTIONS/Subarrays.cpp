#include<iostream>
using namespace std;

void Input_array(int arr[], int n)
{
    cout<<"\nEnter the elements of the array :";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
}

void Sub_arrays(int arr[], int n)
{
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            // cout<<arr[i]<<arr[j]<<" ";
            for(int k=i; k<=j ; k++){
                cout<<arr[k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int arr[n];

    Input_array(arr,n);
    
    Sub_arrays(arr,n);
}