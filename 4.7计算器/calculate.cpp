#include <cassert>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int __calculate(const string& str, int& index) {
    int num = 0;
    char sign = '+';
    stack<int> nums;

    while (index < str.length()) {
        char c = str[index];

        if (c == ' ') {
            ++index;
            continue;
        }

        if (isdigit(c)) {
            num = 10 * num + (c - '0');
        }

        if (c == '(') {
            ++index;
            num = __calculate(str, index);
        }

        if (!isdigit(c) || index == str.length() - 1) {
            int prev;
            switch (sign) {
                case '+':
                    nums.push(num);
                    break;
                case '-':
                    nums.push(-num);
                    break;
                case '*':
                    prev = nums.top();
                    nums.pop();
                    nums.push(prev * num);
                    break;
                case '/':
                    prev = nums.top();
                    nums.pop();
                    nums.push(prev / num);
                    break;
            }

            num = 0;
            sign = c;
        }

        if (c == ')') break;

        ++index;
    }

    int result = 0;

    while (!nums.empty()) {
        result += nums.top();
        nums.pop();
    }

    return result;
}

int calculate(const string& str) {
    int index = 0;
    return __calculate(str, index);
}

int main() {
    assert(calculate("1 + 2") == 1 + 2);
    assert(calculate("1 - 2") == 1 - 2);
    assert(calculate("1 * 2") == 1 * 2);
    assert(calculate("1 / 2") == 1 / 2);

    assert(calculate("3 * (4 + 3)") == 3 * (4 + 3));
    assert(calculate("3 * (4 + 3) / 2 + 1") == 3 * (4 + 3) / 2 + 1);
}