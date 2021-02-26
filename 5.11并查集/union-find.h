#ifndef CHAPTER5_11_UNION_FIND_H
#define CHAPTER5_11_UNION_FIND_H

#include <cassert>
#include <vector>

class UnionFind {
   private:
    int N;
    std::vector<int> id;
    std::vector<int> size;

   public:
    UnionFind(int n) : N(n) {
        id = std::vector<int>(n);
        size = std::vector<int>(n);

        for (int i = 0; i < n; ++i) {
            id[i] = i;
            size[i] = 1;
        }
    }

    void unionElements(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) return;

        if (size[rootQ] > size[rootP]) {
            id[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            id[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }

        --N;
    }

    bool connected(int p, int q) { return find(p) == find(q); }

    int find(int x) {
        while (x != id[x]) {
            id[x] = id[id[x]];
            x = id[x];
        }

        return x;
    }

    int count() { return N; }
};

#endif
