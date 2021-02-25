#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int intervalSchedule(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    int count = 1;

    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) -> bool { return a[1] < b[1]; });

    int end = intervals[0][1];
    for (vector<int>& interval : intervals) {
        if (interval[0] >= end) {
            ++count;
            end = interval[1];
        }
    }

    return count;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();

    return n - intervalSchedule(intervals);
}

int main() {
    vector<vector<int>> intervals1 = {{1, 3}, {2, 4}, {3, 6}};
    vector<vector<int>> intervals2 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    cout << intervalSchedule(intervals1) << endl;
    assert(intervalSchedule(intervals1) == 2);
    assert(intervalSchedule(intervals2) == 3);
    assert(eraseOverlapIntervals(intervals2) == 1);
    return 0;
}