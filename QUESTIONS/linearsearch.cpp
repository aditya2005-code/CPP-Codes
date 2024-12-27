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
    int key,index,flag=0;
    cout<<"\nEnter the key:";
    cin>>key;

    for(int i=0 ; i<n ; i++){
        if(arr[i]==key){
           flag++;
           index=i;
        }

    }
    if(flag==1){
        cout<<"Key found at index "<<index<<endl;
    }
    else{
        cout<<"Key not found:"<<endl;
    }
    return 0;
}