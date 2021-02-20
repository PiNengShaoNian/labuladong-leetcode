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

void subsets(vector<int> &nums, int index, vector<vector<int>> &allSets) {
    if (index == nums.size())
        allSets.push_back(vector<int>());
    else {
        subsets(nums, index + 1, allSets);
        int item = nums[index];
        vector<vector<int>> moreSets;

        for (vector<int> &set : allSets) {
            vector<int> newSet(set);
            newSet.push_back(item);
            moreSets.push_back(newSet);
        }

        allSets.insert(allSets.end(), moreSets.begin(), moreSets.end());
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    vector<vector<int>> result1;

    subsets(nums, 0, result1);

    cout << result1.size() << endl;

    cout << result.size() << endl;
}