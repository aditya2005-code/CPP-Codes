// Leetcode 289
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlive(vector<vector<int>>& grid , int i , int j  , int alive){
        int n = grid.size();
        int m = grid[0].size();

        if( i+1 < n && grid[i+1][j] == 1) alive++;
        if( i-1 >= 0 && grid[i-1][j] == 1) alive++;
        if( j+1 < m && grid[i][j+1] == 1) alive++;
        if( j-1 >= 0 && grid[i][j-1] == 1) alive++;
        if( i+1 < n && j+1 < m && grid[i+1][j+1] == 1) alive++;
        if( i+1 < n && j-1 >= 0&& grid[i+1][j-1] == 1) alive++;
        if( i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 1) alive++;
        if( i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 1) alive++;

        cout<<alive<<" ";

        if(grid[i][j] == 1 && alive < 2) return false;
        if(grid[i][j] == 1 && (alive==2||alive==3)) return true;
        if(grid[i][j] == 1 && alive > 3) return false;
        if(grid[i][j] == 0 && alive == 3) return true;

        return false;

    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        map<pair<int,int>,bool> alive;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(isAlive(board , i , j ,  0)){
                    alive[{i,j}] = 1;
                }
            }
        }

        for(int i = 0  ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(alive[{i,j}] == 1){
                    board[i][j] = 1;
                }
                else{
                    board[i][j] = 0;
                }
            }
        }

        
    }
};

int main() {
    Solution obj;

    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };

    obj.gameOfLife(board);

    cout << "\nUpdated Board:\n";

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}