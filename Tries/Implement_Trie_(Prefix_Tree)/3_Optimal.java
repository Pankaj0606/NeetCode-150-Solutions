import java.util.*;

class Trie {
    private static class Node {
        boolean isEnd = false;
        Node[] child = new Node[26];
    }
    private Node root;
    public Trie() {
        root = new Node();
    }
    public void insert(String word) {
        Node node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.child[idx] == null) node.child[idx] = new Node();
            node = node.child[idx];
        }
        node.isEnd = true;
    }
    public boolean search(String word) {
        Node node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.child[idx] == null) return false;
            node = node.child[idx];
        }
        return node.isEnd;
    }
    public boolean startsWith(String prefix) {
        Node node = root;
        for (char c : prefix.toCharArray()) {
            int idx = c - 'a';
            if (node.child[idx] == null) return false;
            node = node.child[idx];
        }
        return true;
    }
}
