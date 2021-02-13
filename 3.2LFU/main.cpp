#include <cassert>

#include "LFU.h"

using namespace std;

int main() {
    LFU<int, int> cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    assert(cache.size() == 2);

    cache.put(3, 3);

    assert(cache.get(1) == nullptr);
    assert(*cache.get(2) == 2);

    cache.put(4, 4);
    assert(cache.get(3) == nullptr);
    assert(*cache.get(4) == 4);

    return 0;
}