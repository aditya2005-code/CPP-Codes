#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> paths;

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i == n - 1 && j == m - 1) return true;

        vis[i][j] = true;

        int type = grid[i][j];

        for (size_t k = 0; k < paths[type].size(); ++k) {
            int dx = paths[type][k].first;
            int dy = paths[type][k].second;
            int ni = i + dx;
            int nj = j + dy;

            if (!isValid(ni, nj, n, m) || vis[ni][nj]) continue;

            int nextType = grid[ni][nj];

            for (size_t l = 0; l < paths[nextType].size(); ++l) {
                int rdx = paths[nextType][l].first;
                int rdy = paths[nextType][l].second;
                if (rdx == -dx && rdy == -dy) {
                    if (dfs(grid, vis, ni, nj)) return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        paths[1] = {{0,-1}, {0,1}};
        paths[2] = {{1,0}, {-1,0}};
        paths[3] = {{0,-1}, {1,0}};
        paths[4] = {{0,1}, {1,0}};
        paths[5] = {{0,-1}, {-1,0}};
        paths[6] = {{0,1}, {-1,0}};

        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        return dfs(grid, vis, 0, 0);
    }
};