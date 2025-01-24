#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printArray(vector<int> vec){
    for(int i=0 ; i<vec.size() ; i++){
        cout<<vec[i]<<" ";

    }
    cout<<endl;
}

void maxArea(vector<int> arr, int n){
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    nsl[0] = -1;
    s.push(0);
    for(int i=1 ; i<n ; i++){
        int curr = arr[i];
        while(!s.empty() && curr <= arr[s.top()]){
             s.pop();
        }
        if(s.empty()) nsl[i]=-1;
        else nsl[i] = s.top();

        s.push(i);
    }
    printArray(nsl);
    while(!s.empty()){
        s.pop();
    }

    s.push(n-1);
    nsr[n-1] = n;
    for(int i=n-2 ; i>=0 ; i--){
        int curr = arr[i];
        while(!s.empty() && curr <= arr[s.top()]){
             s.pop();
        }
        if(s.empty()) nsr[i]=-1;
        else nsr[i] = s.top();

        s.push(i);
    }
    printArray(nsr);
    int area = 1;
    int maxAr = 0;
    for(int i=0 ; i<n ; i++){
        area = arr[i] * (nsr[i] - nsl[i] - 1);
        maxAr = max(maxAr,area);
    }
    cout<<"Max area is "<<maxAr;
}

int main(){
    vector<int> arr;
    int n;
    cout<<"Enter the value of n :";
    cin>>n;
    arr.resize(n);
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    maxArea(arr,n);
    return 0;
}