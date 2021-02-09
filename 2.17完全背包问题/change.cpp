#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int> &coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i < coins.size() + 1; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= coins.size(); ++i) {
        for (int w = 1; w <= amount; ++w) {
            if (w >= coins[i - 1]) {
                dp[i][w] = dp[i - 1][w] + dp[i][w - coins[i - 1]];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[coins.size()][amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    assert(change(5, coins) == 4);
}