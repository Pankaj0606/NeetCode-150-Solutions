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
    // Helper to find max on path from root to target node (identified by pointer)
    int maxOnPath(TreeNode* root, TreeNode* target, int curMax) {
        if (!root) return INT_MIN; // not found in this subtree
        curMax = max(curMax, root->val);
        if (root == target) return curMax;
        int left = maxOnPath(root->left, target, curMax);
        if (left != INT_MIN) return left;
        return maxOnPath(root->right, target, curMax);
    }

    // Brute‑force: for each node, recompute max on its root‑to‑node path
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        vector<TreeNode*> nodes;
        // collect all nodes via simple DFS
        function<void(TreeNode*)> collect = [&](TreeNode* node) {
            if (!node) return;
            nodes.push_back(node);
            collect(node->left);
            collect(node->right);
        };
        collect(root);
        int good = 0;
        for (TreeNode* n : nodes) {
            int pathMax = maxOnPath(root, n, INT_MIN);
            if (n->val >= pathMax) ++good; // pathMax includes n.val, so condition holds
        }
        return good;
    }
};
