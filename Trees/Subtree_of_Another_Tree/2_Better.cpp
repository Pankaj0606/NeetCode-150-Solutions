#include <bits/stdc++.h>
using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    string serialize(TreeNode* node) {
        if (!node) return "#,"; // sentinel for null
        return to_string(node->val) + "," + serialize(node->left) + serialize(node->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string sRoot = serialize(root);
        string sSub = serialize(subRoot);
        return sRoot.find(sSub) != string::npos;
    }
};
