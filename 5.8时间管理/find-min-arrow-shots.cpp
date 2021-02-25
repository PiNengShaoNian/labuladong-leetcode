#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int findMinArrowShots(vector<vector<int>>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end(),
         [](vector<int>& a, vector<int>& b) -> bool { return a[1] < b[1]; });

    int count = 1;
    int end = nums[0][1];
    for (vector<int>& interval : nums) {
        if (interval[0] > end) {
            ++count;
            end = interval[1];
        }
    }

    return count;
}

int main() {
    vector<vector<int>> intervals1 = {{1, 3}, {2, 4}, {3, 6}};

    cout << findMinArrowShots(intervals1) << endl;
    assert(findMinArrowShots(intervals1) == 1);
}