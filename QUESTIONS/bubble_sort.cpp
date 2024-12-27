#include<iostream>
using namespace std;

void Enter_elements(int arr[],int n){
    cout<<"Enter the elements:";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void Bubble_sort(int arr[], int n)
{
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main()
{
    int n;
    cout<<"Enter thhe value of n";
    cin>>n;

    int arr[n];

    Enter_elements(arr,n);

    Bubble_sort(arr,n);
    cout<<endl;
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}