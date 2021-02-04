#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int* findAnagrams(const string& longStr, const string& shortStr) {
    unordered_map<char, int> need;
    unordered_map<char, int> window;
    vector<int> result;

    for (int i = 0; i < shortStr.length(); ++i) {
        ++need[shortStr[i]];
    }

    int l = 0;
    int r = -1;
    int valid = 0;
    while (l < longStr.length()) {
        if (r + 1 < longStr.length() && r - l + 1 < shortStr.length()) {
            char c = longStr[++r];

            if (need.find(c) != need.cend()) {
                ++window[c];

                if (window[c] == need[c]) ++valid;
            }
        } else {
            char c = longStr[l];

            if (need.find(c) != need.cend()) {
                --window[c];

                if (window[c] < need[c]) {
                    --valid;
                }
            }

            ++l;
        }

        if (valid == need.size()) {
            result.push_back(l);
        }
    }

    int* head = new int[result.size()];
    copy(result.cbegin(), result.cend(), head);

    return head;
}

int main() {
    int* result = findAnagrams("cbaebabacd", "abc");

    assert(result[0] == 0);
    assert(result[1] == 6);
}