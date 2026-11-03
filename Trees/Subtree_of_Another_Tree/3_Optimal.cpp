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
    string serialize(TreeNode* node) {
        if (!node) return "#,";
        return to_string(node->val) + "," + serialize(node->left) + serialize(node->right);
    }

    vector<int> buildLPS(const string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m; ) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }

    bool kmpSearch(const string& txt, const string& pat) {
        if (pat.empty()) return true;
        vector<int> lps = buildLPS(pat);
        int i = 0, j = 0;
        int n = txt.size(), m = pat.size();
        while (i < n) {
            if (txt[i] == pat[j]) {
                ++i; ++j;
                if (j == m) return true; // match found
            } else if (j) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string sRoot = serialize(root);
        string sSub = serialize(subRoot);
        return kmpSearch(sRoot, sSub);
    }
};
