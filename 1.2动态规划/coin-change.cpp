#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int index, int amount,
               unordered_map<string, int>& memo) {
    if (amount == 0) return 0;
    if (amount < coins[0] || index < 0) return -1;

    string key = to_string(index) + "-" + to_string(amount);
    if (memo.find(key) != memo.cend()) {
        return memo.find(key)->second;
    }

    int result = INT32_MAX;
    for (int i = amount / coins[index]; i >= 0; --i) {
        int temp =
            coinChange(coins, index - 1, amount - i * coins[index], memo);
        if (temp != -1) {
            //如果能通过更小的硬币组成amount但是又不比之前的结果小，那么可以剪枝
            if (result != INT32_MAX && temp + i > result)
                break;
            else
                result = min(result, temp + i);
        }
    }

    memo.insert({key, result});
    return result;
}

int coinChange(int amount, vector<int>& coins) {
    unordered_map<string, int> memo;
    return coinChange(coins, coins.size() - 1, amount, memo);
}

int coinChange1(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;
    for (int i = 0; i < dp.size(); ++i) {
        for (int coin : coins) {
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] != amount + 1 ? dp[amount] : -1;
}

int main() {
    vector<int> coins = {1, 2, 5};

    sort(coins.begin(), coins.end());
    cout << coinChange(11, coins) << endl;
    cout << coinChange(12, coins) << endl;

    assert(3 == coinChange(11, coins));
    assert(3 == coinChange(12, coins));
    assert(4 == coinChange(13, coins));
    assert(4 == coinChange(14, coins));
    assert(3 == coinChange(15, coins));
    assert(4 == coinChange(16, coins));

    assert(3 == coinChange1(11, coins));
    assert(3 == coinChange1(12, coins));
    assert(4 == coinChange1(13, coins));
    assert(4 == coinChange1(14, coins));
    assert(3 == coinChange1(15, coins));
    assert(4 == coinChange1(16, coins));
    return 0;
}