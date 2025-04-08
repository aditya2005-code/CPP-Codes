#include <iostream>
#include <stack>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

void kLargestElement(vector<int> arr , int k){
    priority_queue<int> pq;

    for(int i=0 ; i<arr.size() ; i++){
        pq.push(arr[i]);
    }

    int i=1;
    while( i < k){
        pq.pop();
        i++;
    }
    cout<<pq.top();
}

int main()
{
    vector<int> arr;
    int n;
    cout << "Enter the size of the vector:" << endl;
    cin >> n;
    arr.resize(n);
    cout << "Enter the elements of the vector:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout<<"\nEnter the value of k :";
    cin>>k;
    kLargestElement(arr,k);
    return 0;
}
