#include<bits/stdc++.h>
using namespace std;


void heapify(vector<int>& arr , int n , int i){
    int left = 2*i +1;
    int right = 2*i+1;
    int largest = i;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(vector<int>& arr , int n){
    //Build heap
    for(int i=n/2-1 ; i >= 0 ; i--){
        heapify(arr,n,i);
    }

    for(int i=n-1 ; i>=0 ;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    vector<int> nums;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    nums.resize(n);
    cout << "Enter elements: ";
    for(int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    heapSort(nums,n);
    for(int i=0 ; i<n ; i++){
        cout << nums[i] << " ";
    }
    return 0;
}