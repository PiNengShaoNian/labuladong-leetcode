#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int __robRange(vector<int> &nums, int start, int end) {
    vector<int> dp(nums.size() + 2, 0);

    for (int i = end; i >= start; --i) {
        dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
    }

    return dp[start];
}

int robRange(vector<int> &nums) {
    return max(__robRange(nums, 1, nums.size() - 1),
               __robRange(nums, 0, nums.size() - 2));
}

int main() {
    vector<int> nums = {2, 3, 2, 3, 2};

    cout << robRange(nums) << endl;
    assert(robRange(nums) == 6);
    return 0;
}