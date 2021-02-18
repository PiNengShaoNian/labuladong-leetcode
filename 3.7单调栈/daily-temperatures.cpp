#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int> nums) {
    vector<int> ans(nums.size());
    stack<int> s;

    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums[s.top()] <= nums[i]) {
            s.pop();
        }

        ans[i] = s.empty() ? 0 : s.top() - i;

        s.push(i);
    }

    return ans;
}

int main() {
    vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    vector<int> result = dailyTemperatures(nums);
    assert(result == expected);
    return 0;
}