#include <iostream>

#include "union-find.h"

using namespace std;

int main() {
    UnionFind uf(5);

    cout << uf.count() << endl;

    uf.unionElements(0, 1);
    cout << uf.count() << endl;
    uf.unionElements(2, 3);
    uf.unionElements(3, 4);

    cout << uf.count() << endl;

    uf.unionElements(0, 2);
    cout << uf.count() << endl;

    cout << uf.connected(0, 4) << endl;

    return 0;
}