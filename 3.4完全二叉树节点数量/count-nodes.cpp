#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

int countNodes(TreeNode *root) {
    if (!root) return 0;
    int hl = 0;
    int hr = 0;

    TreeNode *cur = root;
    while (cur) {
        ++hl;
        cur = cur->left;
    }

    cur = root;

    while (cur) {
        ++hr;
        cur = cur->right;
    }

    if (hl == hr) return (int)pow(2, hl) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode root1(1, new TreeNode(2), new TreeNode(3));
    TreeNode root2(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                   new TreeNode(3, new TreeNode(6), nullptr));

    TreeNode root3(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                   new TreeNode(3));

    assert(countNodes(&root1) == 3);
    assert(countNodes(&root2) == 6);
    assert(countNodes(&root3) == 5);
    return 0;
}