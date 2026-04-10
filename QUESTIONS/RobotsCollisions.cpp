#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths,
                                      string directions) {
        int n = positions.size();

        vector<pair<int, int>> nums; // {position, index}
        for (int i = 0; i < n; i++) {
            nums.push_back({positions[i], i});
        }

        sort(nums.begin(), nums.end());

        vector<int> health = healths;
        vector<bool> alive(n, true);

        while (true) {
            int right = -1;
            int left = -1;

            // find nearest R followed by L
            for (int i = 0; i < n; i++) {
                int idx = nums[i].second;

                if (!alive[idx] || health[idx] == 0) continue;

                if (directions[idx] == 'R') {
                    right = idx;
                } 
                else if (directions[idx] == 'L') {
                    if (right != -1) {
                        left = idx;
                        break;
                    }
                }
            }

            // no more collisions
            if (right == -1 || left == -1) break;

            // resolve collision
            if (health[right] > health[left]) {
                health[right]--;
                health[left] = 0;
                alive[left] = false;
            }
            else if (health[right] < health[left]) {
                health[left]--;
                health[right] = 0;
                alive[right] = false;
            }
            else {
                health[left] = 0;
                health[right] = 0;
                alive[left] = false;
                alive[right] = false;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (alive[i] && health[i] > 0) {
                res.push_back(health[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> positions = {3, 5, 2, 6};
    vector<int> healths = {10, 10, 15, 12};
    string directions = "RLRL";

    vector<int> result = sol.survivedRobotsHealths(positions, healths, directions);

    cout << "Surviving robots' healths: ";
    for (int h : result) {
        cout << h << " ";
    }
    cout << endl;

    return 0;
}