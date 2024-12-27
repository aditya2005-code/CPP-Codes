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
    int rev[n];
    int j=0;

    for(int i=n-1 ; i>=0 ; i--){
        rev[j]=arr[i];
        j++;
    }
    
    cout<<"\nThe elements of reverse array are:";

    for(int i=0; i<n ; i++){
        cout<<rev[i]<<" ";
    }
    return 0;
}