#include <bits/stdc++.h>
using namespace std;

int A, B;
vector<string> arr;

struct State {
    int row, col, dir, dist;
    State(int r, int c, int d, int distance) : row(r), col(c), dir(d), dist(distance) {}
};

bool check(int r, int c) {
    return r >= 0 && r < A && c >= 0 && c < B;
}

bool canPlace(int r, int c, int dir, int len) {
    if (dir == 0) {
        for (int j = 0; j < len; j++)
            if (!check(r, c+j) || arr[r][c+j]=='B') return false;
    } else {
        for (int i = 0; i < len; i++)
            if (!check(r+i, c) || arr[r+i][c]=='B') return false;
    }
    return true;
}

int main() {
    cin >> A >> B;
    arr.resize(A);
    for (int i = 0; i < A; i++) cin >> arr[i];

    vector<pair<int,int>> source, target;
    for (int i=0;i<A;i++)
        for (int j=0;j<B;j++){
            if(arr[i][j]=='I') source.push_back({i,j});
            if(arr[i][j]=='L') target.push_back({i,j});
        }

    int len = source.size();
    bool sourceHorizontal = source[0].first == source[1].first;
    bool targetHorizontal = target[0].first == target[1].first;

    int sRow = sourceHorizontal ? source[0].first : source[0].first;
    int sCol = sourceHorizontal ? source[0].second : source[0].second;
    int tRow = targetHorizontal ? target[0].first : target[0].first;
    int tCol = targetHorizontal ? target[0].second : target[0].second;

    bool visited[20][20][2] = {0};
    queue<State> q;
    q.push(State(sRow, sCol, sourceHorizontal?0:1, 0));
    visited[sRow][sCol][sourceHorizontal?0:1] = 1;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(!q.empty()){
        State u = q.front(); q.pop();
        if(u.row==tRow && u.col==tCol && u.dir==(targetHorizontal?0:1)){
            cout << u.dist << "\n";
            return 0;
        }

        for(int i=0;i<4;i++){
            int nr = u.row+dr[i];
            int nc = u.col+dc[i];
            if(!visited[nr][nc][u.dir] && canPlace(nr,nc,u.dir,len)){
                visited[nr][nc][u.dir] = 1;
                q.push(State(nr,nc,u.dir,u.dist+1));
            }
        }

        int nd = 1-u.dir;
        if(!visited[u.row][u.col][nd] && canPlace(u.row,u.col,nd,len)){
            visited[u.row][u.col][nd] = 1;
            q.push(State(u.row,u.col,nd,u.dist+1));
        }
    }

    cout << "Impossible\n";
    return 0;
}
