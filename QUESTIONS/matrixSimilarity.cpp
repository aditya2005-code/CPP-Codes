#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k = k % m; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i % 2 == 0) {
                    if (mat[i][j] != mat[i][(j + k) % m]) return false;
                } 
                else {
                    if (mat[i][j] != mat[i][(j - k + m) % m]) return false;
                }

            }
        }
        return true;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cin >> k;

    Solution obj;
    bool result = obj.areSimilar(mat, k);

    if (result) cout << "true\n";
    else cout << "false\n";

    return 0;
}