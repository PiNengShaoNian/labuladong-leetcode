#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int slidingPuzzle(vector<vector<int>> &board) {
    int steps = 0;
    queue<string> states;
    unordered_set<string> visited;

    string start;
    string target = "123450";

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            start.push_back(board[i][j] + '0');
        }
    }

    states.push(start);
    visited.insert(start);
    vector<vector<int>> neighbors = {{1, 3}, {0, 4, 2}, {1, 5},
                                     {0, 4}, {3, 1, 5}, {4, 2}};

    while (!states.empty()) {
        int size = states.size();

        for (int i = 0; i < size; ++i) {
            string str = states.front();
            states.pop();

            if (str == target) return steps;

            int index = 0;

            for (; str[index] != '0'; ++index)
                ;

            for (int neighbor : neighbors[index]) {
                string newBoard = str;
                swap(newBoard[neighbor], newBoard[index]);

                if (visited.find(newBoard) == visited.cend()) {
                    states.push(newBoard);
                    visited.insert(newBoard);
                }
            }
        }

        ++steps;
    }

    return -1;
}

int main() {
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    cout << slidingPuzzle(board) << endl;
}