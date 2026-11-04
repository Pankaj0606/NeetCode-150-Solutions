#include <vector>
#include <algorithm>
using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper to find path from root to target node.
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;
        if (getPath(root->left, target, path) || getPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        getPath(root, p, pathP);
        getPath(root, q, pathQ);
        TreeNode* lca = nullptr;
        size_t i = 0, n = min(pathP.size(), pathQ.size());
        while (i < n && pathP[i] == pathQ[i]) {
            lca = pathP[i];
            ++i;
        }
        return lca;
    }
};
