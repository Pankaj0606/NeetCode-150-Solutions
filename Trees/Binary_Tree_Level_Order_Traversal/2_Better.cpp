class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> cur, nxt;
        cur.push(root);
        while (!cur.empty()) {
            vector<int> level;
            while (!cur.empty()) {
                TreeNode* node = cur.front(); cur.pop();
                level.push_back(node->val);
                if (node->left) nxt.push(node->left);
                if (node->right) nxt.push(node->right);
            }
            res.push_back(level);
            swap(cur, nxt);
        }
        return res;
    }
};
