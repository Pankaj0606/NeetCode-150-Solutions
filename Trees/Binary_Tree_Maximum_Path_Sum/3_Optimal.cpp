#include <bits/stdc++.h>
using namespace std;
/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MIN;
        unordered_map<TreeNode*, int> gain; // stores max gain for processed nodes
        vector<TreeNode*> st;
        st.push_back(root);
        while (!st.empty()) {
            TreeNode* node = st.back();
            // push children first if they haven't been processed yet
            if (node->left && gain.find(node->left) == gain.end()) { st.push_back(node->left); continue; }
            if (node->right && gain.find(node->right) == gain.end()) { st.push_back(node->right); continue; }
            st.pop_back();
            int left = node->left ? max(0, gain[node->left]) : 0;
            int right = node->right ? max(0, gain[node->right]) : 0;
            ans = max(ans, node->val + left + right);
            gain[node] = node->val + max(left, right);
        }
        return ans;
    }
};
