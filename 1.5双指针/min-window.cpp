#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

tuple<int, int> minWindow(const string& longStr, const string& shortStr) {
    unordered_map<char, int> need;
    unordered_map<char, int> window;

    tuple<int, int> result = make_tuple(0, longStr.length() + 1);

    for (char c : shortStr) {
        ++need[c];
    }

    int l = 0;
    int r = -1;
    int valid = 0;

    while (l < longStr.length()) {
        if (r + 1 < longStr.length() && valid < need.size()) {
            ++r;
            char c = longStr[r];
            if (need.find(c) != need.cend()) {
                ++window[c];
                if (window[c] == need[c]) ++valid;
            }
        } else {
            char c = longStr[l];

            if (need.find(c) != need.cend()) {
                --window[c];

                if (window[c] < need[c]) --valid;
            }
            ++l;
        }

        if (valid == need.size() && r - l < get<1>(result) - get<0>(result)) {
            result = make_tuple(l, r);
        }
    }

    return result;
}

int main() {
    auto t1 = minWindow("ADBECFEBANC", "ABC");
    auto t2 = minWindow("ABAAACAAA", "AC");
    auto t3 = minWindow("ABAAACAAA", "D");

    assert(get<0>(t1) == 7);
    assert(get<1>(t1) == 10);

    assert(get<0>(t2) == 4);
    assert(get<1>(t2) == 5);

    assert(get<0>(t3) == 0);
    return 0;
}
