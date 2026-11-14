#include <bits/stdc++.h>
using namespace std;

bool hasSubArray(vector<int>& nums) {

    int n = nums.size();

    map<int, vector<int>> index;
    vector<int> prefix(n);

    prefix[0] = nums[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i-1] + nums[i];

    for (int i = 0; i < n; i++)
        index[nums[i]].push_back(i);

    for (auto &entry : index) {

        vector<int> &idx = entry.second;

        for (int j = 0; j < idx.size(); j++) {

            int i1 = idx[j];

            for (int k = j + 1; k < idx.size(); k++) {

                int i2 = idx[k];

                int middleSum = prefix[i2-1] - prefix[i1];

                if (nums[i1] == middleSum)
                    return true;
            }
        }
    }

    return false;
}

int main() {

    vector<int> arr = {4,1,3,4};

    cout << hasSubArray(arr);

    return 0;
}