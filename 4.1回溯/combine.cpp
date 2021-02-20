#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void __combine(int start, int n, int k, vector<int>& path,
               vector<vector<int>>& ans) {
    if (path.size() == k) {
        ans.push_back(path);
        return;
    }
    if (start > n) return;

    path.push_back(start);
    __combine(start + 1, n, k, path, ans);

    path.pop_back();
    __combine(start + 1, n, k, path, ans);
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    __combine(1, n, k, path, ans);
    return ans;
}

int main() {
    vector<vector<int>> result = combine(3, 2);

    for (vector<int>& v : result) {
        cout << v[0] << " " << v[1] << endl;
    }

    cout << result.size() << endl;

    return 0;
}