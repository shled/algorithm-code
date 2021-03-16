#include "solution.h"

vector<vector<string>> Solution::solveNQueens(int n) {
    res.clear();
    vector<string> board(n, string(n, '.'));
    backtrack(0, board);
    return res;
}

void Solution::backtrack(int row, vector<string>& board) {
    if (row == board.size()) {
        res.push_back(board);
    } else {
        for (int col = 0; col < board.size(); col++) {
            if (!is_valid(row, col, board)) {
                continue;
            }
            board[row][col] = 'Q';
            backtrack(row + 1, board);
            board[row][col] = '.';
        }
    }
}

bool Solution::is_valid(int row, int col, vector<string>& board) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}