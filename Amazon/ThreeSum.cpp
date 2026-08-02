#include <bits/stdc++.h>
using namespace std;

// -------------------- Brute Force --------------------
vector<vector<int>> threeSumBrute(vector<int> nums) {
    set<vector<int>> st;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {

                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

// -------------------- Optimal --------------------
vector<vector<int>> threeSumOptimal(vector<int> nums) {

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {

        // Skip duplicate first element
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                ans.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;

                // Skip duplicate second element
                while (left < right && nums[left] == nums[left - 1])
                    left++;

                // Skip duplicate third element
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return ans;
}

// -------------------- Print Function --------------------
void printResult(vector<vector<int>> &ans) {

    if (ans.empty()) {
        cout << "No Triplets Found\n";
        return;
    }

    for (auto &triplet : ans) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
}

// -------------------- Main --------------------
int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Brute Force Solution:\n";
    vector<vector<int>> brute = threeSumBrute(nums);
    printResult(brute);

    cout << "\nOptimal Solution:\n";
    vector<vector<int>> optimal = threeSumOptimal(nums);
    printResult(optimal);

    return 0;
}