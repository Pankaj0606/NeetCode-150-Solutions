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
    // Returns {isBalanced, height}
    pair<bool,int> check(TreeNode* node) {
        if (!node) return {true,0};
        auto left  = check(node->left);
        auto right = check(node->right);
        bool bal = left.first && right.first && abs(left.second - right.second) <= 1;
        int h = 1 + max(left.second, right.second);
        return {bal, h};
    }
    bool isBalanced(TreeNode* root) {
        return check(root).first;
    }
};
