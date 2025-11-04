#include <bits/stdc++.h>
using namespace std;

struct Point {
    int row, col;
    bool operator<(const Point &other) const {
        return row == other.row ? col < other.col : row < other.row;
    }
    bool operator==(const Point &other) const {
        return row == other.row && col == other.col;
    }
};

bool insideGrid(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

bool isValidPlacement(const vector<Point> &cells, const vector<string> &board, int R, int C) {
    for (size_t i = 0; i < cells.size(); i++) {
        const Point &p = cells[i];

        if (!insideGrid(p.row, p.col, R, C) || board[p.row][p.col] == 'B')
            return false;
    }
    return true;
}

bool checkBoundingSquare(const vector<Point> &oldCells, const vector<Point> &newCells) {
    vector<Point> combined = oldCells;
    combined.insert(combined.end(), newCells.begin(), newCells.end());
    int k = oldCells.size();

    vector<int> rows, cols;
    for (size_t i = 0; i < combined.size(); i++) {
        rows.push_back(combined[i].row);
        cols.push_back(combined[i].col);
    }

    int rmin = *min_element(rows.begin(), rows.end());
    int rmax = *max_element(rows.begin(), rows.end());
    int cmin = *min_element(cols.begin(), cols.end());
    int cmax = *max_element(cols.begin(), cols.end());

    return (rmax - rmin == k - 1) && (cmax - cmin == k - 1);
}

vector<vector<Point>> generatePossibleRotations(const vector<Point> &cells, const vector<string> &board, int R, int C) {
    int k = cells.size();
    vector<vector<Point>> results;

    bool horizontal = true;
    for (int i = 1; i < k; i++) {
        if (cells[i].row != cells[0].row) {
            horizontal = false;
            break;
        }
    }

    if (horizontal) {
        for (int r = 0; r <= R - k; r++) {
            vector<Point> temp;
            for (int i = 0; i < k; i++)
                temp.push_back(Point{r + i, cells[0].col});
            if (isValidPlacement(temp, board, R, C) && checkBoundingSquare(cells, temp))
                results.push_back(temp);
        }
    } else {
        for (int c = 0; c <= C - k; c++) {
            vector<Point> temp;
            for (int i = 0; i < k; i++)
                temp.push_back(Point{cells[0].row, c + i});
            if (isValidPlacement(temp, board, R, C) && checkBoundingSquare(cells, temp))
                results.push_back(temp);
        }
    }

    return results;
}

vector<vector<Point>> generateTranslations(const vector<Point> &cells, int R, int C) {
    vector<vector<Point>> translations;
    vector<pair<int, int>> directions;
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(1, 0));
    directions.push_back(make_pair(0, -1));
    directions.push_back(make_pair(0, 1));

    for (size_t d = 0; d < directions.size(); d++) {
        int dr = directions[d].first;
        int dc = directions[d].second;

        vector<Point> moved;
        for (size_t i = 0; i < cells.size(); i++)
            moved.push_back(Point{cells[i].row + dr, cells[i].col + dc});

        bool ok = true;
        for (size_t i = 0; i < moved.size(); i++)
            if (!insideGrid(moved[i].row, moved[i].col, R, C))
                ok = false;
        if (ok) translations.push_back(moved);
    }

    return translations;
}

int minMoves(vector<string> &board, int R, int C, vector<Point> start, vector<Point> target) {
    sort(start.begin(), start.end());
    sort(target.begin(), target.end());
    if (start == target) return 0;

    queue<pair<vector<Point>, int>> q;
    set<vector<Point>> visited;

    q.push(make_pair(start, 0));
    visited.insert(start);

    while (!q.empty()) {
        pair<vector<Point>, int> front = q.front(); q.pop();
        vector<Point> current = front.first;
        int dist = front.second;

        vector<vector<Point>> trans = generateTranslations(current, R, C);
        for (size_t i = 0; i < trans.size(); i++) {
            vector<Point> next = trans[i];
            if (!visited.count(next) && isValidPlacement(next, board, R, C)) {
                if (next == target) return dist + 1;
                visited.insert(next);
                q.push(make_pair(next, dist + 1));
            }
        }

        vector<vector<Point>> rotations = generatePossibleRotations(current, board, R, C);
        for (size_t i = 0; i < rotations.size(); i++) {
            vector<Point> rot = rotations[i];
            if (!visited.count(rot)) {
                if (rot == target) return dist + 1;
                visited.insert(rot);
                q.push(make_pair(rot, dist + 1));
            }
        }
    }

    return -1;
}

vector<Point> collectCells(vector<string> &board, char ch) {
    vector<Point> res;
    for (size_t r = 0; r < board.size(); r++)
        for (size_t c = 0; c < board[0].size(); c++)
            if (board[r][c] == ch)
                res.push_back(Point{int(r), int(c)});
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vector<string> board(R);
    for (int i = 0; i < R; i++)
        cin >> board[i];

    vector<Point> start = collectCells(board, 'L');
    vector<Point> target = collectCells(board, 'T');

    int ans = minMoves(board, R, C, start, target);
    if (ans != -1) cout << ans;
    else cout << "Impossible";
    return 0;
}
