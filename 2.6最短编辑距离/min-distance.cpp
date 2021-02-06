#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int __minDistance(int i, int j, const string& str1, const string& str2,
                  vector<vector<int>>& memo) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (memo[i][j] != -1) return memo[i][j];

    int result = 0;
    if (str1[i] == str2[j])
        result = __minDistance(i - 1, j - 1, str1, str2, memo);
    else {
        result = min(min(__minDistance(i, j - 1, str1, str2, memo),
                         __minDistance(i - 1, j, str1, str2, memo)),
                     __minDistance(i - 1, j - 1, str1, str2, memo)) +
                 1;
    }

    return memo[i][j] = result;
}

int minDistance(const string& str1, const string& str2) {
    vector<vector<int>> memo(str1.length(), vector<int>(str2.length(), -1));

    return __minDistance(str1.length() - 1, str2.length() - 1, str1, str2,
                         memo);
}

int minDistance1(const string& str1, const string& str2) {
    vector<vector<int>> dp(str1.length() + 1,
                           vector<int>(str2.length() + 1, 0));

    for (int i = 1; i < str1.length(); ++i) {
        dp[i][0] = i;
    }

    for (int j = 1; j < str2.length(); ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= str1.length(); ++i) {
        for (int j = 1; j <= str2.length(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] =
                    min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[str1.length()][str2.length()];
}

int main() {
    assert(minDistance("intention", "execution") == 5);
    assert(minDistance("abc", "edf") == 3);
 
    assert(minDistance1("intention", "execution") == 5);
    assert(minDistance1("abc", "edf") == 3);
}