#include <cassert>
#include <vector>

using namespace std;

//存在大量重复子问题
int fib(int N) {
    if (N == 0) return 0;

    if (N == 0 || N == 1) return 1;

    return fib(N - 1) + fib(N - 2);
}

int fib1(int N, vector<int> &memo) {
    if (memo[N] != 0) return memo[N];

    return memo[N] = fib1(N - 1, memo) + fib1(N - 2, memo);
}

//记忆化搜索
int fib1(int N) {
    if (N == 0) return 0;
    vector<int> memo(N + 1, 0);
    memo[1] = memo[2] = 1;
    return fib1(N, memo);
}

//自底向上
int fib2(int N) {
    if (N == 0) return 0;

    vector<int> memo(N + 1, 0);
    memo[1] = memo[2] = 1;

    for (int i = 3; i <= N; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[N];
}

//优化空间复杂度
int fib3(int N) {
    if (N == 0) return 0;

    int prev = 1;
    int cur = 1;
    int sum = 0;

    for (int i = 3; i <= N; ++i) {
        sum = prev + cur;
        prev = cur;
        cur = sum;
    }

    return sum;
}

int main() {
    int a1 = fib(8);
    int a2 = fib1(8);
    int a3 = fib2(8);
    int a4 = fib3(8);

    assert(a1 == a2);
    assert(a2 == a3);
    assert(a3 == a4);
}