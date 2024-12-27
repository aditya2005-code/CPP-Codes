#include <iostream>
#include <vector>
using namespace std;

void printSudoku(vector<vector<int>>& arr) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>>& arr, int row, int col, int digit) {
    // Horizontal check
    for (int i = 0; i < 9; i++) {
        if (arr[row][i] == digit) {
            return false;
        }
    }

    // Vertical check
    for (int i = 0; i < 9; i++) {
        if (arr[i][col] == digit) {
            return false;
        }
    }

    // Subgrid check
    int srow = (row / 3) * 3;
    int scol = (col / 3) * 3;

    for (int i = srow; i < srow + 3; i++) {
        for (int j = scol; j < scol + 3; j++) {
            if (arr[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku_Solver(vector<vector<int>>& arr, int row, int col) {
    if (row == 9) {
        printSudoku(arr);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;
    if (col + 1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (arr[row][col] != 0) {
        return Sudoku_Solver(arr, nextRow, nextCol);
    }

    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(arr, row, col, digit)) {
            arr[row][col] = digit;
            if (Sudoku_Solver(arr, nextRow, nextCol)) {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> arr = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (!Sudoku_Solver(arr, 0, 0)) {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
