#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int __jump(vector<int> &nums, int p, vector<int> &memo) {
    if (p >= nums.size() - 1) return 0;

    if (memo[p] != nums.size()) return memo[p];

    int steps = nums[p];

    for (int i = 1; i <= steps; ++i) {
        int res = __jump(nums, i + p, memo);
        memo[p] = min(memo[p], 1 + res);
    }

    return memo[p];
}

int jump(vector<int> &nums) {
    vector<int> memo(nums.size(), nums.size());

    return __jump(nums, 0, memo);
}

int jump1(vector<int> &nums) {
    int end = 0;
    int farthest = 0;

    int jumps = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
        farthest = max(farthest, nums[i] + i);

        if (i == end) {
            ++jumps;
            end = farthest;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << jump(nums) << endl;

    assert(jump(nums) == 2);
    assert(jump1(nums) == 2);
}