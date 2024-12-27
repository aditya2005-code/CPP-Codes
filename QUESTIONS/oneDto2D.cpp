#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n(even) : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements of the array:";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    int rows,cols,k=0;
    cout<<"\nEnter the rows and cols :";
    cin>>rows>>cols;
    int arr2[rows][cols];
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if(k<n){
            arr2[i][j]=arr[k];
            k++;
            }
        }
    }

    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
    
}