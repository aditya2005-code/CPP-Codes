#include<iostream>
using namespace std;

void print_arr(int arr[],int n){
    cout<<"The elements of reversed array are :";
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}


void Enter_elements(int arr[],int n){

    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
}

void reverse_array(int arr[],int n)
{
    int start=0,end=n-1;
    int temp;

    while(start<end){   
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }

    print_arr(arr,n);
}


int main()
{
    int arr[100],n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"\nEnter the elements of the array:";
    Enter_elements(arr,n);
    reverse_array(arr,n);
    return 0;
}