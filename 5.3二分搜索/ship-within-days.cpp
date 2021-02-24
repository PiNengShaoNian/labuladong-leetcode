#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int timeForShiping(vector<int>& weights, int capacity) {
    int index = 0;
    int ans = 0;
    int cur = 0;
    while (index < weights.size()) {
        if (weights[index] > capacity) return -1;
        if (cur + weights[index] <= capacity) {
            cur += weights[index];
            ++index;
        } else {
            ++ans;
            cur = 0;
        }
    }

    return ans + 1;
}

int shipWithinDays(vector<int>& weights, int D) {
    int hi = INT32_MAX;
    int lo = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        int days = timeForShiping(weights, mid);

        if (days > D || days == -1)
            lo = mid + 1;
        else if (days <= D) {
            hi = mid - 1;
        }
    }

    return lo;
}

int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << shipWithinDays(weights, 5) << endl;
    assert(shipWithinDays(weights, 5) == 15);

    return 0;
}