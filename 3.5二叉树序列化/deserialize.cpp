#include <cassert>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "TreeNode.h"

using namespace std;

vector<string> split(const string& str, const string& delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

TreeNode* __deserialize(list<string>& nodes, const string& sp,
                        const char& empty) {
    if (nodes.size() == 0) return nullptr;

    string& token = nodes.front();
    nodes.pop_front();

    if (token == "#") return nullptr;

    TreeNode* node = new TreeNode(stoi(token));

    node->left = __deserialize(nodes, sp, empty);
    node->right = __deserialize(nodes, sp, empty);

    return node;
}

TreeNode* deserialize(const string& str, const string& sp = ",",
                      const char& empty = '#') {
    list<string> nodes;

    vector<string> tokens = split(str, sp);

    for (const string& token : tokens) {
        nodes.push_back(token);
    }

    return __deserialize(nodes, sp, empty);
}

TreeNode* deserialize1(const string& str, const string& sp = ",",
                       const string& empty = "#") {
    vector<string> tokens = split(str, sp);
    if (tokens.empty() || tokens[0] == "#") return nullptr;

    deque<TreeNode*> parents;

    TreeNode* root = new TreeNode(stoi(tokens[0]));
    parents.push_back(root);

    for (int i = 1; i < tokens.size();) {
        string token = tokens[i++];
        TreeNode* parent = parents.front();
        parents.pop_front();
        if (token == "#") {
            parent->left = nullptr;
        } else {
            parent->left = new TreeNode(stoi(token));
            parents.push_back(parent->left);
        }

        token = tokens[i++];
        if (token == "#") {
            parent->right = nullptr;
        } else {
            parent->right = new TreeNode(stoi(token));
            parents.push_back(parent->right);
        }
    }

    return root;
}

int main() {
    string str = "1,2,#,#,3,#,#";
    string str1 = "1,#,2,#,3,4,#,#,5,#,#";

    TreeNode* root1 = deserialize(str);
    TreeNode* root2 = deserialize(str1);

    assert(root1->val == 1);
    assert(root1->left->val == 2);
    assert(root1->right->val == 3);

    assert(root2->val == 1);
    assert(root2->right->val == 2);
    assert(root2->right->right->val == 3);
    assert(root2->right->right->left->val == 4);
    assert(root2->right->right->right->val == 5);

    string str2 = "1,2,3,#,#,#,#";
    string str3 = "1,#,2,#,3,4,5";
    TreeNode* root3 = deserialize1(str2);
    TreeNode* root4 = deserialize1(str3);
    assert(root3->val == 1);
    assert(root3->left->val == 2);
    assert(root3->right->val == 3);

    assert(root4->val == 1);
    assert(root4->right->val == 2);
    assert(root4->right->right->val == 3);
    assert(root4->right->right->left->val == 4);
    assert(root4->right->right->right->val == 5);

    return 0;
}