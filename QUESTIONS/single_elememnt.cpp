#include<iostream>
using namespace std;

void Input_array(int arr[], int n)
{
    cout<<"\nEnter the elements of the array :";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
}

int Single_element(int arr[],int n)
{
    int count,result;

    for(int i=0 ; i<n ; i++){
        count=0;
        for(int j=0; j<n ; j++)
        {
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==1){
            result=arr[i];
        }
    }
    return result;
}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int arr[n];

    Input_array(arr,n);

    int res= Single_element(arr,n);

    if(res!=0){
        cout<<"\nElement which is single is "<<res;
    }
    else{
        cout<<"No single element";
    }
}