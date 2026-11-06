#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val; TreeNode *left; TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
private:
    void dfs(TreeNode* node, int depth, vector<int>& ans) {
        if (!node) return;
        if (depth == (int)ans.size()) ans.push_back(node->val); // first node at this depth
        dfs(node->right, depth + 1, ans); // right first
        dfs(node->left, depth + 1, ans);
    }
};
