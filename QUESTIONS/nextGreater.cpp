#include <iostream>
#include <stack>
#include <vector>
#include<algorithm>
using namespace std;

void nextGreater(vector<int> &arr)
{
    stack<int> s;
    vector<int> res(arr.size());
    int n = arr.size();
    res.push_back(-1);
    s.push(arr[n-1]);
    for(int i = n-2 ; i>=0 ; i--){
        int current = arr[i];
        while(!s.empty() && s.top() <= current){
            s.pop();
        }
        if(s.empty()){
            res.push_back(-1);
        }
        else res.push_back(s.top());
        s.push(current);
    }
    reverse(res.begin(),res.end());
    cout<<endl;
    for(int i=0 ; i<res.size() ; i++){
        cout<<res[i]<<" ";
    }
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
    nextGreater(arr);
    return 0;
}
