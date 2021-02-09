#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int> &nums) {
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i) sum += nums[i];

    if (sum % 2 != 0) return false;

    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum / 2 + 1, false));

    for (int i = 0; i < nums.size() + 1; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i < nums.size() + 1; ++i) {
        for (int w = 1; w < sum / 2 + 1; ++w) {
            if (w >= nums[i - 1]) {
                dp[i][w] = dp[i - 1][w] || dp[i - 1][w - nums[i - 1]];
            } else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[nums.size()][sum / 2];
}

int main() {
    vector<int> nums1 = {5, 5, 2, 8};
    vector<int> nums2 = {5, 5, 8, 3};

    assert(canPartition(nums1) == true);
    assert(canPartition(nums2) == false);
}