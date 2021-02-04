#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int maxSubarray(vector<int>& nums) {
    int sum = 0;
    int maxSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum < 0) {
            sum = 0;
        } else if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}

int maxSubarray1(vector<int>& nums) {
    if (!nums.size()) return 0;

    vector<int> dp(nums.size());

    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    }

    int result = 0;

    for (int i = 0; i < dp.size(); ++i) {
        result = max(dp[i], result);
    }

    return result;
}

int main() {
    vector<int> nums = {-3, 1, 3, -1, 2, -4, 2};
    assert(maxSubarray(nums) == 5);
    assert(maxSubarray1(nums) == 5);
}