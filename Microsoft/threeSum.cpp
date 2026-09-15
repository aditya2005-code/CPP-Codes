#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Brute force: O(2^n)
    void solve(vector<int>& nums, int i, vector<int>& curr,
               vector<vector<int>>& res) {
        if (i >= nums.size() || curr.size() == 3) {
            if (curr.size() == 3) {
                int sum = accumulate(curr.begin(), curr.end(), 0);

                if (sum == 0)
                    res.push_back(curr);
            }
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;

            curr.push_back(nums[j]);
            solve(nums, j + 1, curr, res);
            curr.pop_back();
        }
    }

    // Brute force: O(n^3)
    vector<vector<int>> cubicSolution(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 1; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return res;
    }

    // Optimized: O(n^2)
    vector<vector<int>> quadraticSolution(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1])
                        j++;

                    while (j < k && nums[k] == nums[k - 1])
                        k--;

                    j++;
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        return quadraticSolution(nums);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // ---------------- Brute Force / Recursive ----------------
    vector<int> curr;
    vector<vector<int>> recursiveRes;

    vector<int> nums1 = nums;
    sort(nums1.begin(), nums1.end());

    obj.solve(nums1, 0, curr, recursiveRes);

    cout << "Recursive Solution:" << endl;
    for (auto &triplet : recursiveRes) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }

    // ---------------- Cubic Solution ----------------
    vector<int> nums2 = nums;
    sort(nums2.begin(), nums2.end());

    vector<vector<int>> cubicRes = obj.cubicSolution(nums2);

    cout << "\nCubic Solution:" << endl;
    for (auto &triplet : cubicRes) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }

    // ---------------- Quadratic Solution ----------------
    vector<int> nums3 = nums;

    vector<vector<int>> quadraticRes = obj.quadraticSolution(nums3);

    cout << "\nQuadratic Solution:" << endl;
    for (auto &triplet : quadraticRes) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}