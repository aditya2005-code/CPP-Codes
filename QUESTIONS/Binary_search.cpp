#include<iostream>
using namespace std;

void Enter_elements(int arr[],int n){
    cout<<"Enter the elements:";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void Bubble_sort(int arr[],int n)
{
    int temp;

    for(int i=0; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int Binary_search(int arr[],int n,int key)
{
    int beg=0,end=n-1,mid;

    while(beg<=end)
    {
        mid=(beg+end)/2;

        for(int i=0; i<n ; i++)
        {
            if(arr[mid]==key){
                return 1;
            }
            else if(arr[mid]>key){
                end=mid-1;
            }
            else{
                beg=mid+1;
            }
        }
    }
    return 0;

}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int arr[n];

    Enter_elements(arr,n);

    int key;
    cout<<"Enter the key:";
    cin>>key;

    Bubble_sort(arr,n);

    int result= Binary_search(arr,n,key);

    if(result!=0){
        cout<<"The value is found";
    }
    else{
        cout<<"Value not found";
    }
    return 0;
}