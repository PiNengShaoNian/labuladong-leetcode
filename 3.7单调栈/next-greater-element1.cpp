#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums) {
    vector<int> ans(nums.size());
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums[i] >= s.top()) {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> expected = {4, 2, 4, -1, -1};
    vector<int> result = nextGreaterElement(nums);
    assert(result == expected);
    return 0;
}