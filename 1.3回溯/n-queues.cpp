#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

void generateBoard(vector<string>& board, vector<int>& row) {
    for (int i = 0; i < row.size(); ++i) {
        string str(row.size(), '.');
        str[row[i]] = 'Q';
        board.push_back(str);
    }
}

void _solveNQueues(int n, int index, vector<int>& row, bool col[], bool dia1[],
                   bool dia2[], vector<vector<string>>& result) {
    if (n == index) {
        vector<string> board;
        generateBoard(board, row);
        result.push_back(board);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
            col[i] = true;
            dia1[index + i] = true;
            dia2[index - i + n - 1] = true;
            row.push_back(i);
            _solveNQueues(n, index + 1, row, col, dia1, dia2, result);
            col[i] = false;
            dia1[index + i] = false;
            dia2[index - i + n - 1] = false;
            row.pop_back();
        }
    }
}

void solveNQueues(int n, vector<vector<string>>& result) {
    bool* col = new bool[n];
    bool* dia1 = new bool[n];
    bool* dia2 = new bool[n];
    vector<int> row;
    uninitialized_fill_n(col, n, false);
    uninitialized_fill_n(dia1, n, false);
    uninitialized_fill_n(dia2, n, false);

    _solveNQueues(n, 0, row, col, dia1, dia2, result);

    delete[] col;
    delete[] dia1;
    delete[] dia2;
}

int main() {
    vector<vector<string>> result;
    solveNQueues(5, result);

    cout << result.size() << endl;

    string s = "sdfsd";

    for (vector<string> board : result) {
        for (string line : board) {
            cout << line << endl;
        }

        cout << endl;
    }
}