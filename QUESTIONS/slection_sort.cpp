#include<iostream>
using namespace std;

void Input_array(int arr[], int n) {
    cout << "\nEnter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void Insertion_sort(int arr[],int n)
{
    for(int i=0; i<n ; i++){
        int minimum=i;
        for(int j=i; j<n ; j++){
            if(arr[minimum] > arr[j]){
                minimum=j;
            }
           
        }
         swap(arr[i],arr[minimum]);
        
    }
}


int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;

    int arr[n];

    Input_array(arr,n);

    Insertion_sort(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}
