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
    // Serialize using ostringstream (O(N) time)
    string serialize(TreeNode* root) {
        ostringstream out;
        buildString(root, out);
        return out.str();
    }

    // Deserialize – split once then rebuild recursively
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
        return buildTree(nodes, idx);
    }

private:
    void buildString(TreeNode* node, ostringstream& out) {
        if (!node) {
            out << "null,";
            return;
        }
        out << node->val << ",";
        buildString(node->left, out);
        buildString(node->right, out);
    }

    TreeNode* buildTree(const vector<string>& nodes, int& idx) {
        if (idx >= (int)nodes.size() || nodes[idx] == "null") {
            ++idx;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(nodes[idx++]));
        node->left = buildTree(nodes, idx);
        node->right = buildTree(nodes, idx);
        return node;
    }
};

// Usage example (LeetCode style):
// Codec codec;
// string s = codec.serialize(root);
// TreeNode* restored = codec.deserialize(s);
