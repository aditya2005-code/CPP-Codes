#include<bits/stdc++.h>
using namespace std;

vector<int> K_Sub_Array_maximum(vector<int>& arr , int n , int k){
    vector<int> res;
    priority_queue<pair<int,int>> pq;

    for(int i=0 ; i<k ; i++){
        pq.push(make_pair(arr[i],i));
    }
    res.push_back(pq.top().first);
    for(int i=k ; i<n ; i++){
        pq.push(make_pair(arr[i],i));
        
        while(!pq.empty() && pq.top().second <= i-k){
            pq.pop();
        }
        res.push_back(pq.top().first);
    }
    return res;
}

int main(){
    int n , k;
    cout << "Enter the value on n:";
    cin >> n;
    cout<<"Enter the size of Sub Array:";
    cin >> k;
    vector<int> arr(n);
    cout<<"Enter the elements of the array:";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    vector<int> result = K_Sub_Array_maximum(arr,n,k);

    for(int i=0 ; i<result.size() ; i++){
        cout << result[i] << " ";
    }
    return 0;
}