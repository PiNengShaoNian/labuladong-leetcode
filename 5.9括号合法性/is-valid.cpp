#include <cassert>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(const string& str) {
    stack<char> parens;

    for (int i = 0; i < str.length(); ++i) {
        char c = str[i];

        if (c == '(' || c == '[' || c == '{') {
            parens.push(c);
            continue;
        }

        if (c == ')' || c == ']' || c == '}') {
            if (parens.empty()) return false;
            char top = parens.top();
            parens.pop();

            char expteced = c == ')' ? '(' : c == ']' ? '[' : '{';
            if (top != expteced) return false;
        }
    }

    return parens.empty();
}

int main() {
    assert(isValid("(){}[]") == true);
    assert(isValid("({[]}){}[]") == true);
    assert(isValid("(){[]}[]") == true);
    assert(isValid("({})") == true);
    assert(isValid("()") == true);
}