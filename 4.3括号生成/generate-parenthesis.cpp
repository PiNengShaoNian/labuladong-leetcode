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
            if (str[start] == '(') {
                string before(str.begin(), str.begin() + start + 1);
                string after(str.begin() + start + 1, str.end());

                result.insert(before + "(" + ")" + after);
            }
            ++start;
        }
    }

    return result;
}

int main() {
    unordered_set<string> result = generateParenthesis(3);

    cout << result.size() << endl;
    for (const string& str : result) {
        cout << str << endl;
    }
}