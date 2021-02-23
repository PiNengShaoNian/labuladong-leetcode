#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    int l = 0;
    int r = -1;
    int ans = 0;

    while (l < nums.size()) {
        if (sum < k) {
            sum += nums[++r];
        } else {
            sum -= nums[l];
            ++l;
        }

        if (sum == k) ++ans;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2};

    cout << subarraySum(nums, 2) << endl;
    return 0;
}