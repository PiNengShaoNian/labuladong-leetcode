#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minInsertions(const string &str) {
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));

    for (int i = str.length() - 2; i >= 0; --i) {
        for (int j = i + 1; j < str.length(); ++j) {
            if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[0][str.length() - 1];
}

int main() {
    assert(minInsertions("abcea") == 2);
    assert(minInsertions("aba") == 0);
}