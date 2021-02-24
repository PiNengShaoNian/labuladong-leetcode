#include <cassert>
#include <iostream>
#include <string>

using namespace std;

string findPalindrome(const string& str, int l, int r) {
    if (r >= str.length() || str[l] != str[r]) return string();

    while (l - 1 >= 0 && r + 1 < str.length()) {
        if (str[l - 1] == str[r + 1]) {
            --l;
            ++r;
        } else
            break;
    }

    return string(str.begin() + l, str.begin() + r + 1);
}

string longestPalindrome(const string& str) {
    string ans;
    for (int i = 0; i < str.length(); ++i) {
        string cur = findPalindrome(str, i, i);
        if (cur.length() > ans.length()) {
            ans = cur;
        }
        cur = findPalindrome(str, i, i + 1);
        if (cur.length() > ans.length()) {
            ans = cur;
        }
    }

    return ans;
}

int main() {
    string ans1 = longestPalindrome("aba");
    string ans2 = longestPalindrome("aacxycaa");
    string ans3 = longestPalindrome("abcdeeeffeefhjkg");
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
}