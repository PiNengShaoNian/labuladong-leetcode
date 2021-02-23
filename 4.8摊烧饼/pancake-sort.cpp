#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void __pancakeSort(vector<int> &nums, int n, vector<int> &result) {
    if (n < 0) return;

    int maxIndex = n;

    for (int i = 0; i < n; ++i) {
        if (nums[i] > nums[maxIndex]) maxIndex = i;
    }

    result.push_back(maxIndex + 1);
    result.push_back(n + 1);

    int l = 0;
    int r = maxIndex;

    while (l < r) {
        swap(nums[l], nums[r]);

        ++l;
        --r;
    }

    l = 0;
    r = n;

    while (l < r) {
        swap(nums[l], nums[r]);
        ++l;
        --r;
    }

    __pancakeSort(nums, n - 1, result);
}

vector<int> pancakeSort(vector<int> &nums) {
    vector<int> result;

    __pancakeSort(nums, nums.size() - 1, result);

    return result;
}

int main() {
    vector<int> nums = {3, 5, 4, 1, 2};
    vector<int> result = pancakeSort(nums);

    for (int i : result) {
        cout << i << endl;
    }
}