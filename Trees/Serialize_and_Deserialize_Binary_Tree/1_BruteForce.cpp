#include <bits/stdc++.h>
using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Serialize using naive string concatenation (O(N^2) time)
    string serialize(TreeNode* root) {
        if (!root) return "null,"; // marker for nullptr
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Deserialize by splitting the string into a vector of tokens
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string token;
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(token);
                token.clear();
            } else {
                token.push_back(c);
            }
        }
        int idx = 0;
        return build(nodes, idx);
    }

private:
    TreeNode* build(const vector<string>& nodes, int& idx) {
        if (idx >= (int)nodes.size() || nodes[idx] == "null") {
            ++idx;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(nodes[idx++]));
        node->left = build(nodes, idx);
        node->right = build(nodes, idx);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// string s = codec.serialize(root);
// TreeNode* ans = codec.deserialize(s);
