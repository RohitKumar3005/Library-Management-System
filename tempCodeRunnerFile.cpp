#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check left side of the current row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
    if (col >= n) {
        return true;  // All queens are placed successfully
    }

    for (int i = 0; i < n; ++i) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;  // Place the queen

            if (solveNQueensUtil(board, col + 1, n)) {
                return true;
            }

            board[i][col] = 0;  // Backtrack if solution not found
        }
    }

    return false;  // No safe position found in this column
}

bool solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));  // Initialize the board

    if (solveNQueensUtil(board, 0, n)) {
        // Print the solution
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    cout << "No solution exists for " << n << "-Queens problem." << endl;
    return false;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}