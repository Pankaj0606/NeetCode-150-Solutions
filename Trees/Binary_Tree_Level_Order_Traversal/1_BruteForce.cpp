class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int h = height(root);
        for (int i = 1; i <= h; ++i) {
            vector<int> level;
            collectLevel(root, i, level);
            res.push_back(level);
        }
        return res;
    }
private:
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    void collectLevel(TreeNode* node, int level, vector<int>& out) {
        if (!node) return;
        if (level == 1) out.push_back(node->val);
        else {
            collectLevel(node->left, level - 1, out);
            collectLevel(node->right, level - 1, out);
        }
    }
};
