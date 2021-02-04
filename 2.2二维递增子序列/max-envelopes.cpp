#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void getNextEnvelopes(vector<pair<int, int>> &envelopes, bool used[], int index,
                      vector<int> &result) {
    for (int i = 0; i < envelopes.size(); ++i) {
        if (!used[i] && envelopes[i].first < envelopes[index].first &&
            envelopes[i].second < envelopes[index].second) {
            result.push_back(i);
        }
    }
}

int __maxEnvelopes(vector<pair<int, int>> &envelopes, bool used[], int index,
                   unordered_map<int, int> &memo) {
    if (memo.find(index) != memo.cend()) return memo[index];

    if (index >= envelopes.size()) return 0;

    int result = 1;
    vector<int> nextEnve;
    getNextEnvelopes(envelopes, used, index, nextEnve);

    for (int i = 0; i < nextEnve.size(); ++i) {
        used[nextEnve[i]] = true;
        result =
            max(result, 1 + __maxEnvelopes(envelopes, used, nextEnve[i], memo));
        used[nextEnve[i]] = false;
    }

    return memo[index] = result;
}

int maxEnvelopes(vector<pair<int, int>> &envelopes) {
    int result = 0;
    bool *used = new bool[envelopes.size()];
    fill_n(used, envelopes.size(), false);
    unordered_map<int, int> memo;
    for (int i = 0; i < envelopes.size(); ++i) {
        used[i] = true;
        result = max(result, __maxEnvelopes(envelopes, used, i, memo));
        used[i] = false;
    }

    delete[] used;
    return result;
}

int main() {
    vector<pair<int, int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};

    cout << maxEnvelopes(envelopes) << endl;
    assert(maxEnvelopes(envelopes) == 3);
}