#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int base = 1337;

int mypow(int a, int k) {
    if (k == 0) return 1;
    a %= base;

    if (k % 2 == 0) {
        int sub = mypow(a, k / 2) % base;
        return (sub * sub) % base;
    } else {
        return (a * mypow(a, k - 1)) % base;
    }
}

int superPow(int a, vector<int> &b) {
    if (b.empty()) return 1;

    int last = b.back();
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    return part1 * part2;
}

int main() {
    vector<int> exponent1 = {1};
    vector<int> exponent2 = {13};
    assert(superPow(3, exponent1) == 3);
    assert(superPow(2, exponent2) == ((int)pow(2, 13) % base));
}