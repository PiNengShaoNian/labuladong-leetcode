#include <cassert>
#include <iostream>
#include <queue>

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

int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;

    int depth = 1;

    queue<TreeNode *> nodes_queue;
    nodes_queue.push(root);
    while (nodes_queue.size()) {
        TreeNode *cur = nodes_queue.front();
        nodes_queue.pop();

        if (cur->left == nullptr && cur->right == nullptr) return depth;

        ++depth;

        if (cur->left) nodes_queue.push(cur->left);

        if (cur->right) nodes_queue.push(cur->right);
    }

    return depth;
}

int main() {
    TreeNode root(1, new TreeNode(2), new TreeNode(3));

    cout << minDepth(&root) << endl;
    assert(minDepth(&root) == 2);

    root.left->left = new TreeNode(4);
    root.left->right = new TreeNode(5);

    root.right->left = new TreeNode(6);
    assert(minDepth(&root) == 3);

    return 0;
}