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
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        // Brute‑force: copy sub‑vectors at each recursion and linearly search for root.
        if (preorder.empty() || inorder.empty()) return nullptr;
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        // Find root index in inorder (linear scan)
        int idx = 0;
        while (idx < inorder.size() && inorder[idx] != rootVal) ++idx;
        // Build left and right sub‑vectors
        vector<int> leftPre(preorder.begin()+1, preorder.begin()+1+idx);
        vector<int> leftIn(inorder.begin(), inorder.begin()+idx);
        vector<int> rightPre(preorder.begin()+1+idx, preorder.end());
        vector<int> rightIn(inorder.begin()+idx+1, inorder.end());
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
