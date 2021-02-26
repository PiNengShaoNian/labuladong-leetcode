#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "../5.11并查集/union-find.h"

using namespace std;

bool equationsPossible(vector<string>& equations) {
    UnionFind uf(26);

    for (string& equation : equations) {
        if (equation[1] == '=') {
            uf.unionElements(equation[0] - '0', equation[3] - '0');
        }
    }

    for (string& equation : equations) {
        if (equation[1] == '!') {
            if (uf.connected(equation[0] - '0', equation[3] - '0'))
                return false;
        }
    }

    return true;
}

int main() { return 0; }