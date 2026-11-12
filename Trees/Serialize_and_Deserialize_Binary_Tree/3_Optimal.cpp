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
    // Serialize with ostringstream (pre‑order, O(N))
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Deserialize using a stringstream to read tokens lazily (O(N) time, O(H) stack)
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }

private:
    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (!node) {
            out << "null,";
            return;
        }
        out << node->val << ",";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string token;
        if (!getline(ss, token, ',')) return nullptr; // safety
        if (token == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }
};

// Example usage:
// Codec codec;
// string s = codec.serialize(root);
// TreeNode* tree = codec.deserialize(s);
