#include <cassert>
#include <iostream>
#include <queue>
#include <string>

#include "TreeNode.h"

using namespace std;

void __serialize(TreeNode *root, string &res, const string &sp,
                 const string &empty) {
    if (!root) {
        res += empty + sp;
        return;
    };

    res += to_string(root->val) + sp;

    __serialize(root->left, res, sp, empty);
    __serialize(root->right, res, sp, empty);
}

string serialize(TreeNode *root, const string &sp = ",",
                 const string &empty = "#") {
    string res;
    __serialize(root, res, sp, empty);
    return res;
}

string serialize1(TreeNode *root, const string &sp = ",",
                  const string &empty = "#") {
    queue<TreeNode *> nodes;

    nodes.push(root);
    string res;

    while (!nodes.empty()) {
        TreeNode *cur = nodes.front();
        nodes.pop();

        if (!cur) {
            res += empty + sp;
            continue;
        }

        res += to_string(cur->val) + sp;

        nodes.push(cur->left);
        nodes.push(cur->right);
    }

    return res;
}

int main() {
    TreeNode root1(1, new TreeNode(2), new TreeNode(3));
    TreeNode root2(1, new TreeNode(2, new TreeNode(4), nullptr),
                   new TreeNode(3));

    cout << serialize(&root1) << endl;
    cout << serialize(&root2) << endl;

    cout << serialize1(&root1) << endl;
    cout << serialize1(&root2) << endl;

    return 0;
}