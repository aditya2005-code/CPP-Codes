#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> arr , int n=0){
    if( n == arr.size()-1){
        return true;
    }

    if(arr[n] > arr[n+1]){
        return false;
    }

    return isSorted(arr,n+1);
}

int main(){
    int n ;
    cout<<"Enter the valur of n:";
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    cout<<isSorted(arr);
    return 0;
}