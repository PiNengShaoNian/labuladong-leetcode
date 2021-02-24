#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int prev = nums[0];
    int index = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != prev) {
            prev = nums[i];
            nums[++index] = nums[i];
        }
    }

    return index + 1;
}

void isSorted(vector<int>& nums, int n) {
    for (int i = 0; i < n - 1; ++i) {
        assert(nums[i] <= nums[i + 1]);
    }
}

int main() {
    vector<int> nums1 = {1, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6};
    vector<int> nums2 = {1};
    vector<int> nums3 = {1, 2, 3};
    vector<int> nums4 = {3, 3, 3};

    assert(removeDuplicates(nums1) == 6);
    isSorted(nums1, 6);
    assert(removeDuplicates(nums2) == 1);
    isSorted(nums2, 1);
    assert(removeDuplicates(nums3) == 3);
    isSorted(nums3, 3);
    assert(removeDuplicates(nums4) == 1);
    isSorted(nums4, 1);

    return 0;
}