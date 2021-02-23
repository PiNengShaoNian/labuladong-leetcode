#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> twoSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums.size() - 1;
    vector<vector<int>> result;
    while (l < r) {
        int left = nums[l];
        int right = nums[r];
        int sum = left + right;

        if (sum < target) {
            while (l + 1 < r && nums[l] == left) ++l;
        } else if (sum > target) {
            while (r - 1 > l && nums[r] == right) --r;
        } else {
            result.push_back(vector<int>({left, right}));

            while (l + 1 < r && nums[l] == left) ++l;
            while (r - 1 > l && nums[r] == right) --r;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 2, 2};

    vector<vector<int>> result = twoSum(nums, 3);

    cout << result.size() << endl;
    assert(result.size() == 1);
    return 0;
}