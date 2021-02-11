#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int __findTargetSumWays(vector<int>& nums, int index, int sum,
                        unordered_map<string, int>& memo, int target) {
    if (index == nums.size()) {
        if (sum == target) return 1;

        return 0;
    }

    string key = to_string(index) + ',' + to_string(sum);

    if (memo.find(key) != memo.cend()) return memo[key];

    return memo[key] = __findTargetSumWays(nums, index + 1, sum + nums[index],
                                           memo, target) +
                       __findTargetSumWays(nums, index + 1, sum - nums[index],
                                           memo, target);
}

int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<string, int> memo;
    return __findTargetSumWays(nums, 0, 0, memo, target);
}

int findTargetSumWaysDP(vector<int>& nums, int target) {
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }

    if (sum < target || (sum + target) % 2 == 1) return 0;

    sum = (sum + target) / 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= nums.size(); ++i) dp[i][0] = 1;

    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[nums.size()][sum];
}

int main() {
    vector<int> nums = {1, 3, 1, 4, 2};

    assert(findTargetSumWays(nums, 5) == 3);
    assert(findTargetSumWays(nums, 11) == 1);

    assert(findTargetSumWaysDP(nums, 5) == 3);
    assert(findTargetSumWaysDP(nums, 11) == 1);
    return 0;
}