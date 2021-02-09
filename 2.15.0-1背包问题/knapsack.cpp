#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int N = weights.size();
    vector<vector<int>> dp(N + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i < N + 1; ++i) {
        for (int w = 1; w < capacity + 1; ++w) {
            if (w >= weights[i - 1]) {
                dp[i][w] = max(dp[i - 1][w],
                               dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[N][capacity];
}

int main() {
    vector<int> weights = {2, 1, 3};
    vector<int> values = {4, 2, 3};

    assert(knapsack(weights, values, 4) == 6);
    assert(knapsack(weights, values, 5) == 7);
    return 0;
}