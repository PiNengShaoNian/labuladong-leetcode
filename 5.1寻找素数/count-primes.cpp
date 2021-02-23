#include <cassert>
#include <iostream>

using namespace std;

int countPrimes(int n) {
    int ans = 0;
    bool* isPrime = new bool[n];

    for (int i = 0; i < n; ++i) isPrime[i] = true;

    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < n; ++i)
        if (isPrime[i]) ++ans;

    delete[] isPrime;
    return ans;
}

int main() {
    cout << countPrimes(10) << endl;
    assert(countPrimes(10) == 4);
    return 0;
}