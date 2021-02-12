#include <cassert>
#include <iostream>
#include <string>

#include "LRU.h"

using namespace std;

int main() {
    Cache<int, int> cache(3);
    cache.set(1, 1);
    cache.set(2, 2);
    cache.set(3, 3);
    cache.set(4, 4);

    assert(cache.size() == 3);
    assert(cache.get(1) == nullptr);
    assert(*cache.get(2) == 2);
    cache.set(5, 5);
    assert(cache.get(3) == nullptr);
    assert(*cache.get(5) == 5);
    return 0;
}