#include <bits/stdc++.h>
using namespace std;

// ---------- Helper: prefix "greater-than" counts ----------
// greater[i][x] = number of characters in s[0..i-1] that are
// alphabetically GREATER than character ('a' + x).
// Precomputed once in O(26*n), queried in O(1) afterwards.
vector<array<int,26>> buildGreater(const string &s) {
    int n = s.size();
    vector<array<int,26>> greater(n+1);
    greater[0].fill(0);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        for (int x = 0; x < 26; x++)
            greater[i+1][x] = greater[i][x] + (c > x ? 1 : 0);
    }
    return greater;
}

// Brute-force O(k^2) inversion counter, used only to validate merges.
int countInversions(const string &s) {
    int cnt = 0, k = s.size();
    for (int i = 0; i < k; i++)
        for (int j = i+1; j < k; j++)
            if (s[i] > s[j]) cnt++;
    return cnt;
}

// ---------- 1. Brute Force ----------
// Generates every interleaving that preserves the internal order of
// primary and secondary, scores each, returns the minimum.
// Exponential: C(n+m, n) merges. Only usable for small n, m (<= ~12-15).
int minConflictsBrute(const string &primary, const string &secondary) {
    int n = primary.size(), m = secondary.size();
    int best = INT_MAX;
    string path;
    path.reserve(n+m);

    function<void(int,int)> gen = [&](int i, int j) {
        if (i == n && j == m) {
            best = min(best, countInversions(path));
            return;
        }
        if (i < n) {
            path.push_back(primary[i]);
            gen(i+1, j);
            path.pop_back();
        }
        if (j < m) {
            path.push_back(secondary[j]);
            gen(i, j+1);
            path.pop_back();
        }
    };
    gen(0, 0);
    return best;
}

// ---------- 2. Memoization (Top-Down DP) ----------
int minConflictsMemo(const string &primary, const string &secondary) {
    int n = primary.size(), m = secondary.size();
    auto gP = buildGreater(primary);
    auto gS = buildGreater(secondary);

    vector<vector<int>> memo(n+1, vector<int>(m+1, -1));

    function<int(int,int)> solve = [&](int i, int j) -> int {
        if (i == 0 && j == 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int best = INT_MAX;
        if (i > 0) {
            int c = primary[i-1] - 'a';
            int added = gP[i-1][c] + gS[j][c];      // already-placed chars greater than primary[i-1]
            best = min(best, solve(i-1, j) + added);
        }
        if (j > 0) {
            int c = secondary[j-1] - 'a';
            int added = gP[i][c] + gS[j-1][c];      // already-placed chars greater than secondary[j-1]
            best = min(best, solve(i, j-1) + added);
        }
        return memo[i][j] = best;
    };

    return solve(n, m);
}

// ---------- 3. Tabulation (Bottom-Up DP) ----------
int minConflictsTab(const string &primary, const string &secondary) {
    int n = primary.size(), m = secondary.size();
    auto gP = buildGreater(primary);
    auto gS = buildGreater(secondary);

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        int c = primary[i-1] - 'a';
        int added = gP[i-1][c] + gS[0][c];
        dp[i][0] = dp[i-1][0] + added;
    }
    for (int j = 1; j <= m; j++) {
        int c = secondary[j-1] - 'a';
        int added = gP[0][c] + gS[j-1][c];
        dp[0][j] = dp[0][j-1] + added;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c1 = primary[i-1] - 'a';
            int fromP = dp[i-1][j] + gP[i-1][c1] + gS[j][c1];

            int c2 = secondary[j-1] - 'a';
            int fromS = dp[i][j-1] + gP[i][c2] + gS[j-1][c2];

            dp[i][j] = min(fromP, fromS);
        }
    }

    return dp[n][m];
}

// ---------- getMinimumConflicts (function signature matching the problem) ----------
int getMinimumConflicts(const string &primary, const string &secondary) {
    return minConflictsTab(primary, secondary); // use tabulation for actual submission
}

int main() {
    vector<tuple<string,string,int>> tests = {
        {"zc", "d", 2},
        {"dae", "add", 1}
    };

    for (auto &[primary, secondary, expected] : tests) {
        int b = minConflictsBrute(primary, secondary);
        int me = minConflictsMemo(primary, secondary);
        int t = minConflictsTab(primary, secondary);
        cout << "primary=\"" << primary << "\" secondary=\"" << secondary
             << "\" expected=" << expected
             << " brute=" << b << " memo=" << me << " tab=" << t << "\n";
    }

    // Uncomment to read from stdin like the actual OA:
    // string primary, secondary;
    // cin >> primary >> secondary;
    // cout << getMinimumConflicts(primary, secondary) << "\n";

    return 0;
}