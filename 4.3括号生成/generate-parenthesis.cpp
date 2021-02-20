#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int getRightParenIndex(int l, const string& s) {
    vector<char> stack;
    int result = -1;
    for (int i = l; i < s.length(); ++i) {
        if (s[i] == '(') {
            stack.push_back(s[i]);
        } else {
            stack.pop_back();

            if (!stack.size()) {
                result = i;
                break;
            }
        }
    }

    return result;
}

unordered_set<string> generateParenthesis(int n) {
    if (n == 1) return unordered_set<string>({"()"});

    unordered_set<string> strs = generateParenthesis(n - 1);
    unordered_set<string> result;

    for (const string& str : strs) {
        int start = 0;
        result.insert("()" + str);
        result.insert("(" + str + ")");
        while (start < str.length() - 1) {
            int end = getRightParenIndex(start, str);

            if (end == -1) break;
            string before(str.begin(), str.begin() + start);
            string middle(str.begin() + start, str.begin() + end + 1);
            string after(str.begin() + end + 1, str.end());

            result.insert(before + "(" + middle + ")" + after);
            start = end + 1;
        }
    }

    return result;
}

int main() {
    unordered_set<string> result = generateParenthesis(6);

    cout << result.size() << endl;
    for (const string& str : result) {
        cout << str << endl;
    }
}