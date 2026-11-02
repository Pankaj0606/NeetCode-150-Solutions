#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string s1 = serialize(p);
        string s2 = serialize(q);
        return s1 == s2;
    }
private:
    string serialize(TreeNode* node) {
        if (!node) return "#,"; // sentinel for null
        return to_string(node->val) + "," + serialize(node->left) + serialize(node->right);
    }
};
