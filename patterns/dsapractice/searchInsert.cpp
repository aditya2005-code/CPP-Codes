#include<iostream>
using namespace std;

void Enter_elements(int arr[],int n){
    cout<<"Enter the elements:";
    for(int i=0 ; i<=n ; i++){
        cin>>arr[i];
    }
    cout<<endl;
}

int Binary_search(int arr[] ,  int n , int key )
{
    int beg=0,end=n-1,mid;
    int index;

    while(beg<=end){
        mid=(beg+end)/2;

        if(arr[mid]==key){
            return index=mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }

        else{
            beg=mid+1;
        }
    }
    return -1;
}

int Insert_Element(int arr[], int n, int key)
{
    int ind;
    for(int i=0; i<n ; i++){
        if(arr[i]<key){
            ind=i+1;
        }
    }
    int k=0;
    int duplicate[k];
    for(int i=0; i<n ; i++){
        if(i==ind){
            duplicate[i]=key;
            k++;
        }
        else{
            duplicate[i]=arr[i];
            k++;
        }
    }
     n=k;
    for(int i=0; i<k ;i++){
        arr[i]=duplicate[i];
    }

    return n;

   
}

void Print_array(int arr[], int n){
    cout<<endl;
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }
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

    int result= Binary_search(arr,n,key);
    int res;
    if(result==-1){
        cout<<"\nKey not found";
        res=Insert_Element(arr,n,key);
        Print_array(arr,res);
    }
    else{
        cout<<"Key found at index "<<result;
    }


    

    return 0;


}