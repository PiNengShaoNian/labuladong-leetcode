#include <cassert>
#include <tuple>
#include <vector>

using namespace std;

tuple<int, int> towSum(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
        int cand = nums[l] + nums[r];

        if (cand == target)
            return make_tuple(l, r);
        else if (cand < target)
            ++l;
        else
            --r;
    }

    return make_tuple(-1, -1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    auto t1 = towSum(nums, 7);
    auto t2 = towSum(nums, 11);
    auto t3 = towSum(nums, 9);

    assert(get<0>(t1) == 0);
    assert(get<1>(t1) == 5);

    assert(get<0>(t2) == 4);
    assert(get<1>(t2) == 5);

    assert(get<0>(t3) == 2);
    assert(get<1>(t3) == 5);
}