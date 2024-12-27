#include<iostream>
using namespace std;

void Input_array(int arr[], int n) {
    cout << "\nEnter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void Insertion_Sort(int arr[],int n)
{
    for(int i=1 ; i<n ;i++){
        
        int current=arr[i];
        int prev=i-1;

        while(prev>=0 && arr[prev]>current){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=current;
    }
}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int arr[n];

    Input_array(arr,n);

    Insertion_Sort(arr,n);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }

    return 0;
}