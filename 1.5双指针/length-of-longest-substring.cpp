#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(const string& str) {
    int result = 0;
    unordered_map<char, int> window;

    int l = 0;
    int r = -1;

    while (l < str.length() && r + 1 < str.length()) {
        char c = str[++r];

        if (window.find(c) != window.cend()) {
            --window[str[l]];
            ++l;
            ++window[c];
        } else {
            ++window[c];
        }

        if (r - l + 1 > result) result = r - l + 1;
    }

    return result;
}

int main() {
    assert(lengthOfLongestSubstring("aabab") == 2);
    assert(lengthOfLongestSubstring("abcdeff") == 6);
    assert(lengthOfLongestSubstring("aabcdef") == 6);
    assert(lengthOfLongestSubstring("aaabbb") == 2);
}