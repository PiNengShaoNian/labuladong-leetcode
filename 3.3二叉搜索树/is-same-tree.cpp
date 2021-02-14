#include <cassert>
#include <iostream>

#include "TreeNode.h"

using namespace std;

bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;

    if (!root1 || !root2) return false;

    if (root1->val != root2->val) return false;

    return isSameTree(root1->left, root2->left) &&
           isSameTree(root1->right, root2->right);
}

int main() {
    TreeNode root1(1, new TreeNode(2), new TreeNode(3));
    TreeNode root2(1, new TreeNode(2), new TreeNode(3));
    TreeNode root3(1, new TreeNode(2), new TreeNode(4));
    TreeNode root4(1, new TreeNode(2), nullptr);
    assert(isSameTree(&root1, &root2) == true);
    assert(isSameTree(&root1, &root3) == false);
    assert(isSameTree(&root1, &root4) == false);
    return 0;
}