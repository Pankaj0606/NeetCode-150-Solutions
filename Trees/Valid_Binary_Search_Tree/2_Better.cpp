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
    bool isValidBST(TreeNode* root) {
        vector<long long> inorder;
        inorderTraversal(root, inorder);
        for (size_t i = 1; i < inorder.size(); ++i) {
            if (inorder[i] <= inorder[i-1]) return false;
        }
        return true;
    }
private:
    void inorderTraversal(TreeNode* node, vector<long long>& vec) {
        if (!node) return;
        inorderTraversal(node->left, vec);
        vec.push_back(node->val);
        inorderTraversal(node->right, vec);
    }
};
