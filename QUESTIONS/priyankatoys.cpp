#include <bits/stdc++.h>
using namespace std;


void toys(vector<int> nums) {
    int n = nums.size();
    int count = 0;
    int j = 0;
    int i = 0;
    vector<pair<int, int>> res;

    for (int i = 0; i < n; i++) {
        res.push_back(make_pair(nums[i], i));
    }

    sort(res.begin(), res.end());

    vector<vector<int>> ans;

    while (i < n) {
        vector<int> box;
        int w = res[i].first + 4;

        while (i < n && res[i].first <= w) {
            box.push_back(res[i].second); 
            i++;
        }

        ans.push_back(box);
        count++;
    }
    cout<<"\n Total number of boxes required are : "<<count;
    cout << "\nThe indexes in each box are:\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << "Box " << i + 1 << " has toys at original indexes: ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int n;
    cout << "Enter the number of toys: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the weights: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    toys(arr);
    return 0;
}
