#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
int __maxA(int N, int aNum, int copy, unordered_map<string, int> &memo) {
    if (N < 0) return 0;
    if (N == 0) return aNum;
    string key = to_string(N) + ',' + to_string(aNum) + ',' + to_string(copy);
    if (memo.find(key) != memo.cend()) return memo[key];

    int result = max(max(__maxA(N - 1, aNum + 1, copy, memo),
                         __maxA(N - 2, aNum, aNum, memo)),
                     __maxA(N - 1, aNum + copy, copy, memo));

    return memo[key] = result;
}

int maxA(int N) {
    unordered_map<string, int> memo;
    return __maxA(N, 0, 0, memo);
}

int maxA1(int N) {
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1;

        for (int j = 2; j < i; ++j) {
            dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
        }
    }

    return dp[N];
}

int main() {
    assert(maxA(3) == 3);
    assert(maxA(7) == 9);
    assert(maxA1(3) == 3);
    assert(maxA1(7) == 9);
}