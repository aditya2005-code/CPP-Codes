#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        vector<int> dx = {-2 , -2 , 2 , 2 , 1, 1 , -1 , -1};
        vector<int> dy = {-1, 1, -1, 1, -2, 2, -2, 2};
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        queue<tuple<int,int,int>> q;
        
        // Convert to 0-based indexing
        int startX = knightPos[0] - 1;
        int startY = knightPos[1] - 1;
        int targetX = targetPos[0] - 1;
        int targetY = targetPos[1] - 1;
        
        q.push({startX, startY, 0});
        visited[startX][startY] = true;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int i = get<0>(curr);
            int j = get<1>(curr);
            int steps = get<2>(curr);
            
            if(i == targetX && j == targetY){
                return steps;
            }
            
            for(int k = 0; k < 8; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(ni >= 0 && nj >= 0 && ni < n && nj < n 
                   && !visited[ni][nj]){
                    
                    visited[ni][nj] = true;
                    q.push({ni, nj, steps + 1});
                }
            }
        }
        
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter board size (n): ";
    cin >> n;

    vector<int> knightPos(2), targetPos(2);

    cout << "Enter knight position (x y): ";
    cin >> knightPos[0] >> knightPos[1];

    cout << "Enter target position (x y): ";
    cin >> targetPos[0] >> targetPos[1];

    Solution obj;
    int result = obj.minStepToReachTarget(knightPos, targetPos, n);

    cout << "Minimum steps required: " << result << endl;

    return 0;
}