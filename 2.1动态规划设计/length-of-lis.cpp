#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    int res = 0;

    for (int i = 0; i < dp.size(); ++i) {
        res = max(res, dp[i]);
    }

    return res;
}

int lengthOfLIS1(vector<int> &nums) {
    int piles = 0;
    vector<int> top(nums.size(), 0);

    for (int i = 0; i < nums.size(); ++i) {
        int poker = nums[i];

        int l = 0;
        int r = piles;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (top[mid] > poker) {
                r = mid - 1;
            } else if (top[mid] < poker) {
                l = mid + 1;
            } else if (top[mid] == poker) {
                r = mid - 1;
            }
        }

        if (l > piles) l = r;

        if (l == piles) ++piles;

        top[l] = poker;
    }

    return piles;
}

int main() {
    vector<int> nums = {1, 4, 3, 4, 2};
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};

    assert(lengthOfLIS(nums) == 3);
    assert(lengthOfLIS(nums1) == 6);

    assert(lengthOfLIS1(nums) == 3);
    assert(lengthOfLIS1(nums1) == 6);
    return 0;
}