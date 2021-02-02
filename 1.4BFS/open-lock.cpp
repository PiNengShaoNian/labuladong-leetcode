#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int openLock(const string& target, vector<string>& deadends) {
    unordered_set<string> visited;
    for (string end : deadends) {
        visited.insert(end);
    }

    queue<string> states;
    states.push("0000");
    visited.insert("0000");
    int times = 0;

    while (states.size()) {
        size_t size = states.size();
        for (int i = 0; i < size; ++i) {
            string cur = states.front();
            states.pop();

            if (cur == target) return times;

            for (int j = 0; j < cur.length(); ++j) {
                string next = cur;
                if (next[j] == '9')
                    next[j] = '0';
                else
                    next[j] += 1;

                if (visited.find(next) == visited.cend()) {
                    visited.insert(next);
                    states.push(next);
                }

                next = cur;
                if (next[j] == '0')
                    next[j] = '9';
                else
                    next[j] -= 1;
                if (visited.find(next) == visited.cend()) {
                    visited.insert(next);
                    states.push(next);
                }
            }
        }
        ++times;
    }

    return -1;
}

int main() {
    vector<string> deadends = {"1234", "5678"};
    vector<string> deadends1 = {"8887", "8889", "8878", "8898",
                                "8788", "8988", "7888", "9888"};

    assert(openLock("0009", deadends) == 1);
    assert(openLock("8888", deadends1) == -1);
    return 0;
}