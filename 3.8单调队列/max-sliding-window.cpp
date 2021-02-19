#include <cassert>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class MonotonicQueue {
   private:
    list<int> queue;

   public:
    int max() { return queue.front(); }

    void pop(int n) {
        if (n == queue.front()) {
            queue.pop_front();
        }
    }

    void push(int n) {
        while (!queue.empty() && queue.back() < n) {
            queue.pop_back();
        }

        queue.push_back(n);
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue mq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        if (i < k - 1) {
            mq.push(nums[i]);
        } else {
            mq.push(nums[i]);
            ans.push_back(mq.max());
            mq.pop(nums[i - k + 1]);
        }
    }

    return ans;
}

int main() {
    vector<int> expected = {3, 3, 5, 5, 6, 7};
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> result = maxSlidingWindow(nums, 3);

    assert(result == expected);

    return 0;
}