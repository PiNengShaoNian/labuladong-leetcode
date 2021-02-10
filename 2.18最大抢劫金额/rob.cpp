#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int __rob(vector<int>& nums, int start, vector<int>& memo) {
    if (start >= nums.size()) return 0;

    if (memo[start] != -1) return memo[start];

    int res = max(__rob(nums, start + 1, memo),
                  nums[start] + __rob(nums, start + 2, memo));

    return memo[start] = res;
}

int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);

    return __rob(nums, 0, memo);
}

int rob1(vector<int>& nums) {
    vector<int> dp(nums.size() + 2, 0);

    for (int i = nums.size() - 1; i >= 0; --i) {
        dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
    }

    return dp[0];
}

int main() {
    vector<int> nums = {2, 1, 7, 9, 3, 1};

    cout << rob(nums) << endl;
    assert(rob(nums) == 12);
    assert(rob1(nums) == 12);

    return 0;
}