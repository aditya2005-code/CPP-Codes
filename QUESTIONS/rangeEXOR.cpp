#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1000000007;
    #define ll long long
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (auto &t : queries) {
            int l = t[0];
            int r = t[1];
            int k = t[2];
            int v = t[3];
            int idx = l;
            while (idx <= r) {
                ll temp = nums[idx];
                nums[idx] = (temp * v) % mod;
                idx += k;
            }
        }
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> queries = {
        {0, 4, 1, 2},  // multiply all elements by 2
        {1, 3, 2, 3}   // multiply indices 1 and 3 by 3
    };

    int result = sol.xorAfterQueries(nums, queries);

    cout << "Final XOR: " << result << endl;

    return 0;
}