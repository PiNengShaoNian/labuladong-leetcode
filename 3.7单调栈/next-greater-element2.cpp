#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = n * 2 - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= nums[i % n]) {
            s.pop();
        }

        ans[i % n] = s.empty() ? -1 : s.top();

        s.push(nums[i % n]);
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> expected = {4, 2, 4, -1, 4};
    vector<int> result = nextGreaterElement(nums);
    assert(result == expected);
    return 0;
}