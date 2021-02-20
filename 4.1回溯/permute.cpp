#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute1(vector<int>& nums) {
    if (!nums.size()) return vector<vector<int>>(1, vector<int>());

    vector<int> remainder(nums.begin() + 1, nums.end());

    vector<vector<int>> result;
    vector<vector<int>> permutations = permute1(remainder);

    for (vector<int>& permutation : permutations) {
        for (int i = 0; i <= permutation.size(); ++i) {
            vector<int> temp(permutation.begin(), permutation.begin() + i);
            temp.push_back(nums[0]);
            temp.insert(temp.end(), permutation.begin() + i, permutation.end());

            result.push_back(move(temp));
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute1(nums);

    cout << result.size() << endl;
    return 0;
}