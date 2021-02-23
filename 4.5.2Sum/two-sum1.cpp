#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

pair<int, int> towSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        auto it = map.find(target - nums[i]);
        if (it != map.cend() && it->second != i)
            return make_pair(i, map[target - nums[i]]);
    }

    return make_pair(-1, -1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    pair<int, int> result = towSum(nums, 5);
    pair<int, int> result1 = towSum(nums, 8);
    pair<int, int> result2 = towSum(nums, 10);

    cout << result.first << " " << result.second << endl;
    cout << result1.first << " " << result1.second << endl;
    cout << result2.first << " " << result2.second << endl;
    return 0;
}