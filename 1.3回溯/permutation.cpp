#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
void _permutation(int index, vector<T>& elems, bool used[],
                  vector<vector<T>>& result, vector<T>& path) {
    if (index == elems.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < elems.size(); ++i) {
        if (used[i]) continue;
        used[i] = true;
        path[i] = elems[index];
        _permutation(index + 1, elems, used, result, path);
        used[i] = false;
    }
}

template <typename T>
void permutation(vector<T>& elems, vector<vector<T>>& result) {
    bool* used = new bool[elems.size()];
    uninitialized_fill(used, used + elems.size(), false);
    vector<T> path(elems.size());
    _permutation(0, elems, used, result, path);

    delete[] used;
}

int main() {
    vector<int> elems = {1, 2, 3};
    vector<vector<int>> result;
    permutation(elems, result);

    for (vector<int> p : result) {
        for (int i : p) {
            cout << i << " ";
        }

        cout << endl;
    }
    assert(result.size() == 6);

    result.clear();
    elems = {1, 2, 3, 4};
    permutation(elems, result);
    assert(result.size() == 24);
    return 0;
}