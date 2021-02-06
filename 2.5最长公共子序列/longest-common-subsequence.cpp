#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int __longestCommonSubsequence(int i, int j, const string& str1,
                               const string& str2,
                               unordered_map<string, int>& memo) {
    if (i < 0 || j < 0) return 0;

    string key = to_string(i) + "-" + to_string(j);
    if (memo.find(key) != memo.cend()) return memo[key];
    int result = 0;
    if (str1[i] == str2[j])
        result = __longestCommonSubsequence(i - 1, j - 1, str1, str2, memo) + 1;
    else {
        result = max(__longestCommonSubsequence(i - 1, j, str1, str2, memo),
                     __longestCommonSubsequence(i, j - 1, str1, str2, memo));
    }

    return memo[key] = result;
}

int longestCommonSubsequence(const string& str1, const string& str2) {
    unordered_map<string, int> memo;

    return __longestCommonSubsequence(str1.length() - 1, str2.length() - 1,
                                      str1, str2, memo);
}

int longestCommonSubsequence1(const string& str1, const string& str2) {
    vector<vector<int>> dp(str1.length() + 1,
                           vector<int>(str2.length() + 1, 0));

    for (int i = 1; i <= str1.length(); ++i) {
        for (int j = 1; j <= str2.length(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[str1.length()][str2.length()];
}

int main() {
    assert(longestCommonSubsequence("abcde", "aceb") == 3);
    assert(longestCommonSubsequence("1a2b3c4d", "aabbccdd") == 4);

    assert(longestCommonSubsequence1("abcde", "aceb") == 3);
    assert(longestCommonSubsequence1("1a2b3c4d", "aabbccdd") == 4);
    return 0;
}