#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;

    for (int mask = 0; mask < (1 << nums.size()); ++mask) {
        vector<int> set;
        for (int j = 0; j < nums.size(); ++j) {
            if (mask & (1 << j)) {
                set.push_back(nums[j]);
            }
        }

        ans.push_back(set);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    cout << result.size() << endl;
}