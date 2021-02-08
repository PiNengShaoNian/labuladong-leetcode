#include <string>
#include <unordered_map>

using namespace std;

int __superEggDrop(int k, int n, unordered_map<string, int> &memo) {
    if (k == 1) return n;
    if (n == 0) return 0;

    int res;
    string key = to_string(k) + ',' + to_string(n);

    if (memo.find(key) != memo.cend()) return memo[key];

    for (int i = 1; i <= n; ++i) {
        res = min(res, max(__superEggDrop(k - 1, i - 1, memo),
                           __superEggDrop(k, i + 1, memo)) +
                           1);
    }

    return memo[key] = res;
}

int superEggDrop(int k, int n) {
    unordered_map<string, int> memo;
    return __superEggDrop(k, n, memo);
}

int main() { return 0; }