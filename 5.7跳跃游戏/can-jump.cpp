#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < nums.size(); ++i) {
        farthest = max(farthest, i + nums[i]);

        if (farthest <= i) return false;
    }

    return farthest >= nums.size() - 1;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    assert(canJump(nums1) == true);
    assert(canJump(nums2) == false);

    return 0;
}