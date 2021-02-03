#include <cassert>
#include <string>
#include <unordered_map>

using namespace std;

bool checkInclusion(const string& longStr, const string& shortStr) {
    int windowSize = shortStr.length();
    unordered_map<char, int> need;
    unordered_map<char, int> window;

    for (char c : shortStr) {
        ++need[c];
    }

    int l = 0;
    int r = -1;
    int valid = 0;
    while (l < longStr.length()) {
        if (r + 1 < longStr.length() && r - l + 1 < windowSize) {
            char c = longStr[++r];

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

        if (valid == need.size()) return true;
    }

    return false;
}

int main() { 
    assert(checkInclusion("helloworld", "oow") == true);
    assert(checkInclusion("helloworld", "olleh") == true);
    assert(checkInclusion("helloworld", "hw") == false);
    assert(checkInclusion("helloworld", "rld") == true);
 }