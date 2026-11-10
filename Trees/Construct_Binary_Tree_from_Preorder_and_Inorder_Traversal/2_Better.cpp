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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode* helper(const vector<int>& pre, int preL, int preR,
                     const vector<int>& in, int inL, int inR) {
        // preL inclusive, preR exclusive
        if (preL >= preR || inL >= inR) return nullptr;
        int rootVal = pre[preL];
        TreeNode* root = new TreeNode(rootVal);
        // Linear search for root in inorder slice
        int idx = inL;
        while (idx < inR && in[idx] != rootVal) ++idx;
        int leftSize = idx - inL;
        root->left = helper(pre, preL+1, preL+1+leftSize, in, inL, idx);
        root->right = helper(pre, preL+1+leftSize, preR, in, idx+1, inR);
        return root;
    }
};
