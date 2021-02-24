#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int eatingHours(vector<int>& piles, int speed) {
    int ans = 0;

    for (int pile : piles) {
        if (pile % speed == 0)
            ans += pile / speed;
        else
            ans += pile / speed + 1;
    }

    return ans;
}

int minEatingSpeed(vector<int>& piles, int H) {
    if (H < piles.size()) return -1;
    int hi = INT32_MAX;
    int lo = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int hours = eatingHours(piles, mid);

        if (hours <= H) {
            hi = mid - 1;
        } else if (hours > H) {
            lo = mid + 1;
        }
    }

    return lo;
}

int main() {
    vector<int> piles = {1, 2, 3, 20, 10, 6};

    cout << minEatingSpeed(piles, 5) << endl;
    assert(minEatingSpeed(piles, 7) == 10);
    assert(minEatingSpeed(piles, 6) == 20);
    return 0;
}