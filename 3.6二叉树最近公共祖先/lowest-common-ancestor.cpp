#include <cassert>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

TreeNode* lowesetCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (root == p || root == q) return root;
    TreeNode* left = lowesetCommonAncestor(root->left, p, q);
    TreeNode* right = lowesetCommonAncestor(root->right, p, q);

    if (left && right) return root;

    if (!left && !right) return nullptr;

    return left ? left : right;
}

int main() {
    TreeNode root(3, new TreeNode(5), new TreeNode(1));
    TreeNode *p4, *p0, *p6;
    root.left->left = p6 = new TreeNode(6);
    root.left->right = new TreeNode(2);
    root.left->right->left = new TreeNode(7);
    root.left->right->right = p4 = new TreeNode(4);
    root.right->left = p0 = new TreeNode(0);
    root.right->right = new TreeNode(8);

    assert(p6->val == 6);
    assert(p0->val == 0);
    assert(p4->val == 4);

    assert(lowesetCommonAncestor(&root, p0, p4)->val == 3);
    assert(lowesetCommonAncestor(&root, p6, p4)->val == 5);
    return 0;
}