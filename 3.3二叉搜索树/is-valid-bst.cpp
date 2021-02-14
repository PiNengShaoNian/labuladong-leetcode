#include <cassert>
#include <iostream>

#include "TreeNode.h"

bool __isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
    if (!root) return true;

    if (min && min->val >= root->val) return false;

    if (max && max->val <= root->val) return false;

    return __isValidBST(root->left, min, root) &&
           __isValidBST(root->right, root, max);
}

bool isValidBST(TreeNode* root) { return __isValidBST(root, nullptr, nullptr); }

int main() {
    TreeNode root1(2, new TreeNode(1), new TreeNode(3));

    TreeNode root2(2, new TreeNode(2), nullptr);

    TreeNode root3(1, new TreeNode(2), new TreeNode(3));

    assert(isValidBST(&root1) == true);
    assert(isValidBST(&root2) == false);
    assert(isValidBST(&root3) == false);
    return 0;
}