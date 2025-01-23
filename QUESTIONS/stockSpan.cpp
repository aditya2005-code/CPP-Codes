#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpan(vector<int> &arr)
{
    stack<int> s;
    vector<int> res;
    res.push_back(1);
    s.push(0);
    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        int span = s.empty() ? (i + 1) : (i - s.top());
        res.push_back(span);

        s.push(i);
    }
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
    stockSpan(arr);
    return 0;
}
