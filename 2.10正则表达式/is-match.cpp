#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool __isMatch(const string& str, const string& pattern, int indexStr,
               int indexPattern, unordered_map<string, bool>& memo) {
    if (indexStr == str.length()) {
        if (indexPattern >= pattern.length())
            return true;
        else
            return false;
    }

    if (indexPattern >= pattern.length()) return false;

    string key = to_string(indexStr) + "," + to_string(indexPattern);
    if (memo.find(key) != memo.cend()) return memo[key];

    bool result;
    char lookahead =
        indexPattern + 1 < pattern.length() ? pattern[indexPattern + 1] : '\0';
    if (lookahead != '*') {
        if (str[indexStr] == pattern[indexPattern] ||
            pattern[indexPattern] == '.')
            result =
                __isMatch(str, pattern, indexStr + 1, indexPattern + 1, memo);
        else
            result = false;
    } else {
        if (pattern[indexPattern] == str[indexStr] ||
            pattern[indexPattern] == '.') {
            result =
                __isMatch(str, pattern, indexStr + 1, indexPattern + 2, memo) ||
                __isMatch(str, pattern, indexStr + 1, indexPattern, memo) ||
                __isMatch(str, pattern, indexStr, indexPattern + 2, memo);
        } else {
            result = __isMatch(str, pattern, indexStr, indexPattern + 2, memo);
        }
    }

    return memo[key] = result;
}

bool isMatch(const string& str, const string& pattern) {
    unordered_map<string, bool> memo;
    return __isMatch(str, pattern, 0, 0, memo);
}

int main() {
    assert(isMatch("abc", ".bc") == true);
    assert(isMatch("abc", ".cc") == false);
    assert(isMatch("abc", ".bd") == false);
    assert(isMatch("abbbbbc", "a.*") == true);
    assert(isMatch("abbbbbc", "a.*bc") == true);
    assert(isMatch("abc", "a.*bcd") == false);
    assert(isMatch("abcf", "a.*bc.") == true);
}