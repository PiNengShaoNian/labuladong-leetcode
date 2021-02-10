#include <cassert>
#include <iostream>
#include <unordered_map>

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

int __rob(TreeNode *root, unordered_map<TreeNode *, int> &memo) {
    if (!root) return 0;

    if (memo.find(root) != memo.cend()) return memo[root];

    int choose =
        root->val +
        (root->left
             ? __rob(root->left->left, memo) + __rob(root->left->right, memo)
             : 0) +
        (root->right
             ? __rob(root->right->left, memo) + __rob(root->right->right, memo)
             : 0);

    int notChoose = __rob(root->left, memo) + __rob(root->right, memo);

    return memo[root] = max(choose, notChoose);
}

int rob(TreeNode *root) {
    unordered_map<TreeNode *, int> memo;
    return __rob(root, memo);
}

int main() {
    TreeNode tree1(3, new TreeNode(2, nullptr, new TreeNode(3)),
                   new TreeNode(3, nullptr, new TreeNode(1)));

    cout << rob(&tree1) << endl;
    assert(rob(&tree1) == 7);
    return 0;
}