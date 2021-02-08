#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int>& nums) {
    vector<int> points(nums.size() + 2, 0);
    points[0] = points[nums.size() + 1] = 1;

    for (int i = 1; i <= nums.size(); ++i) {
        points[i] = nums[i - 1];
    }

    vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));

    for (int i = nums.size() + 1; i >= 0; --i) {
        for (int j = i + 1; j < nums.size() + 2; ++j) {
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] +
                                             points[k] * points[j] * points[i]);
            }
        }
    }

    return dp[0][nums.size() + 1];
}

int main() {
    vector<int> nums = {1, 1, 2};
    cout << maxCoins(nums) << endl;
    return 0;
}