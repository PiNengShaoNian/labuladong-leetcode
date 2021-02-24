#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int> &heights, int l, int r) {
    int ans = l;
    for (int i = l + 1; i <= r; ++i) {
        if (heights[i] > heights[ans]) ans = i;
    }

    return ans;
}

int computeOnRange(vector<int> &heights, int l, int r) {
    int ans = 0;
    int minHeight = min(heights[l], heights[r]);
    for (int i = l + 1; i < r; ++i) {
        ans += minHeight - heights[i];
    }

    return ans;
}

int compute(vector<int> &heights, int mid, bool left) {
    if ((mid <= 0 && left) || (mid >= heights.size() - 1 && !left)) return 0;
    if (left) {
        int leftMax = getMax(heights, 0, mid - 1);

        int res = computeOnRange(heights, leftMax, mid);
        return res + compute(heights, leftMax, true);
    } else {
        int rightMax = getMax(heights, mid + 1, heights.size() - 1);

        int res = computeOnRange(heights, mid, rightMax);

        return res + compute(heights, rightMax, false);
    }
}

int trap(vector<int> &heigts) {
    int mid = getMax(heigts, 0, heigts.size() - 1);
    return compute(heigts, mid, true) + compute(heigts, mid, false);
}

int trap1(vector<int> &heights) {
    vector<int> leftMax(heights.size()), rightMax(heights.size());

    leftMax[0] = heights[0];

    for (int i = 1; i < heights.size(); ++i) {
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    }

    rightMax[heights.size() - 1] = heights[heights.size() - 1];

    for (int i = heights.size() - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], heights[i]);
    }

    int ans = 0;
    for (int i = 1; i < heights.size() - 1; ++i) {
        ans += min(leftMax[i], rightMax[i]) - heights[i];
    }

    return ans;
}

int trap2(vector<int> &heights) {
    int n = heights.size();
    int leftMax = heights[0];
    int rightMax = heights[n - 1];

    int left = 0;
    int right = n - 1;
    int ans = 0;
    while (left <= right) {
        leftMax = max(leftMax, heights[left]);
        rightMax = max(rightMax, heights[right]);

        if (leftMax < rightMax) {
            ans += leftMax - heights[left];
            ++left;
        } else {
            ans += rightMax - heights[right];
            --right;
        }
    }

    return ans;
}

int main() {
    vector<int> heights = {4, 1, 1, 5, 1, 1, 3};
    cout << trap(heights) << endl;
    cout << trap1(heights) << endl;
    cout << trap2(heights) << endl;

    assert(trap(heights) == 10);
    assert(trap1(heights) == 10);
    assert(trap2(heights) == 10);
}