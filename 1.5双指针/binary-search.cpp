#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template <class ForwardIt, class T>
ForwardIt left_bound(ForwardIt first, ForwardIt last, const T& value) {
    ForwardIt l = first;
    ForwardIt r = last - 1;

    while (l <= r) {
        ForwardIt mid = l + (r - l) / 2;

        if (*mid == value) {
            r = mid - 1;
        } else if (*mid > value) {
            r = mid - 1;
        } else if (*mid < value) {
            l = mid + 1;
        }
    }

    if (l >= last || *l != value) return last;

    return l;
}

template <class ForwardIt, class T>
ForwardIt right_bound(ForwardIt first, ForwardIt last, const T& value) {
    ForwardIt l = first;
    ForwardIt r = last - 1;

    while (l <= r) {
        ForwardIt mid = l + (r - l) / 2;

        if (*mid == value) {
            l = mid + 1;
        } else if (*mid > value) {
            r = mid - 1;
        } else if (*mid < value) {
            l = mid + 1;
        }
    }

    if (r < first || *r != value) return last;

    return r + 1;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 3, 3, 4, 5};
    assert(left_bound(nums1.cbegin(), nums1.cend(), 3) == nums1.cbegin() + 2);
    assert(right_bound(nums1.cbegin(), nums1.cend(), 3) == nums1.cbegin() + 5);

    assert(left_bound(nums1.cbegin(), nums1.cend(), 2) == nums1.cbegin() + 1);
    assert(right_bound(nums1.cbegin(), nums1.cend(), 2) == nums1.cbegin() + 2);
}