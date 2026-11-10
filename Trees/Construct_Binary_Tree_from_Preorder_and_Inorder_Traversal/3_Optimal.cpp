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
        unordered_map<int,int> idxMap;
        for (int i = 0; i < inorder.size(); ++i) idxMap[inorder[i]] = i;
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size(), idxMap);
    }
private:
    TreeNode* build(const vector<int>& pre, int preL, int preR,
                    const vector<int>& in, int inL, int inR,
                    const unordered_map<int,int>& idxMap) {
        if (preL >= preR || inL >= inR) return nullptr;
        int rootVal = pre[preL];
        TreeNode* root = new TreeNode(rootVal);
        int idx = idxMap.at(rootVal);
        int leftSize = idx - inL;
        root->left = build(pre, preL+1, preL+1+leftSize, in, inL, idx, idxMap);
        root->right = build(pre, preL+1+leftSize, preR, in, idx+1, inR, idxMap);
        return root;
    }
};
