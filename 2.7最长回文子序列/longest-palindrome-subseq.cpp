#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestPaliandromeSubseq(const string& str) {
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));

    for (int i = 0; i < str.length(); ++i) {
        dp[i][i] = 1;
    }

    for (int i = str.length() - 2; i >= 0; --i) {
        for (int j = i + 1; j < str.length(); ++j) {
            if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][str.length() - 1];
}

int longestPaliandromeSubseq1(const string& str) {
    vector<int> dp(str.length(), 1);

    for (int i = str.length() - 2; i >= 0; --i) {
        int pre = 0;
        for (int j = i + 1; j < str.length(); ++j) {
            int temp = dp[j];
            if (str[i] == str[j]) {
                dp[j] = pre + 2;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }

            pre = temp;
        }
    }

    return dp[str.length() - 1];
}

int main() {
    assert(longestPaliandromeSubseq("aba") == 3);
    assert(longestPaliandromeSubseq("abfindoutba") == 5);

    assert(longestPaliandromeSubseq1("aba") == 3);
    assert(longestPaliandromeSubseq1("abfindoutba") == 5);
}