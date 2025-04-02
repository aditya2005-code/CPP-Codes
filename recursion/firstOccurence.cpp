#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int> arr , int n, int key , int i){
    if(i == n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstOccurence(arr,n,key,i+1);
}
int lastOccurence(vector<int> arr , int key , int i){
    if( i < 0){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return lastOccurence(arr,key,i-1);
}

int main(){
    int n ;
    cout<<"Enter the valur of n:";
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"\n Enter the key";
    cin>>key;
    cout<<firstOccurence(arr,n,key,0)<<endl;
    cout<<lastOccurence(arr,key,n-1);
    return 0;
}