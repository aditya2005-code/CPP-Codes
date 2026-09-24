#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int i = 0, j = 0;
        unordered_map<int, int> freq;

        int res = 0;

        while (i < n) {

            // Add current element
            freq[fruits[i]]++;

            // Shrink if more than 2 distinct elements
            while (freq.size() > 2) {

                freq[fruits[j]]--;

                // Remove key if frequency becomes 0
                if (freq[fruits[j]] == 0) {
                    freq.erase(fruits[j]);
                }

                j++;
            }

            // Update answer
            res = max(res, i - j + 1);

            i++;
        }

        return res;
    }
};

int main() {
    vector<int> arr = {1, 2, 2, 1, 2, 3, 3, 3, 3};

    Solution s;

    cout << "The result is : " << s.totalFruit(arr);

    return 0;
}