bool __solveSudoku(char board[9][9], int row, int col, bool rowMap[9][9],
                   bool colMap[9][9], bool blockMap[9][9]) {
    if (col == 9) {
        return __solveSudoku(board, row, col, rowMap, colMap, blockMap);
    }

    if (row == 9) {
        return true;
    }

    if (board[row][col] != '.') {
        return __solveSudoku(board, row, col, rowMap, colMap, blockMap);
    }

    for (char c = '1'; c <= '9'; ++c) {
        int blockIndex = row / 3 * 3 + col / 3;
        if (rowMap[row] || colMap[col] || blockMap[blockIndex]) continue;

        rowMap[row][c - '1'] = true;
        colMap[col][c - '1'] = true;
        blockMap[blockIndex][c - '1'] = true;

        if (__solveSudoku(board, row, col, rowMap, colMap, blockMap))
            return true;

        rowMap[row][c - '1'] = false;
        colMap[col][c - '1'] = false;
        blockMap[blockIndex][c - '1'] = false;
        board[row][col] = '.';
    }

    return false;
}

void solveSudoku(char board[9][9]) {
    bool rowMap[9][9];
    bool colMap[9][9];
    bool blockMap[9][9];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            rowMap[i][j] = false;
            colMap[i][j] = false;
            blockMap[i][j] = false;
        }
    }

    __solveSudoku(board, 0, 0, rowMap, colMap, blockMap);
}

int main() { return 0; }