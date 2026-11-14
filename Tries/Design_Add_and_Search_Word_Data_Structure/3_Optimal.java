import java.util.*;

public class WordDictionary {
    private static class TrieNode {
        boolean isEnd = false;
        TrieNode[] child = new TrieNode[26];
    }
    private final TrieNode root;
    public WordDictionary() {
        root = new TrieNode();
    }
    public void addWord(String word) {
        TrieNode node = root;
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if (node.child[idx] == null) node.child[idx] = new TrieNode();
            node = node.child[idx];
        }
        node.isEnd = true;
    }
    public boolean search(String word) {
        return dfs(word.toCharArray(), 0, root);
    }
    private boolean dfs(char[] arr, int pos, TrieNode node) {
        if (node == null) return false;
        if (pos == arr.length) return node.isEnd;
        char ch = arr[pos];
        if (ch == '.') {
            for (TrieNode child : node.child) {
                if (dfs(arr, pos + 1, child)) return true;
            }
            return false;
        } else {
            return dfs(arr, pos + 1, node.child[ch - 'a']);
        }
    }
}
