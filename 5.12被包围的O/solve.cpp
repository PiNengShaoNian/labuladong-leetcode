#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &board, int row, int col) {
    int rows = board.size();
    int columns = board[0].size();

    if (row >= rows || rows < 0 || col >= columns || col < 0) return;

    if (board[row][col] != 'O') return;

    board[row][col] = '#';

    dfs(board, row - 1, col);
    dfs(board, row, col + 1);
    dfs(board, row + 1, col);
    dfs(board, row, col - 1);
}

void solve(vector<vector<char>> &board) {
    int rows = board.size();
    int columns = board[0].size();
    for (int i = 0; i < rows; ++i) {
        dfs(board, i, 0);
        dfs(board, i, columns - 1);
    }

    for (int i = 0; i < columns; ++i) {
        dfs(board, 0, i);
        dfs(board, rows - 1, i);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X'}, {'X', 'O', 'X'}, {'X', 'X', 'X'}};

    solve(board);

    cout << board[1][1] << endl;
}